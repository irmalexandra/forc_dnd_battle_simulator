#ifndef FORC_PA_5_SPECIES_H
#define FORC_PA_5_SPECIES_H

#include "BaseTemplate.h"
#include "iostream"




class Species: public BaseTemplate {
public:
    explicit Species() = default;
    explicit Species(speciesStats* species_stats);


    bool get_unnatural();
    Range get_disquiet_range();
    Range get_traumatism_range();
    bool get_is_eldritch();

    void set_unnatural(bool* unnatural);
    void set_disquiet_range(int* disquiet_min, int* disquiet_max);
    void set_traumatism_range(int* traumatism_min, int* traumatism_max);

    friend std::ostream& operator<< (std::ostream& out, Species* creature);

private:
    bool unnatural;
    int disquiet_min;
    int disquiet_max;
    bool is_eldritch_horror;
    int traumatism_min;
    int traumatism_max;
};

#endif //FORC_PA_5_SPECIES_H
