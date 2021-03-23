#ifndef FORC_PA_5_PAYLOAD_H
#define FORC_PA_5_PAYLOAD_H

#include <map>

#include "../../Models/Investigator.h"
#include "../../Models/Person.h"
#include "../../Models/Creature.h"
#include "../../Models/EldritchHorror.h"
#include "../../Templates/Species.h"
#include "../../Templates/Role.h"
#include "../DataHandler.h"

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
        this->DHEldritchHorrors = dh_eldritch_horrors;
        this->DHSpecies = dh_species;
        this->DHRoles = dh_roles;
        this->species_map = species_map;

    }

// ROSTER
    DataHandler<Investigator>* DHInvestigators;
    DataHandler<Person>* DHPersons;
    DataHandler<Creature>* DHCreatures;
    DataHandler<EldritchHorror>* DHEldritchHorrors;

    // Templates
    DataHandler<Species>* DHSpecies;
    DataHandler<Role>* DHRoles;

    // Species Map
    std::map<string, int>* species_map;
};


#endif //FORC_PA_5_PAYLOAD_H