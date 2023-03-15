// GameEngine.cpp
#include "GameEngine.h"
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "Player.h"

/*
This section is dedicated to Assignment 2 part 2
*/

// Runs the startup for the game

/*
If your reading this I'm probably butchering my explination, sorry about that.
TODO: Implement/Fix 4b), 4c) and 4d)


This function essentially deals with what our p1 driver programs were already doing, this
leads me to a few questions:
4.c), does a army count already exist somewhere?
 */
void GameEngine::startupPhase(int state)
{
    int numOfPlayers = 0; //will be used to keep track of the number of players
    MapLoader *validMap;
    Map *map;
    Territory* territories;
    Territory*** adjacencyMatrix;
    int nbTerritories;
    Player *p1, *p2, *p3, *p4, *p5, *p6;
    Deck *deckA = new Deck();

    if (state == 0)
        {
            //1.Use the MapLoader function to select a map
            MapLoader *validMap = new MapLoader("europe.map");
            Map *map = validMap->getMap();
        }
        else if (state == 1)
        {
            //2.Use validate map to validate the map
            map->validate(); 
            //This is tecnically part of 1. but it's placed here since it doesn't make sense to do this before validation
            Territory* territories = map->getCountries();
            Territory*** adjacencyMatrix = map->getAdjacencyMatrix();
            int nbTerritories = *validMap->getMap()->getNbTerritories();
            
        }
        else if (state == 2)
        {
            //3. Adds player
            if(numOfPlayers == 0){
                Player *p1 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
                numOfPlayers++;
            }else if (numOfPlayers == 1){
                Player *p2 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
                numOfPlayers++;
            }else if (numOfPlayers == 2){
                Player *p3 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
                numOfPlayers++;
            }else if (numOfPlayers == 3){
                Player *p4 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
                numOfPlayers++;
            }else if (numOfPlayers == 4){
                Player *p5 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
            numOfPlayers++;
            }else if (numOfPlayers == 5){
                Player *p6 = new Player(numOfPlayers+1, territories, nbTerritories, adjacencyMatrix, map); 
                numOfPlayers++;
            }
        }
        else if (state == 3)
        {
            //4.a) fairly distribute all the territories to the players
            if(numOfPlayers == 2){
                // Set p1 territories
                for(int i = 0; i < nbTerritories/2; i++){
                    territories[i].setPosessor(p1->getPlayerID());
                }
                // Set p2 territories
                for(int i = nbTerritories/2; i < nbTerritories; i++){
                    territories[i].setPosessor(p2->getPlayerID());
                }
            }else if (numOfPlayers == 3){
                // Set p1 territories
                for(int i = 0; i < nbTerritories/3; i++){
                    territories[i].setPosessor(p1->getPlayerID());
                }
                // Set p2 territories
                for(int i = nbTerritories/3; i < nbTerritories*(2/3); i++){
                    territories[i].setPosessor(p2->getPlayerID());
                }
                // Set p3 territories
                for(int i = nbTerritories*(2/3); i < nbTerritories; i++){
                    territories[i].setPosessor(p3->getPlayerID());
                }
            }else if (numOfPlayers == 4){
                // Set p1 territories
                for(int i = 0; i < nbTerritories/4; i++){
                    territories[i].setPosessor(p1->getPlayerID());
                }
                // Set p2 territories
                for(int i = nbTerritories/4; i < nbTerritories/2; i++){
                    territories[i].setPosessor(p2->getPlayerID());
                }
                // Set p3 territories
                for(int i = nbTerritories/2; i < nbTerritories*(3/4); i++){
                    territories[i].setPosessor(p3->getPlayerID());
                }
                // Set p4 territories
                for(int i = nbTerritories*(3/4); i < nbTerritories; i++){
                    territories[i].setPosessor(p4->getPlayerID());
                }
            }else if (numOfPlayers == 5){
                // Set p1 territories
                for(int i = 0; i < nbTerritories/5; i++){
                    territories[i].setPosessor(p1->getPlayerID());
                }
                // Set p2 territories
                for(int i = nbTerritories/5; i < nbTerritories*(2/5); i++){
                    territories[i].setPosessor(p2->getPlayerID());
                }
                // Set p3 territories
                for(int i = nbTerritories*(2/5); i < nbTerritories*(3/5); i++){
                    territories[i].setPosessor(p3->getPlayerID());
                }
                // Set p4 territories
                for(int i = nbTerritories*(3/5); i < nbTerritories*(4/5); i++){
                    territories[i].setPosessor(p4->getPlayerID());
                }
                // Set p5 territories
                for(int i = nbTerritories*(4/5); i < nbTerritories; i++){
                    territories[i].setPosessor(p5->getPlayerID());
                }
            }else if (numOfPlayers == 6){
                // Set p1 territories
                for(int i = 0; i < nbTerritories/6; i++){
                    territories[i].setPosessor(p1->getPlayerID());
                }
                // Set p2 territories
                for(int i = nbTerritories/6; i < nbTerritories*(1/3); i++){
                    territories[i].setPosessor(p2->getPlayerID());
                }
                // Set p3 territories
                for(int i = nbTerritories*(1/3); i < nbTerritories/2; i++){
                    territories[i].setPosessor(p3->getPlayerID());
                }
                // Set p4 territories
                for(int i = nbTerritories/2; i < nbTerritories*(2/3); i++){
                    territories[i].setPosessor(p4->getPlayerID());
                }
                // Set p5 territories
                for(int i = nbTerritories*(2/3); i < nbTerritories*(5/6); i++){
                    territories[i].setPosessor(p5->getPlayerID());
                }
                // Set p6 territories
                for(int i = nbTerritories*(5/6); i < nbTerritories; i++){
                    territories[i].setPosessor(p6->getPlayerID());
                }
            }
            

        }else if (state == 4){
            //b) determine randomly the order of play of the players in the game
            int min = 1, max = numOfPlayers;

            //gives the player their turn order
            for(int i = min; i <= numOfPlayers; i++)
            {
                //write this out >:)
            } 

            //c) give 50 initial armies to the players, which are placed in their respective reinforcement pool
            //this one is really easy to implement, I'm just not if the reinforcement pool exists
            //

            //loop through numOfPlayers and assign them 50 troops

            //d) let each player draw 2 initial cards from the deck using the deck’s draw() method
            //fill the deck with cards to draw from
            for (int i = (0); i < 10; i++){
                if (i < 2){
                    deckA->setDeck(i, Type::airlift);
                } else if (i < 4) {
                    deckA->setDeck(i, Type::blockade);
                } else if (i < 6) {
                    deckA->setDeck(i, Type::bomb);
                } else if (i < 8) {
                    deckA->setDeck(i, Type::diplomacy);
                } else {
                    deckA->setDeck(i, Type::reinforcement);
                }
            }
            //draws cards for the hand
            for (int i = 0; i < 2; i++)
               {
                //struggling to figure out how to properly call the players hand
                Card abc = deckA->draw();
                //p1->setCards(); //doesn't work due to setCards() being a of class Hand, this is a easy fix by calling a specific card in their hand
                //handA->hand[i] = deckA->draw();
                }

            //e) switch the game to the play phase //explain this better!
            //This happens automatically, the reason is that it's already implemented into the game engine system
        }

}

