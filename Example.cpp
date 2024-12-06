#include "Example.h"
#include "Condition.h"
#include "ActuatorCommands.h"
#include "UtilityCommands.h"

CONDITION(mymaincondition, AND(LESSTHAN(50, 1000), MORETHAN(50, 100)))

State PreLaunch({
  Transition(
     mymaincondition,
    {openSolenoidsID},
    {6},
    {TimerCommand(11,12)},
    {5},
    &Boost
  )
});
// etc.
// State Boost = {};
