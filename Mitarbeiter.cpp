//
// Created by debian on 29.05.15.
//

#include "Mitarbeiter.h"
#include "Callcenter.h"
#include <iostream>



std::string Mitarbeiter::getName() const {

    return "Mitarbeiter " + std::to_string(myAgentId);
}

std::atomic<unsigned int> Mitarbeiter::agentCountId (1);

void Mitarbeiter::operator()() const {
    std::cout << getName()  << std::endl;
}

void Mitarbeiter::working() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
        try {
            while (true) {
                Anrufer* anrufer = myCallcenter->getNextCall();
               // std::lock_guard<std::mutex> lock(ausgabeMutex);
                std::cout << "Mitarbeiter " << getName()  << " telefoniert mit "  << anrufer->getMyNumber() << std::endl;
                anrufer->startTalk();

            }
        } catch (...) {
            std::lock_guard<std::mutex> lock(ausgabeMutex);
            std::cout << "Mitarbeiter " << getName() << " beendet sich." << std::endl;
        }

}