/*
This section is for all the constructors used for each class
*/

// Constructor for game engine
GameEngine::GameEngine()
{
    current_state = new int(0); // default: every user starts at current state 0 aka. "Start"
}

// Destructor for game engine
GameEngine::~GameEngine()
{
    delete current_state;
    current_state = nullptr;
}

// Copy constructor for game engine
GameEngine::GameEngine(const GameEngine &copy)
{
    current_state = new int(*(copy.current_state));
}

// Constructor for start state
StartState::StartState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for start state
StartState::StartState(const StartState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for start state
StartState::~StartState()
{
    delete engine;
    engine = nullptr;
}

// Constructor for Map loaded state
MapLoadedState::MapLoadedState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for map loaded state
MapLoadedState::MapLoadedState(const MapLoadedState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for map loaded state
MapLoadedState::~MapLoadedState()
{
    delete engine;
    engine = nullptr;
}

// Constructor for map validated state
MapValidatedState::MapValidatedState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for map validated state
MapValidatedState::MapValidatedState(const MapValidatedState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for map validated state
MapValidatedState::~MapValidatedState()
{
    delete engine;
    engine = nullptr;
}

// Constructor for players added state
PlayersAddedState::PlayersAddedState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for players added state
PlayersAddedState::PlayersAddedState(const PlayersAddedState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for players added state
PlayersAddedState::~PlayersAddedState()
{
    delete engine;
    engine = nullptr;
}

// Constructor assign reinforcement state
AssignReinforcementState::AssignReinforcementState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy consturctor for assign reinforcement state
AssignReinforcementState::AssignReinforcementState(const AssignReinforcementState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for assingn reinforcement state
AssignReinforcementState::~AssignReinforcementState()
{
    delete engine;
    engine = nullptr;
}

// Constructor for issue order state
IssueOrderState::IssueOrderState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for issue order state
IssueOrderState::IssueOrderState(const IssueOrderState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for issue order state
IssueOrderState::~IssueOrderState()
{
    delete engine;
    engine = nullptr;
}

// Constructor for execute order state
ExecuteOrderState::ExecuteOrderState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for execute order state
ExecuteOrderState::ExecuteOrderState(const ExecuteOrderState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for execute order state
ExecuteOrderState::~ExecuteOrderState()
{
    delete engine;
    engine = nullptr;
}

// Construct for win state
WinState::WinState(GameEngine *engine)
{
    this->engine = engine;
}

// Copy constructor for win state
WinState::WinState(const WinState &copy)
{
    this->engine = new GameEngine(*copy.engine);
}

// Destructor for win state
WinState::~WinState()
{
    delete engine;
    engine = nullptr;
}

// Play method: this method runs a continuous loop and plays the game
void GameEngine::Play()
{
    // create the states
    GameEngine *Engine = new GameEngine();
    StartState *start_state = new StartState(Engine);
    MapLoadedState *map_loaded_state = new MapLoadedState(Engine);
    MapValidatedState *map_validated_state = new MapValidatedState(Engine);
    PlayersAddedState *players_added_state = new PlayersAddedState(Engine);
    AssignReinforcementState *assign_reinforcement_state = new AssignReinforcementState(Engine);
    IssueOrderState *issue_order_state = new IssueOrderState(Engine);
    ExecuteOrderState *execute_order_state = new ExecuteOrderState(Engine);
    WinState *win_state = new WinState(Engine);

    // loop that keeps the game running, ends when the state is 8 aka. "End"
    while (*Engine->getState() != 8)
    {
        Engine->Commands();
        std::cout << "Your move: ";
        std::string input;
        std::cin >> input;
        if (*Engine->getState() == 0)
        {
            start_state->StartInput(input);
        }
        else if (*Engine->getState() == 1)
        {
            map_loaded_state->MapLoadedInput(input);
        }
        else if (*Engine->getState() == 2)
        {
            map_validated_state->ValidateInput(input);
        }
        else if (*Engine->getState() == 3)
        {
            players_added_state->PlayersAddedInput(input);
        }
        else if (*Engine->getState() == 4)
        {
            assign_reinforcement_state->AssignReinforcementsInput(input);
        }
        else if (*Engine->getState() == 5)
        {
            issue_order_state->IssueOrderInput(input);
        }
        else if (*Engine->getState() == 6)
        {
            execute_order_state->ExecuteOrderInput(input);
        }
        else if (*Engine->getState() == 7)
        {
            win_state->WinInput(input);
        }
    }

    Engine->~GameEngine();
    start_state->~StartState();
    map_loaded_state->~MapLoadedState();
    map_validated_state->~MapValidatedState();
    players_added_state->~PlayersAddedState();
    assign_reinforcement_state->~AssignReinforcementState();
    issue_order_state->~IssueOrderState();
    execute_order_state->~ExecuteOrderState();
    win_state->~WinState();
}

// Getter for the private attribute state
int *GameEngine::getState()
{
    return this->current_state;
}

/*
    This section downwards is for transition functions only
    It is comprised of the base command function that is called by all functions.
    and each states transition function that is used to transition from state to state.
*/

// Function that will change the state of the game
void GameEngine::TransitionTo(int state)
{
    current_state = new int(state);
}

//  shows valid game engine commands for each state
void GameEngine::Commands()
{
    std::cout << "Valid commands: ";
    if (*current_state == 0)
    {
        std::cout << "\n1. loadmap" << std::endl;
    }
    else if (*current_state == 1)
    {
        std::cout << "\n1. loadmap" << std::endl;
        std::cout << "2. validatemap" << std::endl;
    }
    else if (*current_state == 2)
    {
        std::cout << "\n1. addplayer" << std::endl;
    }
    else if (*current_state == 3)
    {
        std::cout << "\n1. addplayer" << std::endl;
        std::cout << "2. assigncountries" << std::endl;
    }
    else if (*current_state == 4)
    {
        std::cout << "\n1. issueorder" << std::endl;
    }
    else if (*current_state == 5)
    {
        std::cout << "\n1. issueorder" << std::endl;
        std::cout << "2. endissueorders" << std::endl;
    }
    else if (*current_state == 6)
    {
        std::cout << "\n1. win" << std::endl;
        std::cout << "2. execorder" << std::endl;
        std::cout << "3. endexecorders" << std::endl;
    }
    else if (*current_state == 7)
    {
        std::cout << "\n1. end" << std::endl;
        std::cout << "2. play" << std::endl;
    }
}

// Checks for the input in start state
void StartState::StartInput(const std::string &input)
{
    if (input == "loadmap")
    {
        engine->startupPhase(0);
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(1);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        StartInput(temp);
    }
}

// Checks for the input in Map load state
void MapLoadedState::MapLoadedInput(const std::string &input)
{
    if (input == "validatemap")
    {
        engine->startupPhase(1);
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(2);
    }
    else if (input == "loadmap")
    {
        std::cout << "\nMap loaded\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        MapLoadedInput(temp);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        MapLoadedInput(temp);
    }
}

// Checks for the input in Map validate state
void MapValidatedState::ValidateInput(const std::string &input)
{
    if (input == "addplayer")
    {
        engine->startupPhase(2);
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(3);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        ValidateInput(temp);
    }
}

// Checks for the input in Player Added state
void PlayersAddedState::PlayersAddedInput(const std::string &input)
{
    if (input == "assigncountries")
    {
        engine->startupPhase(3);
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(4);
    }
    else if (input == "addplayer")
    {
        engine->startupPhase(2);
        std::cout << "\nPlayer added\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        PlayersAddedInput(temp);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        PlayersAddedInput(temp);
    }
}

void AssignReinforcementState::AssignReinforcementsInput(const std::string &input)
{
    if (input == "issueorder")
    {
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(5);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        AssignReinforcementsInput(temp);
    }
}

void IssueOrderState::IssueOrderInput(const std::string &input)
{
    if (input == "endissueorders")
    {
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(6);
    }
    else if (input == "issueorder")
    {
        std::cout << "\nOrder issued\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        IssueOrderInput(temp);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        IssueOrderInput(temp);
    }
}

void ExecuteOrderState::ExecuteOrderInput(const std::string &input)
{
    if (input == "win")
    {
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(7);
    }
    else if (input == "execorder")
    {
        std::cout << "\nOrder executed\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        ExecuteOrderInput(temp);
    }
    else if (input == "endexecorders")
    {
        std::cout << "\nSuccess! Returning to Assignment of reinforcements.\n"
                  << std::endl;
        engine->TransitionTo(4);
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        ExecuteOrderInput(temp);
    }
}

// TODO: finish the win input
void WinState::WinInput(const std::string &input)
{
    if (input == "end")
    {
        engine->TransitionTo(8);
        std::cout << "\nThank you for playing!" << std::endl;
        exit(0);
    }
    else if (input == "play")
    {
        engine->TransitionTo(0);
        std::cout << "\n Back to the start." << std::endl;
    }
    else
    {
        std::cout << "\nInvalid command\n"
                  << std::endl;
        engine->Commands();
        std::cout << "Your move: ";
        std::string temp;
        std::cin >> temp;
        WinInput(temp);
    }
}
