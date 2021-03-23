#ifndef FORC_PA_5_TEMPLATES_H
#define FORC_PA_5_TEMPLATES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "../../Classes/TemplateCreator.h"
#include "../../Templates/Role.h"
#include "../../Templates/Species.h"
#include "../FileHandler.h"
#include "../Structs/Payload.h"
#include "../HelperFunctions.h"

using namespace std;

void view_single_template(int species_index, int role_index, Payload* payload);
void template_menu(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload);
void create_template(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload);
void view_templates(Payload* payload);
void view_shortened_templates(Payload* payload);
void edit_templates(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload);
void delete_template(FileHandler* file_handler, Payload* payload);



#endif //FORC_PA_5_TEMPLATES_H
