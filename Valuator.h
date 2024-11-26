#pragma once

template <typename T>
struct Valuator {
  virtual T eval() = 0;
};

template <typename T>
class Add : public Valuator<T> {
  Valuator<T> *v1, *v2;

  Add<T> (Valuator<T> *v1, Valuator<T> *v2) : v1(v1), v2(v2) {}

  T eval() override {
    return v1->eval() + v2->eval();
  }
};

template <typename T>
class Val : public Valuator<T> {
  T v;

  Val<T> (T v) : v(v) {}

  T eval() override {
    return v;
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
