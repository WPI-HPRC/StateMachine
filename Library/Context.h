#pragma once

#include <any>
#include <map>
#include <set>
#include "ContextDefinitions.h"

using F = bool(void);
using L = void(UtilityCommand);

#undef KEY
#undef MAP
#define FIELD(typ, name) typ name;
#define CONTEXT_KEY(typ, name) constexpr int name = __COUNTER__;
#define GET(typ, name)                                                        \
  template <> std::any get<::name>() { return std::any(this->name); }

template <typename T> struct Ctx {
  template <int key> std::any get() { return ((T *)this)->template get<key>(); }
};

#define CREATE_CONTEXT(sensor_data)                                           \
  sensor_data(CONTEXT_KEY);                                                   \
  struct Context : public Ctx<Context> {                                      \
    sensor_data(FIELD);                                                       \
    std::set<int> actuatorCmdPool;                                            \
    std::list<UtilityCommand> utilityCmdPool;                                 \
                                                                              \
    template <int key> std::any get();                                        \
    sensor_data(GET);                                                         \
  };                                                                          \
  template <typename T> using Value = BaseValue<T, Context>;                  \
  template <typename T, int id> using Get = BaseGet<T, id, Context>;

CREATE_CONTEXT(SENSOR_DATA);

#undef KEY
#undef MAP
#define UTILITY_KEY(name) constexpr int name  ## Type = __COUNTER__;
#define UTILITY_MAP(name) {name ## Type, & ## name ## Function},

#define CREATE_UTILITY_COMMANDS(utility_commands)                             \
utility_commands(UTILITY_KEY);                                                \
static std::map<int, void(*)(UtilityCommand)> UtilityCommandMap{              \
utility_commands(UTILITY_MAP)                                                 \
};

CREATE_UTILITY_COMMANDS(UTILITYCOMMANDS)


#define ACTUATOR_KEY(name) constexpr int name ## ID = __COUNTER__;
#define ACTUATOR_MAP(name) {name ## ID, &name},

#define CREATE_ACTUATOR_COMMANDS(actuator_commands)                                      \
  actuator_commands(ACTUATOR_KEY);                                                       \
  static  std::map<const int, void(*)()> ActuatorCommandMap = {        \
    actuator_commands(ACTUATOR_MAP)                                                      \
  };  

CREATE_ACTUATOR_COMMANDS(ACTUATORCOMMANDS)

