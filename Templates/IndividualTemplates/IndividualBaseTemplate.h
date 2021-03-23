//
// Created by emmik on 22/03/2021.
//

#ifndef FORC_PA_5_ACTIONBASETEMPLATE_H
#define FORC_PA_5_ACTIONBASETEMPLATE_H


#include "iostream"
#include "../../Helpers/Structs/Stats.h"

class ActionBaseTemplate {
public:
    ActionBaseTemplate(baseIndividualTemplateStats* baseStats);
//    ~BaseTemplate();

    std::string get_name();
    std::string get_type();

    Range get_life_range();
    Range get_strength_range();
    Range get_intelligence_range();

    void set_life_range(int* life_min, int* life_max);
    void set_strength_range(int* strength_min, int* strength_max);
    void set_intelligence_range(int* intelligence_min, int* intelligence_max);
    void set_name(std::string* name);
    void set_type(std::string* type);

    friend std::ostream& operator<< (std::ostream& out, ActionBaseTemplate* BaseTemplate);
private:
    std::string name;
    std::string type = "unchanged from Base_template";
    int life_min;
    int strength_min;
    int intelligence_min;
    int life_max;
    int strength_max;
    int intelligence_max;
};
#endif //FORC_PA_5_ACTIONBASETEMPLATE_H
