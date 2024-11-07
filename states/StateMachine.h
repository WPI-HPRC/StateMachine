#pragma once
#include "State.h"

/**
 * @class StateMachine
 * @brief A class that controls the flow of states within a system.
 *
 * The `StateMachine` class manages the current state, handles transitions to new states,
 * and ensures that the setup, loop, and exit methods are called for each active state. 
 * It runs in a loop, executing the logic of the active state and transitioning between states 
 * based on specific conditions.
 */
class StateMachine {
    private: 
        bool isRunning;  ///< A flag indicating if the state machine is actively running.
        State* currentState;  ///< Pointer to the current active state.
    public: 
        /**
         * @brief Default constructor for the StateMachine class.
         * 
         * Initializes the state machine and sets the initial state to `PreLaunch`.
         * The state machine is not running at this point.
         */
        StateMachine();

        /**
         * @brief Starts the state machine and enters the main loop.
         *
         * The `run()` method starts the execution of the state machine. It enters a loop where
         * it continuously calls the `loop()` method of the active state and checks if state transitions
         * need to occur.
         */
        void run();

         /**
         * @brief Stops the state machine.
         * 
         * This method halts the execution of the state machine. It stops the main loop and ensures that
         * the current state is cleaned up by calling its `exit()` method.
         */
        void stop();

        /**
         * @brief Transitions to a new state.
         * 
         * This method manages the transition from the current state to a new state. It calls the 
         * `exit()` method of the current state, then switches to the new state and calls its `setup()` method.
         *
         * @param newState The new state to transition into.
         */
        void setState(State* newState);

        /**
         * @brief Retrieves the current active state.
         * 
         * This method returns the pointer to the current active state.
         * 
         * @return State* The current state.
         */
        State* getState() const;

};