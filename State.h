#pragma once

#include "UtilityCommand.h"
#include <functional>
#include <vector>

template <typename SensorData>
struct BaseTransition;
template <typename SensorData>
struct BaseState;

template <typename SensorData>
struct BaseState {
  std::vector<BaseTransition<SensorData>> transitions;
};

template <typename SensorData>
struct BaseTransition {
  std::function<bool(Ctx<SensorData>)> cond;
  std::vector<int> actuatorPushCmds;
  std::vector<int> actuatorPopCmds;
  std::vector<UtilityCommand> utilityPushCmds;
  std::vector<int> utilityPopCmds;
  BaseState<SensorData> *targetState;
};
