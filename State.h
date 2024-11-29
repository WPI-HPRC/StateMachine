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

template <typename C> struct TransitionBuilder {
  Condition<C> cond;
  std::initializer_list<int> actuatorPushCmds;
  std::initializer_list<int> actuatorPopCmds;
  std::initializer_list<UtilityCommand> utilityPushCmds;
  std::initializer_list<int> utilityPopCmds;
  State<C> *targetState;

  TransitionBuilder<C>(Condition<C> cond, State<C> *targetState)
      : cond(cond),targetState(targetState) {}

  public TransitionBuilder<typename C> setActuatorPushCmds(std::initializer_list<int> actuatorPushCmds){
    this->actuatorPushCmds = actuatorPushCmds;
    return this;
  }

  public TransitionBuilder<typename C> setActuatorPopCmds(std::initializer_list<int> actuatorPopCmds){
    this->actuatorPopCmds = actuatorPopCmds;
    return this;
  }

  public TransitionBuilder<typename C> setUtilityPushCmds(std::initializer_list<UtilityCommand> utilityPushCmds){
    this->utilityPushCmds = utilityPushCmds;
    return this;
  }

  public TransitionBuilder<typename C> setUtilityPopCmds(std::initializer_list<UtilityCommand> utilityPopCmds){
    this->utilityPopCmds = utilityPopCmds;
    return this;
  }

  public Transition<typename C> build(){
    return new Transition(cond, actuatorPushCmds, actuatorPopCmds,utilityPopCmds,utilityPushCmds,targetState);
  }
};

template <typename C>
TransitionBuilder(ICondition<C>, State<C> *) -> TransitionBuilder<C>;

