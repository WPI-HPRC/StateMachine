#pragma once

#include "Condition.h"
#include "../User_Code/UtilityCommands.h"
#include <initializer_list>
#include <list>
#include <functional>

using F = bool(void);

template <typename C> struct Transition;
template <typename C> struct State;

template <typename C> struct State {
  std::vector<Transition<C>> transitions;

  State<C>(std::initializer_list<Transition<C>> transitions) : transitions(transitions) {}
};

template <typename C>
State(std::initializer_list<Transition<C>>) -> State<C>;

template <typename C> struct Transition {
  std::function<bool(const Context*)> cond;
  std::vector<int> actuatorPushCmds;
  std::vector<int> actuatorPopCmds;
  std::vector<UtilityCommands::UtilityCommand> utilityPushCmds;
  std::vector<int> utilityPopCmds;
  State<C> *targetState;

  Transition<C>(std::function<bool(const Context*)> cond, std::vector<int> actuatorPushCmds,
                std::vector<int> actuatorPopCmds,
                std::vector<UtilityCommands::UtilityCommand> utilityPushCmds,
                std::vector<int> utilityPopCmds,
                State<C> *targetState)
      : cond(cond), actuatorPushCmds(actuatorPushCmds),
        actuatorPopCmds(actuatorPopCmds), utilityPushCmds(utilityPushCmds),
        utilityPopCmds(utilityPopCmds), targetState(targetState) {}
};

template <typename C>
Transition(std::function<bool(Context ctx)>, std::vector<int>,
           std::vector<int>, std::vector<UtilityCommands::UtilityCommand>,
           std::vector<int>, State<C> *) -> Transition<C>;


