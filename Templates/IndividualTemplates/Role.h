//
// Created by emmik on 22/03/2021.
//

#ifndef FORC_PA_5_ROLE_H
#define FORC_PA_5_ROLE_H

#include "string"
#include "iostream"
#include "BaseTemplate.h"


class Role: public BaseTemplate {
public:
    Role(baseStats* base_stats);

    Range get_fear_range();
    Range get_terror_range();

    friend std::ostream& operator<< (std::ostream& out, Role* person);

private:
    int fear_min;
    int fear_max;
    int terror_min;
    int terror_max;
};


#endif //FORC_PA_5_ROLE_H
