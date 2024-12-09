#pragma once
#include "BasicUtilityCommands.cpp"
#include "Condition.h"
#include "Context.h"
#include "EKF.cpp"
#include "PID.cpp"

struct UtilityCommand {
  int id;
  int TypeID;
  UtilityCommand(int id) : id(id) {TypeID = genericType;}
};

struct TimerCommand : public UtilityCommand {
  long startTime;
  TimerCommand(int id, long time)
      : UtilityCommand(1 << 31 & id), startTime(time) {TypeID = timerType;}
};

struct DebouncerCommand : public UtilityCommand {
  int counts;
  F* cond;
  DebouncerCommand(int id, int counts, F* cond)
      : UtilityCommand(id), counts(counts), cond(cond) {TypeID = debouncerType;}
};

/*
template <typename C>
DebouncerCommand(int, int, ICondition<C>) -> DebouncerCommand<C>;
*/
struct Timer {
  long timeRemaining;
};

struct Debouncer {
  int loopsLeft;
};
