#pragma once

#include "Condition.h"
#include "UtilityCommand.h"
#include <initializer_list>

template <typename C> struct Transition;
template <typename C> struct State;

template <typename C> struct State {
  std::initializer_list<Transition<C>> transitions;

  State<C>(std::initializer_list<Transition<C>> transitions) : transitions(transitions) {}
};

template <typename C>
State(std::initializer_list<Transition<C>>) -> State<C>;

template <typename C> struct Transition {
  Condition<C> cond;
  std::initializer_list<int> actuatorPushCmds;
  std::initializer_list<int> actuatorPopCmds;
  std::initializer_list<UtilityCommand> utilityPushCmds;
  std::initializer_list<int> utilityPopCmds;
  State<C> *targetState;

  Transition<C>(Condition<C> cond, std::initializer_list<int> actuatorPushCmds,
                std::initializer_list<int> actuatorPopCmds,
                std::initializer_list<UtilityCommand> utilityPushCmds,
                std::initializer_list<int> utilityPopCmds,
                State<C> *targetState)
      : cond(cond), actuatorPushCmds(actuatorPushCmds),
        actuatorPopCmds(actuatorPopCmds), utilityPushCmds(utilityPushCmds),
        utilityPopCmds(utilityPopCmds), targetState(targetState) {}
};

template <typename C>
Transition(ICondition<C>, std::initializer_list<int>,
           std::initializer_list<int>, std::initializer_list<UtilityCommand>,
           std::initializer_list<int>, State<C> *) -> Transition<C>;
