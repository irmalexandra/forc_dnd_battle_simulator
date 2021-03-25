#ifndef FORC_PA_5_BATTLEHANDLER_H
#define FORC_PA_5_BATTLEHANDLER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Helpers/Structs/Payload.h"
#include "../Models/Being.h"
#include "../Helpers/IndexFinder.h"
#include "../Helpers/HelperFunctions.h"

using namespace std;

class BattleHandler {
public:
    explicit BattleHandler(Payload* payload);
    void decrement_cooldowns();
    void increment_round();
    void increment_turn();
    void set_turn_order();
    void execute_ai_turn();
    void execute_player_turn();
    void execute_offensive_action(Offensive* action);
    void execute_defensive_action(Defensive* action);
    template <typename T> T* select_target();
    int dice_roll(int* max_value);
    void start();
    void set_status();
    string find_target();

private:
    int turn_tracker = 0;
    int turn_size;
    int round_tracker = 0;
    int monster_team_count = 0;
    int investigator_team_count = 0;
    vector<Being*>* participant_list;
    Payload* payload;

};

#endif //FORC_PA_5_BATTLEHANDLER_H
