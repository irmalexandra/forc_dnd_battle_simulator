cmake_minimum_required(VERSION 3.17)
project(FORC_PA_5)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../FORC-PA-5)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(FORC_PA_5 ../FORC-PA-5/main.cpp
        ../FORC-PA-5/Models/Being.cpp
        ../FORC-PA-5/Models/Being.h
        ../FORC-PA-5/Models/Creature.cpp
        ../FORC-PA-5/Models/Creature.h
        ../FORC-PA-5/Models/Person.cpp
        ../FORC-PA-5/Models/Person.h
        ../FORC-PA-5/Models/Investigator.cpp
        ../FORC-PA-5/Models/Investigator.h
        ../FORC-PA-5/Models/EldritchHorror.cpp
        ../FORC-PA-5/Models/EldritchHorror.h
        ../FORC-PA-5/Classes/IndividualCreator.cpp
        ../FORC-PA-5/Classes/IndividualCreator.h
        ../FORC-PA-5/Helpers/InputHandler.cpp
        ../FORC-PA-5/Helpers/InputHandler.h
        ../FORC-PA-5/Helpers/FileHandler.cpp
        ../FORC-PA-5/Helpers/FileHandler.h
        ../FORC-PA-5/Helpers/HelperFunctions.cpp
        ../FORC-PA-5/Helpers/HelperFunctions.h
        ../FORC-PA-5/Helpers/DataHandler.h
        ../FORC-PA-5/Classes/TemplateCreator.cpp
        ../FORC-PA-5/Classes/TemplateCreator.h
        ../FORC-PA-5/Templates/BaseTemplate.cpp
        ../FORC-PA-5/Templates/BaseTemplate.h
        ../FORC-PA-5/Templates/Species.cpp
        ../FORC-PA-5/Templates/Species.h
        ../FORC-PA-5/Templates/Role.cpp
        ../FORC-PA-5/Templates/Role.h
        )