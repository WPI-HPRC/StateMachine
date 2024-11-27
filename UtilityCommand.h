#pragma once

#include "Condition.h"

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

template <typename C>
struct DebouncerCommand : public IUtilityCommand {
  int counts;
  Condition<C> cond;
  DebouncerCommand(int id, int counts, Condition<C> const cond)
      : IUtilityCommand(id), counts(counts), cond(cond) {}
};

template <typename C>
DebouncerCommand(int, int, ICondition<C>) -> DebouncerCommand<C>;

struct Timer {
  long timeRemaining;
};

struct Debouncer {
  int loopsLeft;
};
