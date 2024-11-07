#include "StateMachine.h" 

StateMachine::StateMachine() : isRunning(false) {
    setState(State::PreLaunch); // Start with the PreLaunch state (This can be changed to other initial states if needed)
}

/**
 * @brief Starts the state machine and enters the main loop.
 * 
 * The `run()` method starts the state machine's execution. It enters a loop, continuously 
 * calling the `loop()` method of the active state, and checks for conditions that trigger 
 * state transitions. This loop runs as long as the state machine is marked as running.
 */
void StateMachine::run() {
    isRunning = true; //Flag indicator
    while (isRunning) {
        if (StateMachine::currentState != nullptr) {
            StateMachine::currentState->loop();  // Call loop for the active state
        }
        ////////////////////// Insert logic here to decide when to transition states //////////////////////////
        //EX: check for a button press or a specific sensor input
    }
}

/**
 * @brief Stops the state machine.
 * 
 * This method halts the execution of the state machine by setting the `isRunning` flag 
 * to `false`. It also calls the `exit()` method of the current active state to clean 
 * up resources before stopping the state machine.
 */
void StateMachine::stop() {
    isRunning = false;
    if (StateMachine::currentState != nullptr) {
        StateMachine::currentState->exit();  // Cleanup before stopping like freeing memory and whatnot
    }
}

/**
 * @brief Transitions to a new state.
 * 
 * This method manages the transition from the current active state to a new state. It 
 * involves calling the `exit()` method on the current state and then calling `setup()` 
 * on the new state.
 * 
 * @param newState The new state to transition into.
 */
void StateMachine::setState(State* newState) {
    if (StateMachine::currentState != nullptr) {
        StateMachine::currentState->exit();    //Free memory from previous state before transition
    }

    StateMachine::currentState = newState;     // Update the current state
    if (StateMachine::currentState != nullptr) {
        StateMachine::currentState->setup();   //Initialize the new state
    }
}

/**
 * @brief Retrieves the current active state.
 * 
 * This method returns the pointer to the current active state. It is useful for checking
 * the current state or for debugging purposes.
 * 
 * @return State* The current state.
 */
State* StateMachine::getState() const {
    return StateMachine::currentState;
}


