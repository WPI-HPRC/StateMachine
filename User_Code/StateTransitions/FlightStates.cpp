#include "../StateTransitions.h"

State<Context> PreLaunch({
  Transition<Context>(
     CONDITION(GET(accelX) > 10),
    {openSolenoidsID},
    {6},
    {UtilityCommands::TimerCommand(11,12)},
    {5},
    &Boost
  )
});
