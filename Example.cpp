#include "Example.h"

State PreLaunch({
  Transition(
    And(Value<bool>(true), Value<bool>(false)),
    {},
    {},
    {
      DebouncerCommand(1, 10,
        LessThan(Get<float, accelX>(), Value<float>(200.f))),
    },
    {},
    &Boost
  ),
    new TransitionBuilder(
    LessThan(Value<int>(12), Value<int>(14)), 
    &Boost
    )
    .setUtilityPushCmds(
      DebouncerCommand(1, 10,
        LessThan(Get<float, accelX>(), Value<float>(200.f)))
    )
    .build()
});
// etc.
// State Boost = {};
