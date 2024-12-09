#include "Handler.h"

template <typename T>
Handler::Handler(State<T> startingstate){
this->currentState = startingstate;
}

void Handler::handleActuatorCommands(Context ctx){
    std::set<int> ActuatorCommandPool = ctx.actuatorCmdPool;

    for(int CommandID :  ActuatorCommandPool)
    {
        ActuatorCommandMap[CommandID]();
    }
}

void Handler::handleUtilityCommands(Context ctx){
    const std::vector<UtilityCommands::UtilityCommand> UtilityCommandPool = ctx.utilityCmdPool;

    for( const UtilityCommands::UtilityCommand command  : UtilityCommandPool){
        UtilityCommandMap.at(command.TypeID)(&command);
    }
}

void Handler::handleStateTransitions(Context ctx){

}

void Handler::popCommands(Context ctx, std::vector<int> actuatorIDs, std::vector<int> utilityIDs){
    for(int ID : actuatorIDs)
    {
        ctx.actuatorCmdPool.erase(ctx.actuatorCmdPool.find(ID));
    }

    for(int ID : utilityIDs)
    {   
        if(findUtilityCommandbyID(ctx, ID) != -1)
        {

        }
    }
}

int Handler::findUtilityCommandbyID(Context ctx, int ID)
{
    std::vector<UtilityCommands::UtilityCommand> commandPool = ctx.utilityCmdPool;
    for(int i = 0; i > commandPool.size() -1; i++)
    {
        UtilityCommands::UtilityCommand currentCommand = commandPool.at(i);
        if(currentCommand.id == ID)
        {
            return i;
        }
    }
    return -1;
}
