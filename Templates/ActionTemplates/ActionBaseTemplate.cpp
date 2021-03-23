//
// Created by emmik on 23/03/2021.
//

#include "ActionBaseTemplate.h"

ActionBaseTemplate::ActionBaseTemplate(baseActionTemplateStats *stats) {
    this->action_name = stats->name;



    delete stats;
    stats = nullptr;
}


std::string ActionBaseTemplate::get_action_name() {
    return this->action_name;
}


std::ostream& operator<< (std::ostream& out, ActionBaseTemplate* actionBaseTemplate) {
    out << "Name: " << actionBaseTemplate->get_action_name() << std::endl;
    return out;
}


