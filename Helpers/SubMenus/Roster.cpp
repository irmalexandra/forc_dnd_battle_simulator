#include "Roster.h"

void select_template_for_individual(FileHandler* file_handler, Payload* payload, IndividualCreator* individual_creator) {
    view_shortened_templates(payload);
    string name;
    cout << "Enter the name of the template you want to view." << endl;
    cin >> name;
    auto species_index = get_index_species(name, payload);
    auto role_index = get_index_roles(name, payload);
    while(role_index == -1 && species_index == -1) {
        cout << name << " does not exist!" << endl;
        view_shortened_templates(payload);
        cout << "Enter the name of the template you want to view." << endl;
        cin >> name;
        species_index = get_index_species(name, payload);
        role_index = get_index_roles(name, payload);
    }
    view_single_template(species_index, role_index, payload);

    cout << "1. Create Individual based on this template\n2. Back" << endl;
    int choice = 0;
    cin >> choice;
    if(cin.fail()){
        cout << "Invalid input, going back" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        return;
    }
    switch (choice) {
        case 1:
            if (species_index >= 0) {
                auto species = payload->DHSpecies->get_data()->at(species_index);
                if (species->get_is_eldritch()){
                    auto new_eldritch_horror = individual_creator->createEldritchHorror(species);
                    if(payload->species_map->find(new_eldritch_horror->get_template()->get_name()) == payload->species_map->end()){
                        payload->species_map->insert(std::pair<string, int>(new_eldritch_horror->get_template()->get_name(), 0));
                    }
                    new_eldritch_horror->set_name(new string(new_eldritch_horror->get_name() +
                                                             to_string(++payload->species_map->find(new_eldritch_horror->get_template()->get_name())->second)));

                    new_eldritch_horror->set_is_investigator(new bool(false));
                    payload->DHEldritchHorrors->get_data()->push_back(new_eldritch_horror);
                    cout << new_eldritch_horror << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    string original_name = new_eldritch_horror->get_name();
                    cin >> choice;
                    while(cin.fail()){
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<int>::max(),'\n');
                        cout << new_eldritch_horror << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                        cin >> choice;
                    }
                    if(choice == 1){
                        new_eldritch_horror->edit();
                        if(original_name != new_eldritch_horror->get_name()){
                            payload->species_map->find(new_eldritch_horror->get_template()->get_name())->second--;
                        }
                    }
                    auto_save(file_handler, payload);
                }
                else {
                    auto new_creature = individual_creator->createCreature(species);
                    new_creature->set_is_investigator(new bool(false));
                    if(payload->species_map->find(new_creature->get_template()->get_name()) == payload->species_map->end()){
                        payload->species_map->insert(std::pair<string, int>(new_creature->get_template()->get_name(), 0));
                    }
                    new_creature->set_name(new string(new_creature->get_name()
                                                      + to_string(++payload->species_map->find(new_creature->get_template()->get_name())->second)));
                    payload->DHCreatures->get_data()->push_back(new_creature);
                    cout << new_creature << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    string original_name = new_creature->get_name();
                    cin >> choice;
                    while(cin.fail()){
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<int>::max(),'\n');
                        cout << new_creature << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                        cin >> choice;
                    }
                    if(choice == 1){
                        new_creature->edit();
                        if(original_name != new_creature->get_name()){
                            payload->species_map->find(new_creature->get_template()->get_name())->second--;
                        }
                    }
                    auto_save(file_handler, payload);
                }

            } else if (role_index >= 0) {
                auto role = payload->DHRoles->get_data()->at(role_index);
                cout << "1. Investigator (playable character)\n2. Person (NPC)\n3. Return" << endl;
                bool runner = true;
                cin >> choice;
                while(cin.fail()){
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<int>::max(),'\n');
                    cout << "1. Investigator (playable character)\n2. Person (NPC)\n3. Return" << endl;
                    cin >> choice;
                }
                while(runner){
                    if (choice == 1){
                        auto new_investigator = individual_creator->createInvestigator(role);
                        new_investigator->set_is_investigator(new bool(true));
                        payload->DHInvestigators->get_data()->push_back(new_investigator);
                        cout << new_investigator << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                        cin >> choice;
                        while(cin.fail()){
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<int>::max(),'\n');
                            cout << new_investigator << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                            cin >> choice;
                        }
                        if(choice == 1){
                            new_investigator->edit();
                        }
                        runner = false;
                        auto_save(file_handler, payload);

                    }
                    else if (choice == 2){
                        auto new_person = individual_creator->createPerson(role);
                        new_person->set_is_investigator(new bool(false));
                        payload->DHPersons->get_data()->push_back(new_person);
                        cout << new_person << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                        cin >> choice;
                        while(cin.fail()){
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<int>::max(),'\n');
                            cout << new_person << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                            cin >> choice;
                        }
                        if(choice == 1){
                            new_person->edit();
                        }

                        runner = false;
                        auto_save(file_handler, payload);
                    }
                    else{
                        cout << choice << " is not a valid option" << endl;
                        cout << "1. Investigator (playable character)\n2. Person (NPC)\n3. Return" << endl;
                        cin >> choice;
                        while(cin.fail()){
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<int>::max(),'\n');
                            cout << "1. Investigator (playable character)\n2. Person (NPC)\n3. Return" << endl;
                            cin >> choice;
                        }
                    }
                }

            }
        case 2:
            return;
    }
}

