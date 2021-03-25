#include "BattleHandler.h"


BattleHandler::BattleHandler(Payload* payload) {
    this->payload = payload;
    cout << "Launching battle simulator." << endl;
    cout << "Rolling initiative." << endl;
    this->participant_list = new vector<Being*>;
    for (auto & creature : *payload->DHCreatures->get_data()){
        creature->roll_initiative();
        this->participant_list->push_back((Being*)creature);
        this->monster_team_count++;
    }
    for (auto & investigator : *payload->DHInvestigators->get_data()){
        investigator->roll_initiative();
        this->participant_list->push_back((Being*)investigator);
        this->investigator_team_count++;
    }
    for (auto & person : *payload->DHPersons->get_data()){
        person->roll_initiative();
        this->participant_list->push_back((Being*)person);
        this->investigator_team_count++;
    }
    for (auto & horror : *payload->DHEldritchHorrors->get_data()){
        horror->roll_initiative();
        this->participant_list->push_back((Being*)horror);
        this->monster_team_count++;
    }
    set_turn_order();
    cout << "Turn order established." << endl;
    this->turn_size = this->participant_list->size();
}

bool compare (Being* lb, Being* rb){
    return lb->get_initiative() > rb->get_initiative();
}

void BattleHandler::set_turn_order() {
    sort(this->participant_list->begin(), this->participant_list->end(), compare);
}

void BattleHandler::increment_round() {
    this->round_tracker += 1;
}

void BattleHandler::increment_turn() {
    this->turn_tracker += 1;
}

void BattleHandler::start() {
    while (this->round_tracker < 3/*monster_team_count > 0 && investigator_team_count > 0*/){
        while (this->turn_tracker < this->turn_size){
            set_status();
            if(this->participant_list->at(this->turn_tracker)->get_is_investigator()){
                execute_ai_turn();
            } else {
                execute_ai_turn();
            }
            this->turn_tracker++;
        }
        this->decrement_cooldowns();
        this->turn_tracker = 0;
        this->round_tracker++;
    }
}

string BattleHandler::find_target() {
    auto targets = new vector<string>;
    for(auto target : *this->participant_list){
        if(!target->get_status()->dead){
            targets->push_back(target->get_name());
            if(target->get_status()->injured){
                targets->push_back(target->get_name());
            }
            if(target->get_status()->insane){
                targets->push_back(target->get_name());
            }
        }
    }
    auto random = get_random_integer(Range(0, targets->size()));
    return targets->at(random);
}

void BattleHandler::execute_ai_turn() {
    bool use_offensive;
    bool use_defensive;
    auto action_choice_names = new vector<string>;
    auto target_choice_names = new vector<string>;


    auto participant = this->participant_list->at(this->turn_tracker);
    if(participant->get_status()->dead) {
        cout << participant->get_name() << " is dead! Dead you hear me! DEAD!!" << endl;
        return;
    }
    cout << participant->get_name() << " is up!" << endl;

}

void BattleHandler::execute_player_turn() {

    auto participant = this->participant_list->at(this->turn_tracker);
    cout << participant->get_name() << " is up!" << endl;
}

void BattleHandler::set_status() {
    for (auto participant : *this->participant_list){

        // Checking if participant is dead, if true, ignores rest of status checks
        if(participant->get_current_life() <= 0){
            participant->get_status()->set_dead(true);
            continue;
        }

        //  Checking if participant is injured
        auto type = participant->get_template()->get_type();

        if(participant->get_current_life() <= participant->get_life()/2){
            participant->get_status()->set_injured(true);
        }else{
            participant->get_status()->set_injured(false);
        }

        if(type == "Person" || type == "Investigator"){
            auto person = (Person*) participant;
            if(person->get_current_fear() >= person->get_fear()/2){
                person->get_status()->set_frightened(true);
            }else{
                person->get_status()->set_frightened(false);
            }
            if(person->get_current_fear() >= person->get_fear()){
                person->get_status()->set_insane(true);
            }
            else{
                person->get_status()->set_insane(false);
            }
        }

        // Checking if participant feels outnumbered
        if(type == "Person" || type == "Investigator"){
            if(float((((float)this->monster_team_count / (float)this->investigator_team_count) - 1)) > 0.3){
                participant->get_status()->set_outnumbered(true);
            }
            else{
                participant->get_status()->set_outnumbered(false);
            }
        }
        else{
            if(float((((float)this->investigator_team_count / (float)this->monster_team_count) - 1)) > 0.3){
                participant->get_status()->set_outnumbered(true);
            }
            else{
                participant->get_status()->set_outnumbered(false);
            }
        }


        if(participant->get_is_investigator()){
            // TODO something clever for investigators only?
        }else{
            // TODO something else clever for investigators only?
        }


    }
}

template <typename T> T* BattleHandler::select_target() {
    string name;
    int index;
    cout << "Enter the name of your target: ";
    cin >> name;
    index = get_index(this->participant_list, name);

    while (index != -1){
        cout << "\nTarget not found" << endl << "Enter the name of your target: ";
        cin >> name;
        index = get_index(this->participant_list, name);
    }
    return this->participant_list->at(index);
}

void BattleHandler::decrement_cooldowns() {
    for (auto participant : *this->participant_list){
        for (auto action : *participant->get_template()->get_offensive_actions()){
            action->decrement_cooldown_remaining();
        }
        for (auto action : *participant->get_template()->get_defensive_actions()){
            action->decrement_cooldown_remaining();
        }
    }
}

void BattleHandler::execute_offensive_action(Offensive* action) {

}

void BattleHandler::execute_defensive_action(Defensive* action) {

}

