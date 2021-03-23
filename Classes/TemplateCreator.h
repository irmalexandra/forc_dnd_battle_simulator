#ifndef FORC_PA_5_TEMPLATECREATOR_H
#define FORC_PA_5_TEMPLATECREATOR_H

#include <sstream>
#include "limits"
#include "iostream"
#include "istream"
#include "../Templates/IndividualTemplates/Role.h"
#include "../Templates/IndividualTemplates/Species.h"
#include "../Templates/IndividualTemplates/BaseTemplate.h"
#include "../Helpers/HelperFunctions.h"

using namespace std;

class TemplateCreator {
public:
    TemplateCreator() = default;
    ~TemplateCreator() = default;

    Role* create_role();
    Species* create_species();

private:
    void get_base_stats(baseStats* base_stats = nullptr);
    speciesStats* get_species_stats();
};


#endif //FORC_PA_5_TEMPLATECREATOR_H
