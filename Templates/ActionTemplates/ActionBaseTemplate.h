//
// Created by emmik on 23/03/2021.
//

#ifndef FORC_PA_5_ACTIONBASETEMPLATE_H
#define FORC_PA_5_ACTIONBASETEMPLATE_H

#include "string"
#include "../../Helpers/Structs/Stats.h"


class ActionBaseTemplate {

public:
    explicit ActionBaseTemplate(baseActionTemplateStats* stats);


private:
    std::string action_name;
    std::string description;
};


#endif //FORC_PA_5_ACTIONBASETEMPLATE_H
