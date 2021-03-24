#include "FileHandler.h"

void FileHandler::load_templates(Payload* payload){

    char single_line[32] = {};
    string filename = "Resources/template_file.txt";
    cout << "Loading templates from " << filename << "..." << endl;
    speciesStats* stats;

    string name;
    string type;


    auto temp_string_array = new std::vector<std::string>;
    int amount;

    string line_str;
    ifstream fileIn (filename, ios::binary);

    fileIn.getline(single_line, 32);
    line_str = string(single_line);
    if (line_str == ""){
        cout << "File is empty, nothing was loaded." << endl;
        return;
    }
    amount = stoi(line_str);
    for(int i = 0; i < amount; i++){

        stats = new speciesStats();

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        name = split_string(line_str).at(1);
        stats->name = name.substr(0, name.length()-1);

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        type = line_str.substr(0, line_str.length()-1);
        stats->type = type;


        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        *temp_string_array = split_string(split_string(line_str).at(1), "-");
        stats->life_min = stoi(temp_string_array->at(0));
        stats->life_max = stoi(temp_string_array->at(1));

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        *temp_string_array = split_string(split_string(line_str).at(1), "-");
        stats->str_min = stoi(temp_string_array->at(0));
        stats->str_max = stoi(temp_string_array->at(1));

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        *temp_string_array = split_string(split_string(line_str).at(1), "-");
        stats->int_min = stoi(temp_string_array->at(0));
        stats->int_max = stoi(temp_string_array->at(1));

        if(type != "Person"){
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            if(type.substr(0, type.length()-1) == "Natural"){
                stats->unnatural = false;
            }
            else{
                stats->unnatural = true;
            }
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(split_string(line_str).at(1), "-");

            stats->dis_min = stoi(temp_string_array->at(0));
            stats->dis_max = stoi(temp_string_array->at(1));
            if(type == ("Eldritch Horror")){

                fileIn.getline(single_line, 32);
                line_str = string(single_line);
                *temp_string_array = split_string(split_string(line_str).at(1), "-");
                stats->trauma_min = stoi(temp_string_array->at(0));
                stats->trauma_max = stoi(temp_string_array->at(1));
                stats->is_eldritch = true;
            }
        }
        if (type == "Person"){
            payload->DHRoles->get_data()->push_back(new Role(stats));
        } else if (type == "Eldritch Horror" || type == "Creature") {
            payload->DHSpecies->get_data()->push_back(new Species(stats));
        }
        fileIn.getline(single_line, 32); // To skip empty lines
        delete stats;
    }

    cout << "Done!" << endl;
}

void FileHandler::save_templates(Payload* payload) {
    string filename = "Resources/template_file.txt";
    cout << "Saving templates to " << filename << "..." << endl;
    ofstream fileout(filename, ios::trunc);
    int amount = 0;
    amount += payload->DHRoles->get_data()->size();
    amount += payload->DHSpecies->get_data()->size();

    fileout << amount << endl;
    fileout << payload->DHSpecies;
    fileout << payload->DHRoles;
    fileout.close();
    cout << "Done!" << endl;
}

void FileHandler::save_roster(Payload* payload, string* roster_name){
    cout << "Saving roster to " << *roster_name << "..." << endl;
    int amount = 0;
    amount += payload->DHInvestigators->get_data()->size();
    amount += payload->DHPersons->get_data()->size();
    amount += payload->DHCreatures->get_data()->size();
    amount += payload->DHEldritchHorrors->get_data()->size();
    ofstream fileout(*roster_name, ios::trunc);
    fileout << amount << endl;
    fileout << payload->DHInvestigators;
    fileout << payload->DHPersons;
    fileout << payload->DHCreatures;
    fileout << payload->DHEldritchHorrors;
    fileout.close();
    cout << "Done!" << endl;
}

