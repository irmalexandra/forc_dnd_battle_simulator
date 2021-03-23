//
// Created by emmik on 23/03/2021.
//

#include "ActionBaseTemplate.h"

ActionBaseTemplate::ActionBaseTemplate(baseActionTemplateStats *stats) {
    this->action_name = stats->name;
    this->description = stats->description;

    delete stats;
    stats = nullptr;
}

