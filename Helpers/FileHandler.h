#ifndef FORC_PA_5_FILEHANDLER_H
#define FORC_PA_5_FILEHANDLER_H
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <map>

#include "../Templates/BaseTemplate.h"
#include "../Templates/Role.h"
#include "../Templates/Species.h"
#include "DataHandler.h"
#include "HelperFunctions.h"
#include "Structs.h"



using namespace std;

class FileHandler {
public:
    void load_templates(Payload* payload);
    void save_templates(Payload* payload);
    void load_roster(Payload* payload, string* roster_name);
    void save_roster(Payload* payload, string* roster_name);

};



#endif //FORC_PA_5_FILEHANDLER_H
