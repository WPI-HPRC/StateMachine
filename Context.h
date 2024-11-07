#pragma once
#include "stdint.h"  // For fixed-width integer types

/**
 * @brief A structure that holds sensor data for the state machine.
 *
 * The `Context` struct is used to store the sensor readings and other related 
 * data that are needed for the state machine to make decisions and transitions. 
 * This includes data like accelerometer readings, sensor flags, and time stamps.
 */
struct Context {
    // other members
};

//Can expand into other structs such as Rocket and RTOS