#include "Example.h"

State PreLaunch = {
    .transitions = {Transition{
        .cond = And(Value(true), Value(false)),
        .utilityPushCmds =
            {
                DebouncerCommand(
                    1, 10, LessThan<float>(Get<float, accelX>(), Value(200.f))),
            },
        .targetState = &Boost,
    }},
};

// etc.
// State Boost = {};
