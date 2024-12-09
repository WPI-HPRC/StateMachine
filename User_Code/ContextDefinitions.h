#include "ActuatorCommands.h"
#include "UtilityCommands.h"

#define SENSOR_DATA(X)            \
  X(float, accelX)                \
  X(bool, limitSwitch)

#define UTILITYCOMMANDS(Z)        \
    Z(generic)                    \
    Z(timer)                      \
    Z(debouncer)

#define ACTUATORCOMMANDS(Y)       \
  Y(expelSolids)                  \
  Y(openSolenoids)                \
  Y(closeSolenoids)               \
  Y(openSolidsDoor)   

