#pragma once

#include "Condition.h"

struct IUtilityCommand {
  int id;
  IUtilityCommand(int id) : id(id) {}
};

using UtilityCommand = Implementation<IUtilityCommand>;

#define GENERATE_UTILS()                                                       \
  struct TimerCommand : public IUtilityCommand {                               \
    long startTime;                                                            \
    TimerCommand(int id, long time)                                            \
        : IUtilityCommand(1 << 31 & id), startTime(time) {}                    \
  };                                                                           \
                                                                               \
  struct DebouncerCommand : public IUtilityCommand {                           \
    int counts;                                                                \
    Condition cond;                                                            \
    DebouncerCommand(int id, int counts, Condition const cond)                 \
        : IUtilityCommand(id), counts(counts), cond(cond) {}                   \
  };                                                                           \
                                                                               \
  struct Timer {                                                               \
    long timeRemaining;                                                        \
  };                                                                           \
                                                                               \
  struct Debouncer {                                                           \
    int loopsLeft;                                                             \
  };
