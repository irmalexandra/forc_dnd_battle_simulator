#ifndef FORC_PA_5_BATTLEHANDLER_H
#define FORC_PA_5_BATTLEHANDLER_H

#include <vector>
#include "../Helpers/Structs/Payload.h"
#include "../Models/Being.h"

class BattleHandler {
    void decrement_cooldowns();
    void set_turn_order();
    int dice_roll();


public:
    explicit BattleHandler(Payload* payload);

private:
    int turn_tracker = 0;
    int round_tracker = 0;
    vector<Being*>* participant_list;
};


#endif //FORC_PA_5_BATTLEHANDLER_H
