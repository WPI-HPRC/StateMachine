#include "Handler.h"
#include "Context.h"
#include <list>

void Handler::HandleActuatorCommands(Context ctx){
    std::set<int> ActuatorCommandPool = ctx.actuatorCmdPool;

    for(int CommandID :  ActuatorCommandPool)
    {
        ActuatorCommandMap[CommandID]();
    }
}

void Handler::HandleUtilityCommands(Context ctx){
    std::list<UtilityCommand> UtilityCommandPool = ctx.utilityCmdPool;

    for( UtilityCommand Command  : UtilityCommandPool){
        UtilityCommandMap[Command.TypeID](Command);
    }
}

void Handler::popCommands(Context ctx, std::list<int> actuatorIDs, std::list<int> utilityIDs){
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
  return -1; //TODO: Make this work
}
