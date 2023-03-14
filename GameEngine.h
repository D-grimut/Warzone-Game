#pragma once
#include <iostream>
#include "LoggingObserver.h"
#include "CommandProcessing.h"

class CommandProcessor;

class GameEngine: public ILoggable, Subject
{
public:
    GameEngine();                       // default constructor
    ~GameEngine();                      // destructor
    GameEngine(const GameEngine &copy); // copy constructor
    void Play();                        // general run method
    void Commands();                    // print the valid commands
    void TransitionTo(int state);       // transition function
    int *getState();                    // getter

    string stringToLog();
    
    CommandProcessor *cp;

private:
    int *current_state; // current state : int or string?
};

/*
Starting now, all of the classes will be seperate states. Each state will have
-A constructor with parameter
-A copy constructor
-A destructor
-An input method
-A private attribute for engine
*/

// start state
class StartState
{
public:
    StartState(GameEngine *engine);
    ~StartState();
    StartState(const StartState &copy);
    bool StartInput(const std::string &input);

private:
    GameEngine *engine;
};

// map loaded state
class MapLoadedState
{
public:
    // constructor
    MapLoadedState(GameEngine *engine);
    ~MapLoadedState();
    MapLoadedState(const MapLoadedState &copy);
    bool MapLoadedInput(const std::string &input);

private:
    GameEngine *engine;
};

// map validate state
class MapValidatedState
{
public:
    MapValidatedState(GameEngine *engine);
    ~MapValidatedState();
    MapValidatedState(const MapValidatedState &copy);
    bool ValidateInput(const std::string &input);

private:
    GameEngine *engine;
};

// players added state
class PlayersAddedState
{
public:
    PlayersAddedState(GameEngine *engine);
    ~PlayersAddedState();
    PlayersAddedState(const PlayersAddedState &copy);
    bool PlayersAddedInput(const std::string &input);

private:
    GameEngine *engine;
};

// assign reinforcement state
class AssignReinforcementState
{
public:
    AssignReinforcementState(GameEngine *engine);
    ~AssignReinforcementState();
    AssignReinforcementState(const AssignReinforcementState &copy);
    bool AssignReinforcementsInput(const std::string &input);

private:
    GameEngine *engine;
};

// issue order state
class IssueOrderState
{
public:
    IssueOrderState(GameEngine *engine);
    ~IssueOrderState();
    IssueOrderState(const IssueOrderState &copy);
    bool IssueOrderInput(const std::string &input);

private:
    GameEngine *engine;
};

// exec orders state
class ExecuteOrderState
{
public:
    ExecuteOrderState(GameEngine *engine);
    ~ExecuteOrderState();
    ExecuteOrderState(const ExecuteOrderState &copy);
    bool ExecuteOrderInput(const std::string &input);

private:
    GameEngine *engine;
};

// win state
class WinState
{
public:
    WinState(GameEngine *engine);
    ~WinState();
    WinState(const WinState &copy);
    bool WinInput(const std::string &input);

private:
    GameEngine *engine;
};
