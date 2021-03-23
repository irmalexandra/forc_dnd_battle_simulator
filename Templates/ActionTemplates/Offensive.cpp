
#include "Offensive.h"


Offensive::Offensive(baseActionTemplateStats* stats, int* hit_modifier, int* damage): ActionBaseTemplate(stats) {
    this->damage = *damage;
    this->hit_modifier = *hit_modifier;

    delete damage;
    delete hit_modifier;

    damage = nullptr;
    hit_modifier = nullptr;
}

int Offensive::get_damage() {
    return this->damage;
}

int Offensive::get_hit_modifier() {
    return this->hit_modifier;
}

std::ostream& operator<< (std::ostream& out, Offensive* offensive) {
    out << (ActionBaseTemplate*)(offensive);
    out << "Hit Modifier: " << offensive->get_hit_modifier() << endl;
    out << "Damage: " << offensive->get_damage() << endl;
    return out;
}



