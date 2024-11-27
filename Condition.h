#pragma once

#include "Context.h"
#include "Interface.h"

/* Forwared declare Condition and Valuator */
template <typename T, typename C> struct IValuator {
  inline virtual T eval(Ctx<C> *ctx) = 0;
};

template <typename T, typename C>
using Valuator = Implementation<IValuator<T, C>>;

template <typename C> struct ICondition {
  inline virtual bool eval(Ctx<C> *ctx) = 0;
};

template <typename C> using Condition = Implementation<ICondition<C>>;

/* ====== Conditions ====== */

template <typename C> struct And : public ICondition<C> {
  Condition<C> c1, c2;

  And(Condition<C> const c1, Condition<C> const c2) : c1(c1), c2(c2) {}

  inline bool eval(Ctx<C> *ctx) override {
    return c1->eval(ctx) && c2->eval(ctx);
  }
};

template <typename C> And(ICondition<C>, ICondition<C>) -> And<C>;

template <typename T, typename C> struct LessThan : public ICondition<C> {
  Valuator<T, C> v1, v2;

  LessThan(Valuator<T, C> const v1, Valuator<T, C> const v2) : v1(v1), v2(v2) {}

  inline bool eval(Ctx<C> *ctx) override {
    return v1->eval(ctx) < v2->eval(ctx);
  }
};

template <typename T, typename C>
LessThan(IValuator<T, C>, IValuator<T, C>) -> LessThan<T, C>;

/* ====== Valuators  ====== */

template <typename T, typename C> struct Add : public IValuator<T, C> {
  Valuator<T, C> v1, v2;

  Add<T>(Valuator<T, C> const v1, Valuator<T, C> const v2) : v1(v1), v2(v2) {}

  inline T eval(Ctx<C> *ctx) override { return v1->eval(ctx) + v2->eval(ctx); }
};

template <typename T, typename C>
Add(IValuator<T, C>, IValuator<T, C>) -> Add<T, C>;

template <typename T, typename C> struct BaseValue : public IValuator<T, C> {
  T v;

  BaseValue<T, C>(T const v) : v(v) {}

  inline T eval(Ctx<C> *ctx) override { return v; }
};

/* Specialize boolean constants to work as conditions */
template <typename C>
struct BaseValue<bool, C> : public IValuator<bool, C>, public ICondition<C> {
  bool v;

  BaseValue<bool, C>(bool const v) : v(v) {}

  inline bool eval(Ctx<C> *ctx) override { return v; }
};

template <typename T, int id, typename C> struct BaseGet : public IValuator<T, C> {
  inline T eval(Ctx<C> *ctx) override {
    return std::any_cast<T>(ctx->template get<id>());
  }
};

/* Specialize boolean sensor values to work as conditions */
template <int id, typename C>
struct BaseGet<bool, id, C> : public IValuator<bool, C>, public ICondition<C> {
  inline bool eval(Ctx<C> *ctx) override {
    return std::any_cast<bool>(ctx->template get<id>());
  }
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
