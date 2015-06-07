//
// Created by debian on 29.05.15.
//

#include "Callcenter.h"
#include <sstream>
#include <string>
#include <mutex>
#include "Mitarbeiter.h"


void Callcenter::hire() {
    Mitarbeiter* agent = new Mitarbeiter(this);
    mitarbeiter.push_back(agent);
    /*std::thread t(&Mitarbeiter::working, agent);
    t.join();*/
}

std::string Callcenter::printInfo() {
    std::stringstream sstream;
    for (auto agent : mitarbeiter){
        sstream <<  agent->getName() << "\n";
    }
    return sstream.str();
}

bool Callcenter::hello(Anrufer *anrufer) {
    {
        std::unique_lock<std::mutex> lock(CallerMutex);
        if (queue.size() < queuesize){
            queue.push_back(anrufer);
            cond.notify_one();
            return 1;
        }
    }
    return 0;

//    std::unique_lock<std::mutex> lock(CallerMutex);
//    while (queuesize == queue.size()) { // voll
//        cond.wait(lock);
//        if (beendet) {
//            throw "put()-wait beendet";
//        }
//    }
//    queue.push_back(anrufer);
//    cond.notify_all();
}

Anrufer *Callcenter::getNextCall() {
    std::unique_lock<std::mutex> lock(CallerMutex);
    while (queue.empty()) {
        cond.wait(lock);
        if (beendet) {
            throw "get()-wait beendet";
        }
    }
    cond.notify_all();
    auto first = queue.front();
    queue.pop_front();
    return first;
}

void Callcenter::beenden() { // Alle waits zwangsläufig beenden
    beendet = true;
    cond.notify_all();
}