//
// Created by emmik on 23/03/2021.
//

#ifndef FORC_PA_5_DEFENSIVE_H
#define FORC_PA_5_DEFENSIVE_H

#include "ActionBaseTemplate.h"

class Defensive : public ActionBaseTemplate {
public:
    Defensive() = default;
    //Defensive(baseActionTemplateStats* stats, int* modifier = 0, int* recovery = 0, int duration* = 0);


private:
    int defense_modifier;
    int health_recovery;
    int duration; // Number of turns

};


#endif //FORC_PA_5_DEFENSIVE_H
