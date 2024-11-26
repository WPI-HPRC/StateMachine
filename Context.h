#pragma once

#define SENSOR_DATA(X) \
  X(float, accelX, 1) \
  X(bool, limitSwitch, 2) \

#include <set>
#include <map>
#include "UtilityCommand.h"

#define FIELD(typ, name, key) typ name;
#define SENSOR_MAP(typ)
#define KEY(typ, name, key) constexpr int name = key;

// struct Ctx {
//   template <typename T>
//   T get(int id) {};
// };

#define CREATE_CONTEXT(sensor_data) \
  struct Context : public Ctx { \
    sensor_data(FIELD); \
    std::set<int> actuatorCmdPool; \
    std::map<int, UtilityCommand *> utilityCmdPool; \
  }; \
  sensor_data(KEY);
