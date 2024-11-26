#pragma once

#include "Valuator.h"

struct Condition {
  virtual bool eval() = 0;
};

struct And : public Condition {
  Condition *c1, *c2;

  And(Condition *c1, Condition *c2) : c1(c1), c2(c2) {}

  bool eval() override {
    return c1->eval() && c2->eval();
  }
};

struct Value : public Condition {
  Valuator<bool> *v;

  Value(Valuator<bool> *v) : v(v) {}

  bool eval() override {
    return v->eval();
  }
};

/*
- Or
- Not
- LessThan
- GreaterThan
- Value
*/

