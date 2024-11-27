#pragma once

#include <any>
#include <map>
#include <set>

#define FIELD(typ, name) typ name;
#define KEY(typ, name) constexpr int name = __COUNTER__;
#define GET(typ, name)                                                         \
  template <> std::any get<::name>() { return std::any(this->name); }

template <typename T> struct Ctx {
  template <int key> std::any get() { return ((T *)this)->template get<key>(); }
};

#define CREATE_CONTEXT(sensor_data)                                            \
  sensor_data(KEY);                                                            \
  struct Context : public Ctx<Context> {                                       \
    sensor_data(FIELD);                                                        \
    std::set<int> actuatorCmdPool;                                             \
    std::map<int, UtilityCommand> utilityCmdPool;                              \
                                                                               \
    template <int key> std::any get();                                         \
    sensor_data(GET);                                                          \
  };                                                                           \
  template <typename T> using Value = BaseValue<T, Context>;                   \
  template <typename T, int id> using Get = BaseGet<T, id, Context>;
