//
// Created by emmik on 22/03/2021.
//

#ifndef FORC_PA_5_CREATURE_H
#define FORC_PA_5_CREATURE_H


#include "Being.h"
#include "iostream"
#include "../Templates/IndividualTemplates/Species.h"
#include "../Helpers/HelperFunctions.h"

using namespace std;

class Creature: public Being {
public:
    Creature(std::string* name, Species* species);
    Creature(baseIndividualStats* stats, Species* species);

    void edit();

    bool get_unnatural();
    int get_disquiet();

    void set_unnatural(bool* unnatural);
    void set_disquiet(int* disquiet);

    Species* get_template();

    friend std::ostream& operator<< (std::ostream& out, Creature* creature);

private:
    Species* species;
    bool unnatural;
    int disquiet;
};



#endif //FORC_PA_5_CREATURE_H
