#pragma once
#include "../Library/Context.h"
#include "../Library/Condition.h"
#include <functional>

namespace UtilityCommands {


  struct UtilityCommand {
    int id;
    int TypeID;
    UtilityCommand(int id) : id(id) {TypeID = genericType;}
  };
  void genericFunction(const UtilityCommand* genericCommand);
  struct TimerCommand : public UtilityCommand {
    long startTime;
    TimerCommand(int id, long time)
        : UtilityCommand(1 << 31 & id), startTime(time) {TypeID = timerType;}
  };
  void timerFunction(const UtilityCommand* timerCommand);
  struct DebouncerCommand : public UtilityCommand {
    int counts;
    std::function<bool(const Context*)> cond;
    DebouncerCommand(int id, int counts, std::function<bool(const Context*)> cond)
        : UtilityCommand(id), counts(counts), cond(cond) {TypeID = debouncerType;}
  };
  void debouncerFunction(const UtilityCommand* debouncerCommand);

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