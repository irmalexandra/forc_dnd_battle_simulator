//
// Created by emmik on 22/03/2021.
//

#ifndef FORC_PA_5_BEING_H
#define FORC_PA_5_BEING_H


#include "iostream"
#include "../Templates/IndividualTemplates/IndividualBaseTemplate.h"

class Being {
public:

    Being(IndividualBaseTemplate* base_template);
    Being(baseIndividualStats* stats);
    Being(baseIndividualStats *stats, IndividualBaseTemplate* base_template);

//    ~Being();

    void edit();

    int get_life();
    int get_strength();
    int get_intelligence();
    std::string get_name();
    bool get_is_investigator();

    void set_name(std::string* name);
    void set_life(int* life);
    void set_strength(int* strength);
    void set_intelligence(int* intelligence);
    void set_is_investigator(bool* is_investigator);


    IndividualBaseTemplate* get_template();


    friend std::ostream& operator<< (std::ostream& out, Being* being);

protected:
    std::string name;

private:
    int life;
    int strength;
    int intelligence;
    bool is_investigator;


    IndividualBaseTemplate* base_template;

};



#endif //FORC_PA_5_BEING_H
