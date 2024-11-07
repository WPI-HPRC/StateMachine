#include "../Context.h"  // Include the Context struct
#include "stdint.h"   // Include for fixed-width integer types

/**
 * @brief State class represents a single state in the state machine.
 * 
 * This class serves as an abstract base class for all states in the system. 
 * Specific states (e.g., PreLaunch, Launch) should derive from this class 
 * and implement the `setup()`, `loop()`, and `exit()` methods.
 */
class State { 
private: 
    Context* ctx;                 //Store sensor data 
    uint64_t startTime;       //get the current time 
    uint64_t currentTime;     //get the starting time 

public: 
    virtual ~State() = default;

    State(Context *ctx) {
        this->ctx = ctx;  // Initialize the context pointer
        this->startTime = 0;  // Set the initial value of startTime
        this->currentTime = 0;  // Set the initial value of currentTime
    }

    //Abstract methods for each state 
    virtual void setup() = 0;                   // Initialize variables
    virtual void loop() = 0;                    // Main logic for state
    virtual void exit() = 0;                    // Cleanup before exiting state

    static State* PreLaunch;
    static State* Launch;
    static State* Coast;
    static State* DrogueDescent;
    static State* MainDescent;
    static State* Recovery;
    static State* Abort;
};

// Initialize the static state pointers to nullptr
State* State::PreLaunch = nullptr;
State* State::Launch = nullptr;
State* State::Coast = nullptr;
State* State::DrogueDescent = nullptr;
State* State::MainDescent = nullptr;
State* State::Recovery = nullptr;
State* State::Abort = nullptr;

