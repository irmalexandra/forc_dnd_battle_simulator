#ifndef FORC_PA_5_ACTIONCREATOR_H
#define FORC_PA_5_ACTIONCREATOR_H
#include "../Templates/ActionTemplates/Defensive.h"
#include "../Templates/ActionTemplates/Offensive.h"
#include "../Templates/ActionTemplates/ActionBaseTemplate.h"
#include "../Helpers/HelperFunctions.h"

using namespace std;

class ActionCreator {
public:
    ActionCreator() = default;
    ~ActionCreator() = default;


    Defensive* create_defensive();
    Offensive* create_offensive();

private:
    baseActionTemplateStats* get_base_stats();

};


#endif //FORC_PA_5_ACTIONCREATOR_H
