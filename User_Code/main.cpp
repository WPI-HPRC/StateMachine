#include "../library/Handler.h"

Context ctx; 
Handler handler = Handler(PreLaunch);

void setup(){
    

}

void loop(){
    
    //update sensors
    handler.handleUtilityCommands(ctx);
    handler.handleActuatorCommands(ctx);
    handler.handleStateTransitions(ctx);
    
}