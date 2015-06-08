//
// Created by debian on 29.05.15.
//

#ifndef CALLCENTER_ANRUFER_H
#define CALLCENTER_ANRUFER_H

#include <string>
#include <chrono>
#include <atomic>

class Callcenter;

class Anrufer {

private:
    static std::atomic<unsigned int> anruferCountId;

    std::string statusText;

//    Mitarbeiter* callingAgent;

    unsigned int myAnruferId;

    std::pair<int, std::chrono::time_point<std::chrono::system_clock>> state = {std::make_pair(-1, std::chrono::system_clock::now())};
    // 0 -> aufgelegt, 1 -> wahlwiederholung (seit 3s), 2 -> telefoniert mit Mitarbeiter 2 (seit 3s), 3 -> in Warteschlange (seit 2s)

private:
    Callcenter* callcenter;
    bool isTalking();
    // nummber

public:
    //auflegen
    void call();
    void operator()() const;

    ~Anrufer() {
        endCall();
    }

    void startTalk();
    void endCall();

    std::string getMyNumber() const;

    Anrufer(Callcenter* callcenter) {
        anruferCountId++;
        myAnruferId = anruferCountId.load(std::memory_order_relaxed);
        this->callcenter = callcenter;
    }

    const std::string getStatusText() const;

    void setStatusText(int state, std::chrono::time_point<std::chrono::system_clock> time);
};


#endif //CALLCENTER_ANRUFER_H
