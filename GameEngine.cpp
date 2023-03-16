// GameEngine.cpp
#include "GameEngine.h"
#include "Player.h"
#include "Orders.h"
#include <cmath>

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



// Method to calculate the armies that a player can use to reinforce
void AssignReinforcementState::reinforcementPhase(Player *pArr[], int nbOfPlayers){
    //Ask Daniel about the "Owns all territories in continent" bonus
    for(int i = 0; i < nbOfPlayers; i++){
        int *nbOfTer = new int(pArr[i]->nbTerritories());
        int reinArm = floor(*nbOfTer/3);
        if(reinArm < 3){
            reinArm = 3;
        }
        pArr[i]->setReinforcementPool(reinArm);
        cout << *pArr[i] << " has " << pArr[i]->getReinforcementPool() << " armies" << endl;
    }
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

void IssueOrderState::issueOrdersPhase(Player *pArr[], int nbOfPlayers){
    // for(int i = 0; i < nbOfPlayers; i++){
    //     pArr[i]->setNegotiateID(0);
    // }

   for(int i = 0; i < nbOfPlayers; i++){
        Territory* toAtt = pArr[i]->toAttack();
        pArr[i]->printToAttToDef(toAtt);
        int nbOfToAtt = pArr[i]->nbOfTerToAttToDef(toAtt);
        

        Territory* toDef = pArr[i]->toDefend();
        pArr[i]->printToAttToDef(toDef);
        int nbOfToDef = pArr[i]->nbOfTerToAttToDef(toDef);
        
        int nbOfRein = pArr[i]->getReinforcementPool();

        string targetTerr, sourceTerr, cardOrder;
        int counterDep, toAttPossesor;
        int* nbOfArmies;
        Territory* target = new Territory;
        Territory* source = new Territory;
        Player* enemy;

        while(nbOfRein != 0){
            cout << "You have " << nbOfRein << " left to deploy" << endl;
            cout << "Enter the country you would like to deploy armies to: ";
            cin >> targetTerr;
            cout << "Enter the amount of armies to send: ";
            cin >> *nbOfArmies;
            if(nbOfRein - *nbOfArmies < 0){
                cout << "Please enter a valid amount of armies to deploy" << endl;
                nbOfArmies = 0;
            }
            
            pArr[i]->issueOrder("Deploy", nbOfArmies, target, nullptr, nullptr, nullptr);
            nbOfRein = nbOfRein - *nbOfArmies;
        }

        OrdersList* ol = pArr[i]->getOrdersList();
        int listSize = pArr[i]->getOrdersIndex();
        ol->showList(listSize);

        bool isAdvancing = true;
        int choice;
        do{
            cout << "Would you like to advance?\n1. Yes\n2. No\nChoice: ";
            cin >> choice;
            if(choice == 1){
                cout << "Territories to attack: " << endl;
                pArr[i]->printToAttToDef(toAtt);
                cout << "Territories to defend: " << endl;
                pArr[i]->printToAttToDef(toDef);

                cout << "Which territory would you like to take armies from: ";
                cin >> sourceTerr;
                cout << "Which territory would you like to advance to: ";
                cin >> targetTerr;
                cout << "How many armies would you like to move: ";
                cin >> *nbOfArmies;

                for(int j = 0; j < nbOfToDef; j++){
                    if(sourceTerr == *toDef[j].getTerritoryName()){
                        *source = toDef[j];
                    }
                    if(targetTerr == *toDef[j].getTerritoryName()){
                        *target = toDef[j];
                    }
                }

                for(int j = 0; j < nbOfToAtt; j++){
                    if(targetTerr == *toAtt[j].getTerritoryName()){
                        *target = toAtt[j];
                        toAttPossesor = *toAtt[j].getPosessor();
                        for(int k = 0; k < nbOfPlayers; k++){
                                if(toAttPossesor == pArr[k]->getPlayerID()){
                                    enemy = pArr[k];
                                }
                        }
                    }
                }
                pArr[i]->issueOrder("Advance", nbOfArmies, target, source, enemy, pArr[i]);
            }else if(choice == 2){
                isAdvancing = false;
            }
        }while(isAdvancing);

        bool validCardOrder = true;

        if(pArr[i]->getSizeOfHand() == 0){
            cout << "You have no cards to create a new order..." << endl;
        }else{
            do{
                cout << "Select a card in your hand to create an order: " << endl;
                pArr[i]->printCards();
                cout << "Choice: ";
                cin >> cardOrder;

                if(cardOrder == "Bomb"){
                    cout << "Which territory would you like to send a bomb from: ";
                    cin >> sourceTerr;
                    cout << "Which territory would you like to target: ";
                    cin >> targetTerr;

                    for(int j = 0; j < nbOfToDef; j++){
                        if(sourceTerr == *toDef[j].getTerritoryName()){
                            *source = toDef[j];
                            break;
                        }
                    }
                    for(int j = 0; j < nbOfToAtt; j++){
                        if(targetTerr == *toAtt[j].getTerritoryName()){
                            *target = toAtt[j];
                            break;
                        }
                    }
                    pArr[i]->issueOrder("Bomb", 0, target, source, nullptr, pArr[i]);
                    validCardOrder = false;
                }else if(cardOrder == "Blockade"){
                    cout << "Which territory would you like to blockade: ";
                    cin >> targetTerr;

                    for(int j = 0; j < nbOfToDef; j++){
                        if(sourceTerr == *toDef[j].getTerritoryName()){
                            *source = toDef[j];
                            break;
                        }
                    }
                    pArr[i]->issueOrder("Blockade", 0, target, nullptr, nullptr, pArr[i]);
                    validCardOrder = false;
                }else if(cardOrder == "Airlift"){
                    cout << "Which territory would you like to take armies from: ";
                    cin >> sourceTerr;
                    cout << "Which territory would you like to advance to: ";
                    cin >> targetTerr;
                    cout << "How many armies would you like to move: ";
                    cin >> *nbOfArmies;

                    for(int j = 0; j < nbOfToDef; j++){
                        if(sourceTerr == *toDef[j].getTerritoryName()){
                            *source = toDef[j];
                            break;
                        }
                    }
                    for(int j = 0; j < nbOfToDef; j++){
                        if(targetTerr == *toDef[j].getTerritoryName()){
                            *target = toDef[j];
                            break;
                        }
                    }

                    pArr[i]->issueOrder("Airlift", nbOfArmies, target, source, nullptr, pArr[i]);
                    validCardOrder = false;
                }else if(cardOrder == "Negotiate"){
                    cout << "Which territory would you like to negotiate with: ";
                    cin >> targetTerr;

                    for(int j = 0; j < nbOfToAtt; j++){
                        if(targetTerr == *toAtt[j].getTerritoryName()){
                            *target = toAtt[j];
                            toAttPossesor = *toAtt[j].getPosessor();
                            for(int k = 0; k < nbOfPlayers; k++){
                                    if(toAttPossesor == pArr[k]->getPlayerID()){
                                        enemy = pArr[k];
                                    }
                            }
                        }
                    }

                    pArr[i]->issueOrder("Negotiate", 0, target, nullptr, enemy, pArr[i]);
                    validCardOrder = false;
                }else{
                    cout << "Invalid order... Try again";
                }
            }while(validCardOrder);            
        }
   }
}

void ExecuteOrderState::executeOrderPhase(Player *pArr[], int nbOfPlayers){
    for(int i = 0; i < nbOfPlayers; i++){
        pArr[i]->getOrdersList()->execute();
    }
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


/*
Player1:
1- return list of toDefend and toAttack (create prio for countries to defend and attack)
2- we call a function to see # of armies that a player owns and calls the deploy order until player has no armies left
3- call the advance order to move armies on the board (either defend or attack)
4- cards (ffs)

Player2:
1- return list of toDefend and toAttack (create prio for countries to defend and attack)
2- we call a function to see # of armies that a player owns and calls the deploy order until player has no armies left
3- call the advance order to move armies on the board (either defend or attack)
4- cards (ffs)


mainGameLoop():
	while(noWinner):
		for(all the players{p1, p2}):
			p1.reinforcementPhase();
		for(all the players{p1, p2}):
			p1.isseOrdersPhase();
		for(all the players{p1, p2}):
			p1.ordersExecutionPhase();
*/