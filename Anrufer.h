//
// Created by debian on 29.05.15.
//

#ifndef CALLCENTER_ANRUFER_H
#define CALLCENTER_ANRUFER_H

#include <string>

class Callcenter;

class Anrufer {

private:
    static unsigned int anruferCountId;

    unsigned int myAnruferId;
    Callcenter* callcenter;
    bool isTalking();
    // nummber

public:
    //auflegen
    void call();
    void operator()() const;

    void startTalk();
    void endCall();

    std::string getMyNumber() const;

    Anrufer(Callcenter* callcenter) {
        this->callcenter = callcenter;

        this->myAnruferId = anruferCountId++;
    }
};


#endif //CALLCENTER_ANRUFER_H
