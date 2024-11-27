#include "Context.h"
#include "State.h"

#define SENSOR_DATA(X)                                                         \
  X(float, accelX)                                                             \
  X(bool, limitSwitch)

CREATE_CONTEXT(SENSOR_DATA);

extern State<Context> PreLaunch;
extern State<Context> Boost;
