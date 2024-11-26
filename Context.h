#pragma once

#include <any>
#include <map>
#include <set>

#define FIELD(typ, name, key) typ name;
#define KEY(typ, name, key) constexpr int name = key;
#define GET(typ, name, key)                                                    \
  template <> std::any get<key>() { return std::any(this->name); }

template <typename T> struct Ctx {
  template <int key> std::any get() { return ((T *)this)->template get<key>(); }
};

template <int key> struct Map {};

#define CREATE_CONTEXT(sensor_data)                                            \
  struct Context : public Ctx<Context> {                                       \
    sensor_data(FIELD);                                                        \
    std::set<int> actuatorCmdPool;                                             \
    std::map<int, UtilityCommand> utilityCmdPool;                              \
                                                                               \
    template <int key> std::any get();                                         \
    sensor_data(GET);                                                          \
  };                                                                           \
  sensor_data(KEY);                                                            \
  GENERATE_CONDITIONS(Context);                                                \
  GENERATE_UTILS();                                                            \
  GENERATE_STATES();\
