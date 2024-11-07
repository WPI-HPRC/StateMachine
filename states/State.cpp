#include <Arduino.h>       // Include Arduino functions
#include <stdint.h>  // Include for fixed-width integer types
#include "State.h"  
#include "Context.h" //Probably file will include structs of context for each different type of data 

// Static state pointers initialization
State* State::current = nullptr;
State* State::PreLaunch = nullptr;
State* State::Launch = nullptr;
State* State::Coast = nullptr;
State* State::DrogueDescent = nullptr;
State* State::MainDescent = nullptr;
State* State::Recovery = nullptr;
State* State::Abort = nullptr;


State::State(Context* ctx) {
    this->ctx = ctx;  //Store sensor data 
    this->startTime = millis(); 
    this->currentTime = 0;  // Initialize current time
};

/**
 * @brief Setup method to initialize state-specific variables
 * 
 * This method is invoked when the state is entered. It can be used to set 
 * up specific resources, such as timers, flags, or other initializations 
 * for that state.
 */
void State::setup() {
    this->startTime = millis(); //Get the start time when called
};

/**
 * @brief Loop method to update the state logic
 * 
 * The `loop()` method gets called repeatedly for each active state, where
 * you can handle any state-specific logic like checking conditions or updating
 * data. The state logic will differ for each state.
 */
void State::loop() {
    uint64_t now = millis(); //Get the current time in updating 
    this->currentTime = now - this->startTime;
};

/**
 * @brief Exit method for cleanup when transitioning away from a state
 * 
 * This method is invoked when transitioning from one state to another. It allows
 * you to perform any necessary cleanup such as stopping timers or clearing 
 * flags associated with the state.
 */
void State::exit() {
     // Any necessary cleanup or resource freeing can be done here
};