void FileHandler::load_roster(Payload *payload, string *roster_name) {
    cout << "Loading roster from " << *roster_name << "..." << endl;
    char single_line[32] = {};
    payload->species_map->clear();
    ifstream fileIn (*roster_name, ios::binary);
    if(fileIn.fail()){
        cout << "File not found" << endl;
        return;
    }

    string line_string;
    string type;
    string template_name;

    fileIn.getline(single_line, 32);
    line_string = string(single_line);
    if (line_string == ""){
        cout << "File is empty, nothing was loaded." << endl;
        return;
    }
    int amount = stoi(line_string);

    for (int i = 0; i < amount; i++){
        fileIn.getline(single_line, 32);
        line_string = string(single_line);

        auto stats = new baseIndividualStats();

        while(line_string == "" || line_string == "\n" || line_string == "\r" || line_string == "\n\r" || line_string == "\r\n"){
            fileIn.getline(single_line, 32);
            line_string = string(single_line);
        }

        auto temp = split_string(line_string).at(1);
        stats->name = temp.substr(0, temp.length()-1);

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        type = line_string.substr(0, line_string.length()-1);
        stats->type = type;

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        template_name = line_string.substr(0, line_string.length()-1);

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        stats->life = stoi(split_string(line_string, " ").at(1));

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        stats->strength = stoi(split_string(line_string).at(1));

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        stats->intelligence = stoi(split_string(line_string).at(1));

        fileIn.getline(single_line, 32);
        line_string = string(single_line);
        if(type == "Creature" || type == "Eldritch Horror"){
            if(payload->species_map->find(template_name) == payload->species_map->end()){
                payload->species_map->insert(std::pair<string, int>(template_name, 1));
            }
            if(stats->name.substr(0, template_name.length())
               + to_string(payload->species_map->at(template_name)) == stats->name){
                payload->species_map->at(template_name)++;
            }

            Species* species = nullptr;
            auto species_list = payload->DHSpecies->get_data();
            for (int i = 0; i < payload->DHSpecies->get_data()->size(); i++){
                if (species_list->at(i)->get_name() == template_name){
                    species = species_list->at(i);
                }
            }

            stats->unnatural = (type != "Natural");
            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->disquiet = stoi(split_string(line_string).at(1));

            if (type == "Eldritch Horror"){
                fileIn.getline(single_line, 32);
                line_string = string(single_line);
                if (species != nullptr){
                stats->traumatism = stoi(split_string(line_string).at(1));
                payload->DHEldritchHorrors->get_data()->push_back(new EldritchHorror(stats, species));
                }
            }
            else if (species != nullptr){
                payload->DHCreatures->get_data()->push_back(new Creature(stats, species));
            }

        }
        else{
            stats->gender = split_string(line_string).at(1);
            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->fear = stoi(split_string(line_string).at(1));

            Role* role = nullptr;
            auto roles = payload->DHRoles->get_data();
            for (int i = 0; i < payload->DHRoles->get_data()->size(); i++){
                if (roles->at(i)->get_name() == template_name){
                    role = roles->at(i);
                }
            }

            if(type == "Person" && role != nullptr){
                if (role != nullptr){
                    payload->DHPersons->get_data()->push_back(new Person(stats, role));

                }
            }
            if(type == "Investigator"){
                fileIn.getline(single_line, 32);
                line_string = string(single_line);
                if (role != nullptr){
                    stats->terror = stoi(split_string(line_string).at(1));
                    payload->DHInvestigators->get_data()->push_back(new Investigator(stats, role));
                }
            }

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
        }
    }
    cout << "Done!" << endl;
}

void FileHandler::load_actions(Payload *payload) {

    char single_line[32] = {};
    string filename = "Resources/actions_file.txt";
    cout << "Loading actions from " << filename << "..." << endl;
    baseActionTemplateStats* stats;

    string name;
    string type;
    int* damage = new int();
    int* hit_modifier = new int();
    int* defense_modifier = new int();
    int* recovery = new int();
    int* duration = new int();

    auto temp_string_array = new std::vector<std::string>;
    int amount;

    string line_str;
    ifstream fileIn (filename, ios::binary);

    fileIn.getline(single_line, 32);
    line_str = string(single_line);
    if (line_str == ""){
        cout << "File is empty, nothing was loaded." << endl;
        return;
    }
    amount = stoi(line_str);
    for(int i = 0; i < amount; i++){

        stats = new baseActionTemplateStats();

        while(line_str == ""){
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
        }

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        name = split_string(line_str).at(1);
        stats->name = name.substr(0, name.length()-1);

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        type = split_string(line_str).at(1);
        stats->type = type.substr(0, type.length()-1);

        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        stats->physical =  "Physical" == line_str.substr(0, line_str.length()-1);


        if(stats->type != "Defensive"){
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(line_str,":" );
            *hit_modifier = stoi(temp_string_array->at(1));

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(line_str,":" );
            *damage = stoi(temp_string_array->at(1));

        } else {
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(line_str,":" );
            *defense_modifier = stoi(temp_string_array->at(1));

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(line_str,":" );
            *recovery = stoi(temp_string_array->at(1));

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            *temp_string_array = split_string(line_str,":" );
            *duration = stoi(temp_string_array->at(1));
        }
        if (stats->type == "Offensive"){
            payload->DHOffensives->get_data()->push_back(new Offensive(stats, hit_modifier, damage));
        } else {
            payload->DHDefensives->get_data()->push_back(new Defensive(stats, defense_modifier, recovery, duration));
        }
        fileIn.getline(single_line, 32); // To skip empty lines
    }
    delete stats;
    delete damage;
    delete hit_modifier;
    cout << "Done!" << endl;
}

void FileHandler::save_actions(Payload *payload) {
    string filename = "Resources/actions_file.txt";
    cout << "Saving actions to " << filename << "..." << endl;
    ofstream fileout(filename, ios::trunc);
    int amount = 0;
    amount += payload->DHOffensives->get_data()->size();
    amount += payload->DHDefensives->get_data()->size();

    fileout << amount << endl;
    fileout << payload->DHOffensives;
    fileout << payload->DHDefensives;
    fileout.close();
    cout << "Done!" << endl;
}
