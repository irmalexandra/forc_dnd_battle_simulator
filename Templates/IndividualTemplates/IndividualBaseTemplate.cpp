#include "IndividualBaseTemplate.h"
#include "iostream"

int LOWER_LIMIT = 0;
int UPPER_LIMIT = 10;

IndividualBaseTemplate::IndividualBaseTemplate(baseIndividualTemplateStats* base_stats){
    this->name = base_stats->name;
    this->type = base_stats->type;
    this->life_min = base_stats->life_min;
    this->life_max = base_stats->life_max;
    this->intelligence_min = base_stats->int_min;
    this->intelligence_max = base_stats->int_max;
    this->strength_min = base_stats->str_min;
    this->strength_max = base_stats->str_max;
    this->offensive_actions = new vector<Offensive*>;
    this->defensive_actions = new vector<Defensive*>;
}

std::string IndividualBaseTemplate::get_name() {
    return this->name;
}

Range IndividualBaseTemplate::get_life_range() {
    return Range(life_min, life_max);
}

Range IndividualBaseTemplate::get_intelligence_range() {
    return Range(intelligence_min, intelligence_max);
}

Range IndividualBaseTemplate::get_strength_range() {
    return Range(strength_min, strength_max);
}

void IndividualBaseTemplate::set_life_range(int* life_min, int* life_max) {
    this->life_min = *life_min;
    this->life_max = *life_max;
}

void IndividualBaseTemplate::set_intelligence_range(int* intelligence_min, int* intelligence_max) {
    this->intelligence_min = *intelligence_min;
    this->intelligence_max = *intelligence_max;
}

void IndividualBaseTemplate::set_strength_range(int* strength_min, int* strength_max) {
    this->strength_min = *strength_min;
    this->strength_max = *strength_max;
}

void IndividualBaseTemplate::set_name(std::string* name) {
    this->name = *name;
}

void IndividualBaseTemplate::set_type(std::string* type) {
    this->type = *type;
}

std::string IndividualBaseTemplate::get_type() {
    return this->type;
}

void IndividualBaseTemplate::add_offensive_action(Offensive* action){
    this->offensive_actions->push_back(action);
}

void IndividualBaseTemplate::add_defensive_action(Defensive* action){
    this->defensive_actions->push_back(action);
}

vector<Offensive*>* IndividualBaseTemplate::get_offensive_actions(){
    return this->offensive_actions;
}

vector<Defensive*>* IndividualBaseTemplate::get_defensive_actions(){
    return this->defensive_actions;
}

std::ostream& operator<< (std::ostream& out, IndividualBaseTemplate* BaseTemplate) {
    out << "Name: " << BaseTemplate->get_name() << std::endl;
    out << BaseTemplate->get_type() << std::endl;
    out << "Life: " << BaseTemplate->get_life_range() << std::endl;
    out << "Strength: " << BaseTemplate->get_strength_range() << std::endl;
    out << "Intelligence: " << BaseTemplate->get_intelligence_range() << std::endl;
    out << "Offensive actions:" << endl;
    for (int i = 0; i < BaseTemplate->offensive_actions->size()-1; i++){
        out << "\t" << BaseTemplate->offensive_actions->at(i)->get_name() << std::endl;
    }
    out << BaseTemplate->offensive_actions->back()->get_name() << endl;
    out << "Defensive actions:" << std::endl;
    for (int i = 0; i < BaseTemplate->defensive_actions->size()-1; i++){
        out << "\t" << BaseTemplate->defensive_actions->at(i)->get_name() << std::endl;
    }
    out << BaseTemplate->defensive_actions->back()->get_name() << endl;
    return out;
}


//string IndividualBaseTemplate::get_raw_info() {
////    std::stringstream string_stream;
//    string return_string;
//    return_string += "Name: " + get_name() +  '\n';
//    return_string += get_type() +  '\n';
//    return_string += "Life: " + to_string(get_life_range().min) + "-" + to_string(get_life_range().max) +  '\n';
//    return_string +=  "Strength: " + to_string(get_strength_range().min) + "-" + to_string(get_strength_range().max) +  '\n';
//    return_string +=  "Intelligence: " + to_string(get_intelligence_range().min) + "-" + to_string(get_intelligence_range().max) +  '\n';
//    return_string +=  "Offensive actions count: " + to_string(offensive_actions->size()) +  '\n';
//    for (int i = 0; i < offensive_actions->size()-1; i++){
//        return_string +=  offensive_actions->at(i)->get_name() +  '\n';
//    }
//    return_string +=  offensive_actions->back()->get_name() +  '\n';
//    return_string +=  "Defensive actions count: " + to_string(defensive_actions->size()) +  '\n';
//    for (int i = 0; i < defensive_actions->size()-1; i++){
//        return_string +=  defensive_actions->at(i)->get_name() +  '\n';
//    }
//    return_string +=  defensive_actions->back()->get_name() +  '\n';
//    return return_string;
//}



