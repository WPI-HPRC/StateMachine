#include "CommandHandler.h"
#include "ActuatorCommands.h"
#include "Context.h"
#include <list>

void CommandHandler::HandleActuatorCommands(Context context){
    std::set<int> ActuatorCommandPool = context.actuatorCmdPool;

    for(int CommandID :  ActuatorCommandPool)
    {
        ActuatorCommandMap[CommandID]();
    }
}

void CommandHandler::HandleUtilityCommands(Context context){
    std::list<UtilityCommand> UtilityCommandPool = context.utilityCmdPool;

    for( UtilityCommand Command  : UtilityCommandPool){
        UtilityCommandMap[Command.TypeID](Command);
    }
}

void CommandHandler::popCommands(Context context, std::list<int> actuatorIDs, std::list<int> utilityIDs){
    for(int ID : actuatorIDs)
    {
        context.actuatorCmdPool.erase(context.actuatorCmdPool.find(ID));
    }

    for(int ID : utilityIDs)
    {   
        if(findUtilityCommandbyID(context, ID) != -1)
        {

        }
    }
}

int CommandHandler::findUtilityCommandbyID(Context context, int ID)
{
  return -1; //TODO: Make this work
}



