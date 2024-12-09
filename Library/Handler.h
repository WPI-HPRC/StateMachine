#include "Context.h"
#include "StateTransitions.h"


class Handler{
    public:
    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param ctx the context
     */
    void HandleUtilityCommands(Context ctx);

    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param ctx the context
     */
    void HandleActuatorCommands(Context ctx);

    /**
     * Brief 
     */
    void HandleStateTransitions(Context ctx);

    void popCommands(Context ctx, std::list<int> actuatorIDs, std::list<int> utilityIDs);

    int findUtilityCommandbyID(Context ctx, int ID);

};