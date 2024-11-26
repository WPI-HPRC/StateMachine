#pragma once

#include "Condition.h"
#include "UtilityCommand.h"
#include <vector>

struct Transition;
struct State;

struct State {
  std::vector<Transition> transitions;
};

struct Transition {
  Condition *cond;
  std::vector<int> actuatorPushCmds;
  std::vector<int> actuatorPopCmds;
  std::vector<UtilityCommand *> utilityPushCmds;
  std::vector<int> utilityPopCmds;
  State *targetState;
};

/*

.condition = And(LessThan(get(key_1), val(100)), GreaterThan(get(key_2), val(1000)))

*/
