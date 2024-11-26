#pragma once

#include "Context.h"
#include "Interface.h"

/*
Here we have to pass in the context type to implement Get
*/
#define GENERATE_CONDITIONS(C)                                                 \
  /* Forwared declare Condition and Validator */                               \
  template <typename T> struct IValuator {                                     \
    inline virtual T eval(Ctx<C> *ctx) = 0;                                    \
  };                                                                           \
                                                                               \
  template <typename T> using Valuator = Implementation<IValuator<T>>;         \
                                                                               \
  struct ICondition {                                                          \
    inline virtual bool eval(Ctx<C> *ctx) = 0;                                 \
  };                                                                           \
                                                                               \
  using Condition = Implementation<ICondition>;                                \
                                                                               \
  /* ====== Conditions ====== */                                               \
                                                                               \
  struct And : public ICondition {                                             \
    Condition c1, c2;                                                          \
                                                                               \
    And(Condition const c1, Condition const c2) : c1(c1), c2(c2) {}            \
                                                                               \
    inline bool eval(Ctx<C> *ctx) override {                                   \
      return c1->eval(ctx) && c2->eval(ctx);                                   \
    }                                                                          \
  };                                                                           \
                                                                               \
  template <typename T> struct LessThan : public ICondition {                  \
    Valuator<T> v1, v2;                                                        \
                                                                               \
    LessThan(Valuator<T> const v1, Valuator<T> const v2) : v1(v1), v2(v2) {}   \
                                                                               \
    inline bool eval(Ctx<C> *ctx) override {                                   \
      return v1->eval(ctx) < v2->eval(ctx);                                    \
    }                                                                          \
  };                                                                           \
                                                                               \
  /* ====== Valuators  ====== */                                               \
                                                                               \
  template <typename T> struct Add : public IValuator<T> {                     \
    Valuator<T> v1, v2;                                                        \
                                                                               \
    Add<T>(Valuator<T> const v1, Valuator<T> const v2) : v1(v1), v2(v2) {}     \
                                                                               \
    inline T eval(Ctx<C> *ctx) override {                                      \
      return v1->eval(ctx) + v2->eval(ctx);                                    \
    }                                                                          \
  };                                                                           \
                                                                               \
  template <typename T> struct Value : public IValuator<T> {                   \
    T v;                                                                       \
                                                                               \
    Value<T>(T const v) : v(v) {}                                              \
                                                                               \
    inline T eval(Ctx<C> *ctx) override { return v; }                          \
  };                                                                           \
                                                                               \
  /* Specialize boolean constants to work as conditions */                     \
  template <> struct Value<bool> : public IValuator<bool>, public ICondition { \
    bool v;                                                                    \
                                                                               \
    Value<bool>(bool const v) : v(v) {}                                        \
                                                                               \
    inline bool eval(Ctx<C> *ctx) override { return v; }                       \
  };                                                                           \
                                                                               \
  template <typename T, int id> struct Get : public IValuator<T> {             \
    inline T eval(Ctx<C> *ctx) override {                                      \
      return std::any_cast<T>(ctx->template get<id>());                        \
    }                                                                          \
  };                                                                           \
                                                                               \
  /* Specialize boolean sensor values to work as conditions */                 \
  template <int id>                                                            \
  struct Get<bool, id> : public IValuator<bool>, public ICondition {           \
    inline bool eval(Ctx<C> *ctx) override {                                   \
      return std::any_cast<bool>(ctx->template get<id>());                     \
    }                                                                          \
  };

/*
- Sub
- Mult
- Div
- Abs
- Get
- Mod
- ~~Palindrome~~
*/

/*
- Or
- Not
- LessThan
- GreaterThan
- Value
*/
