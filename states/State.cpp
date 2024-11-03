//#include <Arduino.h>
#include "State.h"  
#include <stdint.h> // Include this header for fixed-width integer types



State::State() {
    this->startTime = millis();
};

State:: ~State() {

};

void State::enter() {
    this->startTime = millis(); //Get the start time when called
};

void State::update() {
    uint64_t now = millis(); //Get the current time in updating 
    this->currentTime = now - this->startTime;
};

void State::setState(State* newState) {
    //Maybe switch statement? 
}

void State::exit() {
    
};





