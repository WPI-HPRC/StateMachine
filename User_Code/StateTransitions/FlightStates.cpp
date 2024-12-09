#include "StateTransitions.h"

State PreLaunch({
  Transition(
     CONDITION(MORETHAN(ctx.accelX, 10)),
    {openSolenoidsID},
    {6},
    {TimerCommand(11,12)},
    {5},
    &Boost
  )
});