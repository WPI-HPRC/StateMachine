#include "State.h"
class MainDescent : public State {
    public: 
        MainDescent();
        virtual ~MainDescent();

        virtual void enter_impl();              //Entering state (initializing variables)
        virtual void update_impl();            //Operating in state (most of code goes )
        virtual void exit_impl();              //Leave a state (free memory)
};
