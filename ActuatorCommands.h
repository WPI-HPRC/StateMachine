#pragma once
#include "ActuatorCommands.cpp"
#include "Context.h"
#include <map>

#undef KEY
#undef MAP
#define KEY(name) constexpr int name  ## ID = __COUNTER__;
#define MAP(name) {name ## ID, & ## name},

#define CREATE_ACTUATOR_COMMANDS(actuator_commands)                            \
  actuator_commands(KEY);                                                      \
  static  std::map<const int, void(*)()> ActuatorCommandMap = {                \
    actuator_commands(MAP)                                                     \
  };

#define ACTUATORCOMMANDS(Y)     \
  Y(expelSolids)                \
  Y(openSolenoids)              \
  Y(closeSolenoids)             \
  Y(openSolidsDoor)   


CREATE_ACTUATOR_COMMANDS(ACTUATORCOMMANDS)

                                                              
