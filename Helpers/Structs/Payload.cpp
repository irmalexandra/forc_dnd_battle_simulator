#include "Payload.h"

Payload::Payload(
        DataHandler<Investigator>* dh_investigators,
DataHandler<Person>* dh_persons,
        DataHandler<Creature>* dh_creatures,
DataHandler<EldritchHorror>* dh_eldritch_horrors,
        DataHandler<Species>* dh_species,
DataHandler<Role>* dh_roles, /*DataHandler<Action>* dh_actions,*/
        map<string, int>* species_map)

{
this->DHInvestigators = dh_investigators;
this->DHPersons = dh_persons;
this->DHCreatures = dh_creatures;
this->DHEldritchHorrors = dh_eldritch_horrors;
this->DHSpecies = dh_species;
this->DHRoles = dh_roles;
//this->DHActions = dh_actions
this->species_map = species_map;

}