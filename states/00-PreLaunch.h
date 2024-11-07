#include <stdint.h>
#include "State.h" 

class PreLaunch : public State {
    public: 
        PreLaunch(); 
        virtual ~PreLaunch();

        virtual void setup_impl();          //Entering state (initializing variables)
        virtual void loop_impl();           //Operating in state (most of code goes )
        virtual void exit_impl();           //Leave a state (free memory)
    private: 
        
};
