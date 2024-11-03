/*
    TODO:
    1. Create state transitions using conditionals from last year 
    2. 
*/
#include "State.h"

// Include specific state headers
#include "states/00-PreLaunch.h"
#include "states/01-Launch.h"
#include "states/02-Coast.h"
#include "states/03-DrogueDescent.h"
#include "states/04-MainDescent.h"
#include "states/05-Recovery.h"
#include "states/06-Abort.h"

// State instantiation
State* State::current = nullptr; // Initialize current state
State* State::PreLaunch = new PreLaunch();
State* State::Launch = new Launch();
State* State::Coast = new Coast();
State* State::DrogueDescent = new DrogueDescent();
State* State::MainDescent = new MainDescent();
State* State::Recovery = new Recovery();
State* State::Abort = new Abort();
void setup() {
    State::current->enter();
}

void loop() {
    
    State::current->update();
    State::current->exit();
}
