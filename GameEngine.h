#include <iostream>

class GameEngine
{
public:
    GameEngine();                 // default constructor
    void Run();                   // general run method
    void Commands();              // print the valid commands
    void TransitionTo(int state); // transition function

private:
    int current_state; // current state : int or string?
};

// start state
class StartState
{
public:
    StartState(GameEngine *engine)
        : engine_(engine) {}

    void StartInput(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// map loaded
class MapLoadedState
{
public:
    // constructor
    MapLoadedState(GameEngine *engine)
        : engine_(engine) {}

    void MapLoadedInput(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// map validate
class MapValidatedState
{
public:
    MapValidatedState(GameEngine *engine)
        : engine_(engine) {}

    void ValidateInput(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// players added state
class PlayersAddedState
{
public:
    PlayersAddedState(GameEngine *engine)
        : engine_(engine) {}

    void PlayersAddedInput(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// assign reinforcement
class AssignReinforcementState
{
public:
    AssignReinforcementState(GameEngine *engine)
        : engine_(engine) {}

    void Input(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// issue order
class IssueOrderState
{
public:
    IssueOrderState(GameEngine *engine)
        : engine_(engine) {}

    void Input(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// exec orders
class ExecuteOrderState
{
public:
    ExecuteOrderState(GameEngine *engine)
        : engine_(engine) {}

    void Input(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};

// win state
class WinState
{
public:
    WinState(GameEngine *engine)
        : engine_(engine) {}

    void WinInput(const std::string &input); // to change
    void Commands();

private:
    GameEngine *engine_;
};
