#pragma once
#include <map>

namespace ActuatorCommands{
// Flight Commands --------------------------------------------------------------------------------
    /**
     * @brief
     */
    void explode();

// Self Righting Commands -------------------------------------------------------------------------
    /**
     * @brief
     */
    void flip();

// Planting Commands ------------------------------------------------------------------------------
    /**
     * @brief opens the solenoids
     */                                           
    void openSolenoids();

    /**
     * @brief closes the solenoids
     */
    void closeSolenoids();

    /**
     * @brief expels the solids
     */
    void expelSolids();

    /**
     * @brief opens the solids door using rack and pinion
     */
    void openSolidsDoor();
};
