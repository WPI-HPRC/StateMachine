#pragma once

#include <any>
#include <map>
#include <set>
#include <vector>

#include "../User_Code/ContextDefinitions.h"
#include "Fuckyou.h"

#undef KEY
#undef MAP
#define FIELD(typ, name) typ name;

#define CREATE_CONTEXT(sensor_data)                                           \
  struct Context {                                      \
    sensor_data(FIELD);                                                       \
    std::set<int> actuatorCmdPool;                                            \
    std::vector<UtilityCommands::UtilityCommand> utilityCmdPool;                                 \
                                                         \
  };                                                                          

CREATE_CONTEXT(SENSOR_DATA);

#undef KEY
#undef MAP
#define UTILITY_KEY(name) constexpr int name  ## Type = __COUNTER__;
#define UTILITY_MAP(name) {name ## Type, &UtilityCommands::name ## Function},

#define CREATE_UTILITY_COMMANDS(utility_commands)                             \
utility_commands(UTILITY_KEY);                                                \
static const std::map<int, void(*)(const UtilityCommands::UtilityCommand*)> UtilityCommandMap{              \
utility_commands(UTILITY_MAP)                                                 \
};

CREATE_UTILITY_COMMANDS(UTILITYCOMMANDS)


#define ACTUATOR_KEY(name) constexpr int name ## ID = __COUNTER__;
#define ACTUATOR_MAP(name) {name ## ID, &ActuatorCommands::name},

#define CREATE_ACTUATOR_COMMANDS(actuator_commands)                                      \
  actuator_commands(ACTUATOR_KEY);                                                       \
  static  std::map<const int, void(*)()> ActuatorCommandMap = {                          \
    actuator_commands(ACTUATOR_MAP)                                                      \
  };  

CREATE_ACTUATOR_COMMANDS(ACTUATORCOMMANDS)

