
#ifndef FORC_PA_5_STRUCTS_H
#define FORC_PA_5_STRUCTS_H

struct baseStats {
    std::string name = "";
    std::string type= "unchanged from base_Stats";
    int life_min = 0;
    int life_max = 0;
    int str_min = 0;
    int str_max = 0;
    int int_min = 0;
    int int_max = 0;
};

struct baseIndividualStats{
    std::string name = "";
    std::string type = "unchanged from base_Stats";
    std::string gender = "";
    int life = 0;
    int strength= 0;
    int intelligence= 0;
    bool unnatural = false;
    int disquiet = 0;
    int fear = 0;
    int traumatism = 0;
    int terror = 0;

};

struct speciesStats : public baseStats {
    bool is_eldritch = false;

    bool unnatural = 0;
    int dis_min = 0;
    int dis_max = 0;
    int trauma_min = 0 ;
    int trauma_max = 0;
};

struct Range {
    Range(){
    }

    Range(int min, int max){
        this->min = min;
        this->max = max;
    };

    friend std::ostream& operator<< (std::ostream& out, Range range){
        out << range.min << "-" << range.max;
        return out;
    };

    int min = 0;
    int max = 0;
};

struct Payload {
    Payload(
            DataHandler<Investigator>* dh_investigators,
            DataHandler<Person>* dh_persons,
            DataHandler<Creature>* dh_creatures,
            DataHandler<EldritchHorror>* dh_eldritch_horrors,
            DataHandler<Species>* dh_species,
            DataHandler<Role>* dh_roles,
            map<string, int>* species_map)

    {
        this->DHInvestigators = dh_investigators;
        this->DHPersons = dh_persons;
        this->DHCreatures = dh_creatures;
        this->DHEldritch_Horrors = dh_eldritch_horrors;
        this->DHSpecies = dh_species;
        this->DHRoles = dh_roles;
        this->species_map = species_map;
    }

public:
    // ROSTER
    DataHandler<Investigator>* DHInvestigators;
    DataHandler<Person>* DHPersons;
    DataHandler<Creature>* DHCreatures;
    DataHandler<EldritchHorror>* DHEldritch_Horrors;

    // Templates
    DataHandler<Species>* DHSpecies;
    DataHandler<Role>* DHRoles;

    // Species Map
    map<string, int>* species_map;
};


#endif //FORC_PA_5_STRUCTS_H
