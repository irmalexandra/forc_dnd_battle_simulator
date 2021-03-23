#include "Templates.h"


void template_menu(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload) {
    int choice;
    while(true){
        cout << "1. View templates\n2. Create template\n3. Delete template\n4. Back" << endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case(1):
                view_templates(payload);
                break;
            case(2):
                edit_templates(file_handler, template_creator, payload);
                break;
            case 3:
                delete_template(file_handler, payload);
                break;
            case 4:
                return;
            default:
                cout << choice << " is not an option" << endl;
                break;
        }
    }
}

void create_template(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload) {
    int choice = 0;

    Species* species;
    Role* role;


    while(true){
        std::cout << "Select:" << std::endl;
        std::cout << "1. Species" << std::endl;
        std::cout << "2. Role" << std::endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case 1:
                species = template_creator->create_species();
                payload->DHSpecies->get_data()->push_back(species);
                file_handler->save_templates(payload);
                break;
            case 2:
                role = template_creator->create_role();
                payload->DHRoles->get_data()->push_back(role);
                file_handler->save_templates(payload);
                break;
            default:
                cout << "Invalid selection: " << choice << endl;
                break;

        }
        if(!re_prompt()){

            return;
        }
    }
}

void view_templates(Payload* payload) {
    cout << "Available Roles" << endl;
    cout << payload->DHRoles << endl;
    cout << "\nAvailable Species" << endl;
    cout << payload->DHSpecies << endl;
}

void view_single_template(int species_index, int role_index, Payload* payload){

    if(species_index != -1){
        cout << payload->DHSpecies->get_data()->at(species_index) << endl;
    }

    else if(role_index != -1){
        cout << payload->DHRoles->get_data()->at(role_index) << endl;
    }
}

void view_shortened_templates(Payload* payload){
    cout << "Available Roles:" << endl;
    for(const auto role: *payload->DHRoles->get_data()){
        cout << '\t' << role->get_name() << endl;
    }

    cout << "\nAvailable Species:" << endl;
    for(const auto species: *payload->DHSpecies->get_data()){
        cout << '\t' << species->get_name() << endl;
    }
}

void delete_template(FileHandler* file_handler, Payload* payload){
    string name;
    view_shortened_templates(payload);
    cout << "Enter the name of the template you want deleted." << endl;
    cin >> name;

    auto species_index = get_index_species(name, payload);
    auto role_index = get_index_roles(name, payload);
    if(role_index == -1 && species_index == -1){
        cout << name << " does not exist!" << endl;
    }
    else{
        if(species_index != -1){
            payload->DHSpecies->get_data()->erase(payload->DHSpecies->get_data()->begin() + species_index);
            file_handler->save_templates(payload);
        }

        if(role_index != -1){
            payload->DHRoles->get_data()->erase(payload->DHRoles->get_data()->begin() + role_index);
            file_handler->save_templates(payload);
        }
    }
}

void edit_templates(FileHandler* file_handler, TemplateCreator* template_creator, Payload* payload) {
    int choice;
    while(true){
        cout << "1. Create templates\n2. Delete template\n3. Back" << endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case(1):
                create_template(file_handler, template_creator, payload);
                break;
            case(2):
                delete_template(file_handler, payload);
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
                break;

        }
    }
}

int get_index_roles(const string& name, Payload* payload) {
    int index = -1;
    for (int i = 0; i < payload->DHRoles->get_data()->size(); i++){
        if(payload->DHRoles->get_data()->at(i)->get_name() == name){
            index = i;
            return index;
        }
    }
    return index;
}

int get_index_species(const string& name, Payload* payload) {
    int index = -1;
    for (int i = 0; i < payload->DHSpecies->get_data()->size(); i++){
        if(payload->DHSpecies->get_data()->at(i)->get_name() == name){
            index = i;
            return index;
        }
    }
    return index;
}
