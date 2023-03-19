#include <iostream>
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "Player.h"

class GameEngine
{
public:
    GameEngine();                       // default constructor
    ~GameEngine();                      // destructor
    GameEngine(const GameEngine &copy); // copy constructor
    void Play();                        // general run method
    void Commands();                    // print the valid commands
    void TransitionTo(int state);       // transition function
    int *getState();                    // getter
    void startupPhase(int state);
    int *numOfPlayers; //will be used to keep track of the number of players
    bool *startupSuccess; // makes sure the startup works correctly

private:   
    int *p1Order, *p2Order, *p3Order, *p4Order, *p5Order, *p6Order;
    MapLoader *validMap;
    Map *map;
    Territory* territories;
    Territory*** adjacencyMatrix;
    int *nbTerritories;
    Player *p1, *p2, *p3, *p4, *p5, *p6;
    Deck *deckA;
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
    void StartInput(const std::string &input);

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
    void MapLoadedInput(const std::string &input);

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
    void ValidateInput(const std::string &input);

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
    void PlayersAddedInput(const std::string &input);

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
    void AssignReinforcementsInput(const std::string &input);

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
    void IssueOrderInput(const std::string &input);

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
    void ExecuteOrderInput(const std::string &input);

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
    void WinInput(const std::string &input);

private:
    GameEngine *engine;
};
