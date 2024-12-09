#pragma once
#include "../Library/Context.h"
#include "../Library/State.h"
#include "../Library/Condition.h"
// Flight Transitions -----------------------------------------------------------------------------
    /**
     * @brief the state that comes a bit before launch
     */
    extern State<Context> PreLaunch;

     /**
     * @brief Whoosh!
     */
    extern State<Context> Boost;

// Self Righting Transitions ----------------------------------------------------------------------

    
// Planting Transitions ---------------------------------------------------------------------------

