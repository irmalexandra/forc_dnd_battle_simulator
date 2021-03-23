cmake_minimum_required(VERSION 3.17)
project(FORC_PA_5)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(FORC_PA_5 ../FORC-PA-5/main.cpp
        Models/Being.cpp
        Models/Being.h
        Models/Creature.cpp
        Models/Creature.h
        Models/Person.cpp
        Models/Person.h
        Models/Investigator.cpp
        Models/Investigator.h
        Models/EldritchHorror.cpp
        Models/EldritchHorror.h
        Classes/IndividualCreator.cpp
        Classes/IndividualCreator.h
        Helpers/InputHandler.cpp
        Helpers/InputHandler.h
        Helpers/FileHandler.cpp
        Helpers/FileHandler.h
        Helpers/DataHandler.h
        Helpers/HelperFunctions.h
        Helpers/HelperFunctions.cpp
        Classes/TemplateCreator.cpp
        Classes/TemplateCreator.h
        Templates/IndividualTemplates/BaseTemplate.cpp
        Templates/IndividualTemplates/BaseTemplate.h
        Templates/IndividualTemplates/Species.cpp
        Templates/IndividualTemplates/Species.h
        Templates/IndividualTemplates/Role.cpp
        Templates/IndividualTemplates/Role.h
        Helpers/SubMenus/Actions.cpp
        Helpers/SubMenus/Actions.h
        Helpers/SubMenus/Roster.cpp
        Helpers/SubMenus/Roster.h
        Helpers/SubMenus/Templates.cpp
        Helpers/SubMenus/Templates.h
        Helpers/Structs/Payload.h
        Helpers/Structs/Stats.h Helpers/Structs/Payload.cpp Helpers/Structs/Stats.cpp)