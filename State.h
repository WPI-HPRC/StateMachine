#pragma once

#include "Condition.h"
#include "UtilityCommand.h"
#include <initializer_list>
#include <list>

template <typename C> struct Transition;
template <typename C> struct State;

template <typename C> struct State {
  std::list<Transition<C>> transitions;

  State<C>(std::list<Transition<C>> transitions) : transitions(transitions) {}
};

template <typename C>
State(std::list<Transition<C>>) -> State<C>;

template <typename C> struct Transition {
  Condition<C> cond;
  std::list<int> actuatorPushCmds;
  std::list<int> actuatorPopCmds;
  std::list<UtilityCommand> utilityPushCmds;
  std::list<int> utilityPopCmds;
  State<C> *targetState;

  Transition<C>(Condition<C> cond, std::list<int> actuatorPushCmds,
                std::list<int> actuatorPopCmds,
                std::list<UtilityCommand> utilityPushCmds,
                std::list<int> utilityPopCmds,
                State<C> *targetState)
      : cond(cond), actuatorPushCmds(actuatorPushCmds),
        actuatorPopCmds(actuatorPopCmds), utilityPushCmds(utilityPushCmds),
        utilityPopCmds(utilityPopCmds), targetState(targetState) {}
};

template <typename C>
Transition(ICondition<C>, std::list<int>,
           std::list<int>, std::list<UtilityCommand>,
           std::list<int>, State<C> *) -> Transition<C>;

template <typename C> struct TransitionBuilder {
  Condition<C> cond;
  std::list<int> actuatorPushCmds;
  std::list<int> actuatorPopCmds;
  std::list<UtilityCommand> utilityPushCmds;
  std::list<int> utilityPopCmds;
  State<C> *targetState;

  TransitionBuilder<C>(Condition<C> cond, State<C> *targetState)
      : cond(cond),targetState(targetState) {}

  public TransitionBuilder<typename C> setActuatorPushCmds(std::list<int> actuatorPushCmds){
    this->actuatorPushCmds = actuatorPushCmds;
    return this;
  }

  public TransitionBuilder<typename C> setActuatorPopCmds(std::list<int> actuatorPopCmds){
    this->actuatorPopCmds = actuatorPopCmds;
    return this;
  }

  public TransitionBuilder<typename C> setUtilityPushCmds(std::list<UtilityCommand> utilityPushCmds){
    this->utilityPushCmds = utilityPushCmds;
    return this;
  }

  public TransitionBuilder<typename C> setUtilityPopCmds(std::list<UtilityCommand> utilityPopCmds){
    this->utilityPopCmds = utilityPopCmds;
    return this;
  }

  public Transition<typename C> build(){
    return new Transition(cond, actuatorPushCmds, actuatorPopCmds,utilityPopCmds,utilityPushCmds,targetState);
  }
};

template <typename C>
TransitionBuilder(ICondition<C>, State<C> *) -> TransitionBuilder<C>;

