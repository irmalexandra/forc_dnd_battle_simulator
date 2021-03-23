#include "Defensive.h"

Defensive::Defensive(baseActionTemplateStats* stats, int* modifier, int* recovery, int* duration): ActionBaseTemplate(stats){
    this->defense_modifier = *modifier;
    this->health_recovery = *recovery;
    this->duration = *duration;
}

int Defensive::get_def_modifier(){
    return this->defense_modifier;
}
int Defensive::get_recovery(){
    return this->health_recovery;
}
int Defensive::get_duration(){
    return this->duration;
}

std::ostream& operator<< (std::ostream& out, Defensive* defensive) {
    out << (ActionBaseTemplate*)(defensive);
    if (defensive->physical) {
        out << "Physical" << endl;
    }
    else {
        out << "Mental" << endl;
    }
    out << "Defense Modifier: " << defensive->get_def_modifier() << endl;
    out << "Health Recovery: " << defensive->get_recovery() << endl;
    out << "Duration: " << defensive->get_duration() << endl;

    return out;
}