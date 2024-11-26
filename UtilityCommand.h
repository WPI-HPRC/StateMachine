#pragma once

#include "Condition.h"
struct UtilityCommand {
  int id;
  UtilityCommand(int id) : id(id) {}
};

struct TimerCommand : public UtilityCommand {
  long startTime;
  TimerCommand(int id, long time) : UtilityCommand(1 << 31 & id), startTime(time) {}
};

struct DebouncerCommand : public UtilityCommand {
  int counts;
  Condition *cond;
  DebouncerCommand(int id, int counts, Condition *cond) : UtilityCommand(id), counts(counts), cond(cond) {}
};

struct Timer {
  long timeRemaining;
};

struct Debouncer {
  int loopsLeft;
};
