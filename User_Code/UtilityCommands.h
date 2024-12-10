#pragma once

#include "../Library/Condition.h"
#include "../Library/Fuckyou.h"
#include "../Library/Context.h"
#include <functional>

namespace moreUtilityCommands {
  using namespace UtilityCommands;

  void genericFunction(const UtilityCommands::UtilityCommand* genericCommand);
  struct TimerCommand : public UtilityCommands::UtilityCommand {
    long startTime;
    TimerCommand(int id, long time)
        : UtilityCommands::UtilityCommand(1 << 31 & id), startTime(time) {TypeID = timerType;}
  };
  void timerFunction(const UtilityCommands::UtilityCommand* timerCommand);
  struct DebouncerCommand : public UtilityCommands::UtilityCommand {
    int counts;
    std::function<bool(const Context*)> cond;
    DebouncerCommand(int id, int counts, std::function<bool(const Context*)> cond)
        : UtilityCommands::UtilityCommand(id), counts(counts), cond(cond) {TypeID = debouncerType;}
  };
  void debouncerFunction(const UtilityCommands::UtilityCommand* debouncerCommand);

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
};