#pragma once

#include "Context.h"
#include "Interface.h"
#include <functional>

struct IUtilityCommand {
  int id;
  IUtilityCommand(int id) : id(id) {}
};

using UtilityCommand = Implementation<IUtilityCommand>;

struct TimerCommand : public IUtilityCommand {
  long startTime;
  TimerCommand(int id, long time)
      : IUtilityCommand(1 << 31 & id), startTime(time) {}
};

template <typename SensorData>
struct BaseDebouncerCommand : public IUtilityCommand {
  int counts;
  std::function<bool(Ctx<SensorData>)> cond;
  BaseDebouncerCommand(int id, int counts,
                   std::function<bool(Ctx<SensorData>)> const cond)
      : IUtilityCommand(id), counts(counts), cond(cond) {}
};

struct Timer {
  long timeRemaining;
};

struct Debouncer {
  int loopsLeft;
};
