#include "Context.h"
#include "StateTransitions.h"
#include "State.h"
#include <list>

class Handler{
    public:
    State<Context> currentState;
    /**
     * @brief Constructs a new Handler
     * 
     * @param startingState the initial state. Remember to manually push initial utils!
     */
    template <typename T>
    Handler(State<T> startingState);

    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param ctx the context
     */
    void handleUtilityCommands(Context ctx);

    /**
     * @brief Runs / Handles all of the Utility Commands in the Utility pool 
     *        and updates the context with the new values
     * 
     * @param ctx the context
     */
    void handleActuatorCommands(Context ctx);

    /**
     * @brief Runs / Handles the state transition. Checks the context for sensor and utility data and then 
     * takes the correct state transition. Also pushes and pops all specified commands from the state transition
     * 
     * @param ctx the context
     */
    void handleStateTransitions(Context ctx);
    
    /**
     * @brief manually pops specified actuator and utility commands
     * 
     * @param ctx the context
     * 
     * @param actuatorIDs a list of the IDs of the actuator commands to be popped
     * 
     * @param utilityIDs a list of the IDs of the utility commands to be popped
     */
    void popCommands(Context ctx, std::list<int> actuatorIDs, std::list<int> utilityIDs);

      /**
     * @brief manually pushes specified actuator and utility commands
     * 
     * @param ctx the context
     * 
     * @param actuatorIDs a list of the IDs of the actuator commands to be popped
     * 
     * @param utilityCmds a list of the  Utility Commands to be pushed
     */
    void pushCommands(Context ctx, std::list<int> actuatorIDs, std::list<UtilityCommand> UtilityCmds);

    /**
     * @brief finds the position of the utilityCmd in the utility pool by its ID. 
     * 
     * @param ctx the context
     * 
     * @param ID the ID of the utility Command you wish to find
     */
    int findUtilityCommandbyID(Context ctx, int ID);

};