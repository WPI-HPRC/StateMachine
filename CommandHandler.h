#include "Context.h"
#include "example.h"


class CommandHandler{
    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param context the context
     */
    void HandleUtilityCommands(Context context);

    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param context the context
     */
    void HandleActuatorCommands(Context context);

    void popCommands(Context context, std::list<int> actuatorIDs, std::list<int> utilityIDs);
    int findUtilityCommandbyID(Context context, int ID);
};