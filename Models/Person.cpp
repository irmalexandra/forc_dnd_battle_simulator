//
// Created by emmik on 22/03/2021.
//

#include "Person.h"

using namespace std;

Person::Person(std::string* name, std::string* gender, Role* role_template): Being(role_template){
    this->name = *name;
    this->gender = *gender;
    this->role = role_template->get_name();
    this->fear = get_random_integer(role_template->get_fear_range());
    this->current_fear = 0;
    this->role_template = role_template;
    delete name;
    name = nullptr;

    delete gender;
    gender = nullptr;
}

Person::Person(baseIndividualStats *stats, Role* base_template): Being(stats, (IndividualBaseTemplate*) base_template) {

    this->name = stats->name;
    this->gender = stats->gender;
    this->role = base_template->get_name();
    this->fear = stats->fear;
    this->current_fear = 0;
    this->role_template = base_template;
    this->set_battle_stats(stats);
}

void Person::set_battle_stats(baseIndividualStats* stats){
    this->battle_stats->life = stats->life;
    this->battle_stats->strength = stats->strength;
    this->battle_stats->intelligence = stats->intelligence;
    this->battle_stats->fear = stats->fear;
}

std::string Person::get_role() {
    return this->role;
}

Role* Person::get_role_template() {
    return this->role_template;
}
void Person::set_role(std::string *role) {
    this->role = *role;

    delete role;
    role = nullptr;
}

std::string Person::get_gender() {
    return this->gender;
}

void Person::set_gender(std::string *gender) {
    this->gender = *gender;

    delete gender;
    gender = nullptr;
}

int Person::get_fear() {
    return this->fear;
}

void Person::set_fear(int *fear) {
    this->fear = *fear;

    delete fear;
    fear = nullptr;
}

std::ostream& operator<< (std::ostream& out, Person* person) {
    out << (Being*)(person);
    out << "Gender: " << person->get_gender() << std::endl;
    out << "Fear: " << person->get_fear() << std::endl;
    return out;
}

void Person::edit(vector<Person*>* existing_persons) {
    enum Stats { Name = 1, Life = 2, Strength = 3, Intelligence = 4, Role = 5, Gender = 6, Fear = 7, Back = 8};
    int choice = 0;
    auto new_int_value = new int(0);
    int temp_val = 0;
    std::string* new_name;
    std::string* new_gender;
    while (true){
        std::cout << "Pick a stat to edit" << std::endl;
        std::cout << "1. Name" << std:: endl;
        std::cout << "2. Life" << std:: endl;
        std::cout << "3. Strength" << std:: endl;
        std::cout << "4. Intelligence" << std:: endl;
        std::cout << "5. Role" << std:: endl;
        std::cout << "6. Gender" << std:: endl;
        std::cout << "7. Fear" << std:: endl;
        std::cout << "8. Back" << std:: endl;
        std::cin >> choice;
        switch(choice){
            case Name:
                new_name = new std::string("");
                std::cout << "Enter new name: ";
                std::cin >> *new_name;
                while(get_index(existing_persons, *new_name) != -1){
                    cout << "Name already taken, choose a different name." << endl;
                    cin >> *new_name;
                }
                this->set_name(new_name);
                break;
            case Life:
                temp_val = get_int_within_range(
                        this->get_role_template()->get_life_range().min
                        , this->get_role_template()->get_life_range().max
                        ,"Enter a new value for Life"
                );
                new_int_value = &temp_val;
                this->set_life(new_int_value);
                break;
            case Strength:
                temp_val = get_int_within_range(
                        this->get_role_template()->get_strength_range().min,
                        this->get_role_template()->get_strength_range().max,
                        "Enter a new value for Strength"
                );
                new_int_value = &temp_val;
                this->set_strength(new_int_value);
                break;
            case Intelligence:

                temp_val = get_int_within_range(
                        this->get_role_template()->get_intelligence_range().min
                        , this->get_role_template()->get_intelligence_range().max
                        ,"Enter a new value for Intelligence"
                );
                new_int_value = &temp_val;
                this->set_intelligence(new_int_value);
                break;
            case Role:
                cout << "Some cool role picker yes plz" << endl;
                break;
            case Gender:
                this->set_gender(gender_picker());
                break;
            case Fear:
                temp_val = get_int_within_range(
                        this->get_role_template()->get_fear_range().min
                        , this->get_role_template()->get_fear_range().max
                        ,"Enter a new value for Fear"
                );
                new_int_value = &temp_val;
                this->set_fear(new_int_value);
                break;
            case Back:
                return;
        }
    }
}

string Person::get_state() {
    if(this->get_life() > this->get_role_template()->get_life_range().max/2){
        return "Injured";
    }
    return "Default";
}

int Person::get_current_fear() {
    return this->current_fear;
}

void Person::decrease_fear(int amount) {
    this->current_fear -= amount;
    if (this->current_fear < 0){
        this->current_fear = 0;
    }
}

void Person::increase_fear(int amount) {
    this->current_fear += amount;
    if (this->current_fear > this->fear){
        this->current_fear = this->fear;
    }
}

