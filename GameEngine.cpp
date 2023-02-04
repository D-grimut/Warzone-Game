// GameEngine.cpp
#include "GameEngine.h"

GameEngine::GameEngine()
{
    current_state = 0; // default: every user starts at current state 0 aka. "Start"
}

void GameEngine::Run()
{
    // create the states
    GameEngine *Engine = new GameEngine();
    StartState *start_state = new StartState(Engine);
    MapLoadedState *map_loaded_state = new MapLoadedState(Engine);
    MapValidatedState *map_validated_state = new MapValidatedState(Engine);
    PlayersAddedState *players_added_state = new PlayersAddedState(Engine);
    WinState *win_state = new WinState(Engine);

    // loop that keeps the game running, ends when the state is 5 aka. "end"
    while (current_state != 5)
    {
        std::cout << "Your move: ";
        std::string input;
        std::cin >> input;
        if (current_state == 0)
        {
            start_state->StartInput(input);
        }
        else if (current_state == 1)
        {
            map_loaded_state->MapLoadedInput(input);
        }
        else if (current_state == 2)
        {
            map_validated_state->ValidateInput(input);
        }
        else if (current_state == 3)
        {
            players_added_state->PlayersAddedInput(input);
        }
        else if (current_state == 4)
        {
            win_state->WinInput(input);
        }
    }
}

/*
    This section downwards is for transition functions only
    It is comprised of the base command function that is called by all functions.
    and each states transition function that is used to transition from state to state.
*/

//  shows valid game engine commands for each state
void GameEngine::Commands()
{
    std::cout << "Valid commands: ";
    if (current_state == 0)
    {
        // example case
        std::cout << "1. maploaded" << std::endl;
        std::cout << "2. validatemap" << std::endl;
    }
    else if (current_state == 1)
    {
        std::cout << "Input" << std::endl; // to change
    }
    else if (current_state == 2)
    {
        std::cout << "Input" << std::endl; // to change
    }
    else if (current_state == 3)
    {
        std::cout << "Input" << std::endl; // to change
    }
    else if (current_state == 4)
    {
        std::cout << "Input" << std::endl; // to change
    }
}

// Function that will change the state of the game
void GameEngine::TransitionTo(int state)
{
    current_state = state;
}

// Checks for the input in start state
void StartState::StartInput(const std::string &input)
{
    if (input == "Input") // to change
    {
        engine_->TransitionTo(1);
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
        // call function recursively??
    }
    Commands();
}

// command call
void StartState::Commands()
{
    engine_->Commands();
}

// Checks for the input in Map load state
void MapLoadedState::MapLoadedInput(const std::string &input)
{
    if (input == "validatemap")
    {
        engine_->TransitionTo(2);
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
        // call funciton recursively??
    }
    Commands();
}

// map load commands
void MapLoadedState::Commands()
{
    engine_->Commands();
}

// Checks for the input in Map validate state
void MapValidatedState::ValidateInput(const std::string &input)
{
    if (input == "players added")
    {
        engine_->TransitionTo(3);
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
        // call funciton recursively??
    }
    Commands();
}

// map validate commands
void MapValidatedState::Commands()
{
    engine_->Commands();
}

// Checks for the input in Player Added state
void PlayersAddedState::PlayersAddedInput(const std::string &input)
{
    if (input == "win")
    {
        engine_->TransitionTo(4);
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
        // Checks for the input in Map load state
    }
    Commands();
}

// Player added commands
void PlayersAddedState::Commands()
{
    engine_->Commands();
}

// TODO: finish the win input
void WinState::WinInput(const std::string &input)
{
    // do something
}

// win state commands
void WinState::Commands()
{
    engine_->Commands();
}

// test main method
// int main()
// {
//     std::cout << "hello world" << std::endl;
//     return 0;
// }
