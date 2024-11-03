/*
Looking to utilize a polymorphic state machine for the following reasons: 
1. Modular 
2. Good for complex system behavoir such as sensor readings for each state 
3. Adding new states doesn't affect other states 
*/

/**
 * @brief Abstract Class Representing Rocket State 
 */
class State { 
    public: 
        virtual ~State();                      //Deconstructor
        virtual void enter() = 0;              //Use to initialize variables (like setup in arduino)
        virtual void update() = 0;             //Where most code will be (like loop arduino)
        virtual void exit() = 0;               //Shut things off / free memory

        static void setState(State* newState); //This is where state transitions will be called 

        static State* current;  // Keeps track of the current state
        static State* PreLaunch;
        static State* Launch;
        static State* Coast;
        static State* DrogueDescent;
        static State* MainDescent;
        static State* Recovery;
        static State* Abort;
        //Utility::TelemPacket telemPacket;  
    protected: 
        State();                                     //Constructor    
        long long currentTime = 0;
        long long deltaTime = 0;
        long long startTime = 0;

    private: 
        virtual void enter_impl() = 0;              //Entering state (initializing variables)
        virtual void update_impl() = 0;             //Operating in state (most of code goes )
        virtual void exit_impl() = 0;               //Leave a state (free memory)

};

// Definition of static members outside the class
State* State::current = nullptr;
State* State::PreLaunch = nullptr;
State* State::Launch = nullptr;
State* State::Coast = nullptr;
State* State::DrogueDescent = nullptr;
State* State::MainDescent = nullptr;
State* State::Recovery = nullptr;
State* State::Abort = nullptr;

