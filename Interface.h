#pragma once
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
