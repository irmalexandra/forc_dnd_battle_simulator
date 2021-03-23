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


    friend std::ostream& operator<< (std::ostream& out, ActionBaseTemplate* actionBaseTemplate);
    std::string get_action_name();
    std::string get_type();

protected:
    std::string type;
    bool physical;

private:
    std::string action_name;
};


#endif //FORC_PA_5_ACTIONBASETEMPLATE_H
