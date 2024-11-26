#include "State.h"
#include "Context.h"

#define SENSOR_DATA(X)                                                         \
  X(float, accelX, 1)                                                          \
  X(bool, limitSwitch, 2)

CREATE_CONTEXT(SENSOR_DATA);

extern State PreLaunch;
extern State Boost;
