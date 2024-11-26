#pragma once

#include "Condition.h"
#include "UtilityCommand.h"
#include <any>
#include <vector>

struct Transition;
struct State;

#define GENERATE_STATES()                                                      \
  struct State {                                                               \
    std::vector<Transition> transitions;                                       \
  };                                                                           \
                                                                               \
  struct Transition {                                                          \
    Condition cond;                                                            \
    std::vector<int> actuatorPushCmds;                                         \
    std::vector<int> actuatorPopCmds;                                          \
    std::vector<UtilityCommand> utilityPushCmds;                               \
    std::vector<int> utilityPopCmds;                                           \
    State *targetState;                                                        \
  };

