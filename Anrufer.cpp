//
// Created by debian on 29.05.15.
//

#include "Anrufer.h"
#include "Callcenter.h"
#include <iostream>
#include <chrono>
#include <thread>

std::string Anrufer::getMyNumber() const{
    return "555-1234-56-" + std::to_string(myAnruferId);
}


void Anrufer::call() {

    while (!callcenter->hello(this)){
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 12 + 3));
    }
    std::cout << getMyNumber() << " in warteschlange" << std::endl;

}

unsigned int Anrufer::anruferCountId = 0;

void Anrufer::operator()() const {
    //std::cout << getMyNumber() << std::endl;

}

void Anrufer::startTalk() {
    std::this_thread::sleep_for(std::chrono::seconds(rand() % 12 + 3));

}
