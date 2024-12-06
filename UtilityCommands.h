#pragma once
#include "UtilityCommands.cpp"
#include "Condition.h"
#include "Context.h"

using F = bool(void);
using L = void(UtilityCommand);

#undef KEY
#undef MAP
#define KEY(name) constexpr int name  ## Type = __COUNTER__;
#define MAP(name) {name ## Type, & ## name ## Function},

#define CREATE_UTILITY_COMMANDS(utility_commands) \
utility_commands(KEY);                            \
static std::map<int, void(*)(UtilityCommand)> UtilityCommandMap{        \
utility_commands(MAP)                             \
};

#define UTILITYCOMMANDS(Z)    \
Z(generic)            \
Z(timer)              \
Z(debouncer)

CREATE_UTILITY_COMMANDS(UTILITYCOMMANDS)

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
