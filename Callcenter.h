//
// Created by debian on 29.05.15.
//

#ifndef CALLCENTER_CALLCENTER_H
#define CALLCENTER_CALLCENTER_H

#include <vector>
#include "Mitarbeiter.h"

class Callcenter {


private:
    std::vector<Mitarbeiter> mitarbeiter;


public:
    void hire();
    void fire(Mitarbeiter);
    //view Table

};


#endif //CALLCENTER_CALLCENTER_H
