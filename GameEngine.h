#include <iostream>

class GameEngine
{
public:
    GameEngine();                 // default constructor
    void Play();                  // general run method
    void Commands();              // print the valid commands
    void TransitionTo(int state); // transition function
    int *getState();

private:
    int *current_state; // current state : int or string?
};

// start state
class StartState
{
public:
    StartState(GameEngine *engine)
        : engine(engine) {}

    void StartInput(const std::string &input); // to change

private:
    GameEngine *engine;
};

// map loaded
class MapLoadedState
{
public:
    // constructor
    MapLoadedState(GameEngine *engine)
        : engine(engine) {}

    void MapLoadedInput(const std::string &input);

private:
    GameEngine *engine;
};

// map validate
class MapValidatedState
{
public:
    MapValidatedState(GameEngine *engine)
        : engine(engine) {}

    void ValidateInput(const std::string &input);

private:
    GameEngine *engine;
};

// players added state
class PlayersAddedState
{
public:
    PlayersAddedState(GameEngine *engine)
        : engine(engine) {}

    void PlayersAddedInput(const std::string &input);

private:
    GameEngine *engine;
};

// assign reinforcement
class AssignReinforcementState
{
public:
    AssignReinforcementState(GameEngine *engine)
        : engine(engine) {}

    void AssignReinforcementsInput(const std::string &input);

private:
    GameEngine *engine;
};

// issue order
class IssueOrderState
{
public:
    IssueOrderState(GameEngine *engine)
        : engine(engine) {}

    void IssueOrderInput(const std::string &input);

private:
    GameEngine *engine;
};

// exec orders
class ExecuteOrderState
{
public:
    ExecuteOrderState(GameEngine *engine)
        : engine(engine) {}

    void ExecuteOrderInput(const std::string &input);

private:
    GameEngine *engine;
};

// win state
class WinState
{
public:
    WinState(GameEngine *engine)
        : engine(engine) {}

    void WinInput(const std::string &input);

private:
    GameEngine *engine;
};
