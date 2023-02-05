// GameEngine.cpp
#include "GameEngine.h"

GameEngine::GameEngine()
{
    current_state = 0; // default: every user starts at current state 0 aka. "Start"
}

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

    // loop that keeps the game running, ends when the state is 5 aka. "end"
    while (Engine->getState() != 8)
    {
        Engine->Commands();
        std::cout << "Your move: ";
        std::string input;
        std::cin >> input;
        if (Engine->getState() == 0)
        {
            start_state->StartInput(input);
        }
        else if (Engine->getState() == 1)
        {
            map_loaded_state->MapLoadedInput(input);
        }
        else if (Engine->getState() == 2)
        {
            map_validated_state->ValidateInput(input);
        }
        else if (Engine->getState() == 3)
        {
            players_added_state->PlayersAddedInput(input);
        }
        else if (Engine->getState() == 4)
        {
            assign_reinforcement_state->AssignReinforcementsInput(input);
        }
        else if (Engine->getState() == 5)
        {
            issue_order_state->IssueOrderInput(input);
        }
        else if (Engine->getState() == 6)
        {
            execute_order_state->ExecuteOrderInput(input);
        }
        else if (Engine->getState() == 7)
        {
            win_state->WinInput(input);
        }
    }
}

int GameEngine::getState()
{
    return current_state;
}

/*
    This section downwards is for transition functions only
    It is comprised of the base command function that is called by all functions.
    and each states transition function that is used to transition from state to state.
*/

// Function that will change the state of the game
void GameEngine::TransitionTo(int state)
{
    current_state = state;
}

//  shows valid game engine commands for each state
void GameEngine::Commands()
{
    std::cout << "Valid commands: ";
    if (current_state == 0)
    {
        std::cout << "\n1. loadmap" << std::endl;
    }
    else if (current_state == 1)
    {
        std::cout << "\n1. loadmap" << std::endl;
        std::cout << "2. validatemap" << std::endl;
    }
    else if (current_state == 2)
    {
        std::cout << "\n1. addplayer" << std::endl;
    }
    else if (current_state == 3)
    {
        std::cout << "\n1. addplayer" << std::endl;
        std::cout << "2. assigncountries" << std::endl;
    }
    else if (current_state == 4)
    {
        std::cout << "\n1. issueorder" << std::endl;
    }
    else if (current_state == 5)
    {
        std::cout << "\n1. issueorder" << std::endl;
        std::cout << "2. endissueorders" << std::endl;
    }
    else if (current_state == 6)
    {
        std::cout << "\n1. win" << std::endl;
        std::cout << "2. execorder" << std::endl;
        std::cout << "3. endexecorders" << std::endl;
    }
    else if (current_state == 7)
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
        std::cout << "\nSuccess!\n"
                  << std::endl;
        engine->TransitionTo(4);
    }
    else if (input == "addplayer")
    {
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

// test main method
int main()
{
    GameEngine *g = new GameEngine();
    g->Play();
    return 0;
}
