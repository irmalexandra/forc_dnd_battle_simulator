//
// Created by emmik on 22/03/2021.
//

#ifndef FORC_PA_5_FILEHANDLER_H
#define FORC_PA_5_FILEHANDLER_H
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

#include "../IndividualTemplates/BaseTemplate.h"
#include "../IndividualTemplates/Role.h"
#include "../IndividualTemplates/Species.h"
#include "../Helpers/HelperFunctions.h"
#include "DataHandler.h"
#include "Structs/Payload.h"

using namespace std;


class FileHandler {
public:
    void load_templates(Payload* payload);
    void save_templates(Payload* payload);
    void load_roster(Payload* payload, string* roster_name);
    void save_roster(Payload* payload, string* roster_name);
};




#endif //FORC_PA_5_FILEHANDLER_H
