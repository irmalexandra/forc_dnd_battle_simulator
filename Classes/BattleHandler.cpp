#include "BattleHandler.h"


BattleHandler::BattleHandler(Payload* payload) {
    auto investigators = payload->DHInvestigators->get_data();
    auto investigator = investigators->at(0);

    auto investaBeing = (Being*)investigator;

    auto beingToInvestigator = (Investigator*) investaBeing;

    cout << "stuff";
}