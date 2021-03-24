#include "ActionCreator.h"


Defensive* ActionCreator::create_defensive() {
    auto stats = get_base_stats();
    stats->type = "Defensive";
    int* defense_modifier = new int();
    int* health_recovery = new int();
    int* duration = new int(1);

    cout << "Enter a value for the defense modifier (enter 0 if this is a recovery action)" << endl;
    *defense_modifier = get_int_within_range(0, 10, "Def modifier: ");
    cout << "Enter a value for the health recovery (enter 0 if this is not a recovery action)";
    *health_recovery = get_int_within_range(0, 10, "Recovery: ");
    cout << "Enter a value for how many turns this action applies (default value is 1)";
    *duration = get_int_within_range(0, 5, "Duration: ");
    return new Defensive(stats, defense_modifier, health_recovery, duration);
}


Offensive* ActionCreator::create_offensive() {
    auto stats = get_base_stats();
    stats->type = "Offensive";
    int* damage = new int();
    int* hit_modifier = new int();
    cout << "Enter a value for how much damage this action will cause" << endl;
    *damage = get_int_within_range(1, 10, "Damage: ");
    cout << "Enter a value for the hit modifier (higher chance means more likely to hit)" << endl;
    *hit_modifier = get_int_within_range(0, 10, "Hit Modifier: ");
    return new Offensive(stats, hit_modifier, damage);
}


baseActionTemplateStats *ActionCreator::get_base_stats() {
    string name;
    string is_physical;
    cout << "What is the name of this action?\nName: ";
    cin >> name;
    auto stats = new baseActionTemplateStats();
    stats->name = name;
    stats->cooldown = get_int_within_range(1, 5, "How long is the cool down for this action?");
    cout << "Is this a physical action (No would imply that it is a mental action)?\n1. Yes\n2. No" << endl;
    cin >> is_physical;
    if(is_physical == "1"){
        stats->physical = true;
    }
    else{
        stats->physical = false;
    }
    return stats;
}
