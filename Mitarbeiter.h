//
// Created by debian on 29.05.15.
//

#ifndef CALLCENTER_MITARBEITER_H
#define CALLCENTER_MITARBEITER_H


#include <string>
#include <mutex>
#include <thread>
#include "Anrufer.h"



class Mitarbeiter {

private:
    static unsigned int agentCountId;
    bool isEmployed = true;
    unsigned int myAgentId;
    Callcenter* myCallcenter;
    static std::mutex CallerMutex;
    std::thread workingThread;

public:
    void operator()() const;

    std::string getName() const;

    void callStarted();
    void callFinished();
    void working();

    bool isBusy();

    Mitarbeiter(Callcenter* callcenter) : workingThread(&Mitarbeiter::working, this)  {
        myAgentId = agentCountId++;
        myCallcenter = callcenter;

    }

    virtual ~Mitarbeiter() { }
};


#endif //CALLCENTER_MITARBEITER_H
