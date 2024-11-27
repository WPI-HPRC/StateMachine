#include "Example.h"

State PreLaunch = {
    .transitions = {Transition{
        .cond = [](Context ctx) -> bool {
          return ctx.sensorData.accelX > 10.f;
        },
        .utilityPushCmds =
            {
                DebouncerCommand(1, 10,
                                 [](Context ctx) -> bool {
                                   return ctx.sensorData.limitSwitch;
                                 }),
            },
        .targetState = &Boost,
    }},
};

// etc.
// State Boost = {};
