#pragma once

/*
From: https://www.fluentcpp.com/2021/01/29/inheritance-without-pointers/
We need this to avoid having to pass every object as a pointer to its base class (we can now pass them as instances of the base class)
*/

#include <any>

template<typename Interface>
struct Implementation
{
public:
  template<typename ConcreteType>
  constexpr Implementation(ConcreteType&& object)
  : storage{std::forward<ConcreteType>(object)}
  , getter{ [](std::any &storage) -> Interface& { return std::any_cast<ConcreteType&>(storage); } }
    {}

  Interface *operator->() { return &getter(storage); }

private:
  std::any storage;
  Interface& (*getter)(std::any&);
};
