#include "State.h"
#include "Context.h"

struct SensorData {
  float accelX;
  bool limitSwitch;
};

USE_SENSOR_DATA(SensorData);

extern State PreLaunch;
extern State Boost;
