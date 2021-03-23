//
// Created by emmik on 23/03/2021.
//


#ifndef FORC_PA_5_DEFENSIVE_H
#define FORC_PA_5_DEFENSIVE_H

#include "ActionBaseTemplate.h"

class Defensive {
public:
    Defensive();
private:
    int intelligence_defense_modifier;
    int strength_defense_modifier;
    int health_recovery;
    int duration; // Number of turns
};


#endif //FORC_PA_5_DEFENSIVE_H

