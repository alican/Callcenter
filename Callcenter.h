//
// Created by debian on 29.05.15.
//

#ifndef CALLCENTER_CALLCENTER_H
#define CALLCENTER_CALLCENTER_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Mitarbeiter.h"
#include "Anrufer.h"


namespace {
    std::mutex ausgabeMutex;
}

class Callcenter {


private:
    std::mutex mtx;
    std::mutex CallerMutex;
    std::condition_variable cond;

    bool beendet;
    unsigned int queuesize = 5;
    std::vector<Mitarbeiter*> mitarbeiter;
    std::deque<Anrufer*> queue;

    void beenden();


public:
    Callcenter(unsigned int agentsNumber) {
        for(int i = 0; i < agentsNumber; i++){
            hire();
        }
    }

    bool hello(Anrufer*); // 0 voll / 1 frei und in warteschlange

    void hire();
    void fire(unsigned int agentId);

    Anrufer* getNextCall();

    std::string printInfo();
    //view Table

};


#endif //CALLCENTER_CALLCENTER_H