void view_individuals_by_category(Payload* payload) {

    int choice;

    while(true){
        cout << "Select a character type" << std::endl;
        cout << "1. Investigator" << endl;
        cout << "2. Person (NPC)" << endl;
        cout << "3. Creature" << endl;
        cout << "4. Eldritch Horror" << endl;
        cout << "5. Back" << std::endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch(choice){
            case 1:
                cout << payload->DHInvestigators << endl;
                break;
            case 2:
                cout << payload->DHPersons << endl;
                break;
            case 3:
                cout << payload->DHCreatures << endl;
                break;
            case 4:
                cout << payload->DHEldritchHorrors << endl;
                break;
            case 5:
                return;
            default:
                cout<<"Error"<<endl;
                break;

        }
    }
}

void individual_menu(FileHandler* file_handler, Payload* payload, IndividualCreator* individual_creator) {
    int choice;
    while(true){
        cout << "1. View individuals\n2. Create individual\n3. Back" << endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case(1):
                view_individuals(payload);
                break;
            case(2):
                select_template_for_individual(file_handler, payload, individual_creator);
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
                break;
        }
    }
}

void view_shortened_individuals(Payload* payload){
    cout << "Individuals:" << endl << endl << "Persons(NPCs)" << endl;

    for(const auto individual: *payload->DHPersons->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Investigators:" << endl;
    for(const auto individual: *payload->DHInvestigators->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Creatures " << endl;
    for(const auto individual: *payload->DHCreatures->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Eldritch Horrors" << endl;
    for(const auto individual: *payload->DHEldritchHorrors->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
}

void view_all_individuals(Payload* payload) {
    cout << "Created individuals\n" << endl;
    cout << "Investigators:" << endl;
    cout << payload->DHInvestigators << endl;
    cout << "\nNPCs:" << endl;
    cout << payload->DHPersons << endl;
    cout << "\nCreatures:" << endl;
    cout << payload->DHCreatures << endl;
    cout << "\nEldritch Horrors" << endl;
    cout << payload->DHEldritchHorrors << endl;
}

void view_individuals(Payload* payload) {
    int choice;
    while(true){
        cout << "1. View all individuals\n2. View by category\n3. Back" << endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case(1):
                view_all_individuals(payload);
                break;
            case(2):
                view_individuals_by_category(payload);
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
                break;

        }
    }
}

void auto_save(FileHandler* file_handler, Payload* payload){
    cout << "Auto Saving..." << endl;
    file_handler->save_roster(payload, new string("Saves/backups/roster_backup.txt"));
}
