//
// Created by emmik on 23/03/2021.
//

#include "ActionCreator.h"

//
//Defensive* ActionCreator::create_defensive() {
//    int intelligence_defense_modifier;
//    int strength_defense_modifier;
//    int health_recovery;
//    int duration;
//
//    auto stats = get_base_stats();
//    int *damage = new int();
//    int* hit_modifier = new int();
//    cout << "How much damage should this action deal?" << endl;
//    *damage = get_int_within_range(1, 10, "Damage: ");
//    cout << "How much should the hit modifier be? (higher chance means more likely to hit)\nHit modifier: ";
//    *hit_modifier = get_int_within_range(0, 10, "Hit Modifier: ");
//    return new Defensive();
//}


Offensive* ActionCreator::create_offensive() {
    auto stats = get_base_stats();
    int *damage = new int();
    int* hit_modifier = new int();
    cout << "How much damage should this action deal?" << endl;
    *damage = get_int_within_range(1, 10, "Damage: ");
    cout << "How much should the hit modifier be? (higher chance means more likely to hit)\nHit modifier: ";
    *hit_modifier = get_int_within_range(0, 10, "Hit Modifier: ");
    return new Offensive(stats, hit_modifier, damage);
}


baseActionTemplateStats *ActionCreator::get_base_stats() {
    string name;
    cout << "What is the name of this action?\nName: ";
    cin >> name;
    auto stats = new baseActionTemplateStats();
    stats->name = name;
    cout << "Is this a physical attack?\n1. Yes\n2. No" << endl;
    cin >> name;
    if(name == "1"){
        stats->physical = true;
    }
    else{
        stats->physical = false;
    }
    return stats;
}
