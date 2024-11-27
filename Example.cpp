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
  )
});

// etc.
// State Boost = {};
