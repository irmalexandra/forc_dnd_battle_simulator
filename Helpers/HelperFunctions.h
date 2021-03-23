#ifndef FORC_PA_5_HELPERFUNCTIONS_H
#define FORC_PA_5_HELPERFUNCTIONS_H

#include <random>
#include "vector"
#include "iostream"
#include "Structs/Stats.h"
using namespace std;


string clean_string(string* the_string);
string clean_string2(string* the_string);
int get_random_integer(const Range& range);
int get_int_within_range(int lower, int upper, const std::string& display_string);
string ultimate_cleaner_3000(string str);
std::string* gender_picker();
bool re_prompt();
//std::vector<std::string>* split_string(std::string string, char delim = ' ');

std::vector<std::string> split_string(string str, string token = " ");


//int get_index_roles(const string& name, Payload* payload);
//int get_index_species(const string& name, Payload* payload);
//



#endif //FORC_PA_5_HELPERFUNCTIONS_H
