#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
using namespace std;

// Constructor of Player to initialize values
Player::Player(int playerID, Territory* territories, int nbTerritories, Territory*** adjacencyMatrix, Map* map, int reinforcementPool, int negotiateId, bool* gotCard){  
    this->nbOfTerritories = new int(nbTerritories);
    this->playerID = new int(playerID);
    this->territories = territories;

    int* size = new int(10);
    this->ol = new OrdersList(size);

    this->ordersIndex = new int(0);

    this->toDefArr = new Territory[*nbOfTerritories];
    this->toAttArr = new Territory[*nbOfTerritories]; 

    this->adjacencyMatrix = adjacencyMatrix;
    this->map = map;

    this->sizeOfHand = new int(0);
    this->cards = new Hand(*sizeOfHand);
    
    this->reinforcementPool = new int(reinforcementPool);
    this->negotiateId = 0;
    this->gotCard = new bool(false);
}

// Default Constructor
Player::Player(){
    this->playerID = new int(-1);
    this->territories = NULL;
    this->nbOfTerritories = new int(0);

    int* size = new int(10);
    this->ol = new OrdersList(size);

    this->ordersIndex = new int(0);

    this->toDefArr = new Territory[1];
    this->toAttArr = new Territory[1]; 

    this->adjacencyMatrix = NULL;
    this->map = NULL;

    this->cards = NULL;
    
    this->reinforcementPool = new int(0);
    this->negotiateId = 0;
    this->gotCard = new bool(false);
}

// Copy Constructor
Player::Player(const Player& p){
    this->playerID = new int(*p.playerID);
    this->territories = p.territories;
    this->nbOfTerritories = new int(*p.nbOfTerritories);
    this->ol = p.ol;
    this->ordersIndex = new int(*p.ordersIndex);
    this->toDefArr = p.toDefArr;
    this->toAttArr = p.toAttArr;
    this->adjacencyMatrix = p.adjacencyMatrix;
    this->map = p.map;
    this->cards = p.cards;
    this->reinforcementPool = new int(*p.reinforcementPool);
    this->negotiateId = 0;
    this->gotCard = new bool(p.gotCard);
}

// Destructor
Player::~Player(){
    delete this->playerID;
    this->playerID = NULL;

    delete this->territories;
    this->territories = NULL;

    delete this->ol;
    this->ol = NULL;

    delete this->nbOfTerritories;
    this->nbOfTerritories = NULL;

    delete this->ordersIndex;
    this->ordersIndex = NULL;

    delete this->toDefArr;
    this->toDefArr = NULL;

    delete this->toAttArr;
    this->toAttArr = NULL;

    delete this->adjacencyMatrix;
    this->adjacencyMatrix = NULL;

    delete this->map;
    this->map = NULL;

    delete this->cards;
    this->cards = NULL;

    delete this->reinforcementPool;
    this->reinforcementPool = NULL;

    
}

// Method to show owned Territories that the player owns
void Player::ownedTerritories(){
    cout << "Territories owned by Player " << this->getPlayerID() << endl;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*territories[i].getPosessor() == *this->playerID && *territories[i].getPosessor() != -1){
            cout << territories[i] << endl;  
        }     
    }
}

// Method that returns nb of territories owned
int Player::nbTerritories(){
    int counter = 0;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*territories[i].getPosessor() == *this->playerID && *territories[i].getPosessor() != -1){
            counter++;
        }     
    }
    return counter;
}

// Method to create orders and adds them to the OrdersList array that the Player owns
// Prints out the list of orders after creating it
void Player::issueOrder(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer){
    if(orderName == "Deploy"){
        Deploy *deploy = new Deploy();
        deploy->setPlayer(this);
        deploy->setTargetTerr(targetTerr);
        deploy->setArmies(nbOfArmies);
        this->ol->addOrder(deploy, *ordersIndex);
        (*ordersIndex)++;
    }else if(orderName == "Bomb"){
        Bomb *bomb = new Bomb();
        bomb->setTargetTerr(targetTerr);
        bomb->setSourceTerr(sourceTerr);
        bomb->setPlayer(this);
        this->ol->addOrder(bomb, *ordersIndex);
        (*ordersIndex)++;
    }else if(orderName == "Blockade"){
        Blockade *blockade = new Blockade();
        blockade->setPlayer(this);
        blockade->setTargetTerr(targetTerr);
        //DOM  PLEEAESE
        this->ol->addOrder(blockade, *ordersIndex);
        (*ordersIndex)++;
    }else if(orderName == "Negotiate"){
        Negotiate *negotiate = new Negotiate();
        negotiate->setTargetTerr(targetTerr);
        negotiate->setPlayer(this);
        negotiate->setEnemy(enemy);
        //DOM  PLEEAESE
        this->ol->addOrder(negotiate, *ordersIndex);
        (*ordersIndex)++;
    }else if(orderName == "Airlift"){
        Airlift *airlift = new Airlift();
        airlift->setTargetTerr(targetTerr);
        airlift->setSourceTerr(sourceTerr);
        airlift->setPlayer(this);
        airlift->setArmies(nbOfArmies);
        //DOM  PLEEAESE
        this->ol->addOrder(airlift, *ordersIndex);
        (*ordersIndex)++;
    }else if(orderName == "Advance"){
        Advance *advance = new Advance();
        advance->setEnemy(enemy);
        advance->setPlayer(thisPlayer);
        advance->setTargetTerr(targetTerr);
        advance->setSourceTerr(sourceTerr);
        advance->setArmies(nbOfArmies);
        //DOM  PLEEAESE
        this->ol->addOrder(advance, *ordersIndex);
        (*ordersIndex)++;
    }     
}

// Method that finds Territories to defend and adds them to a new array
Territory* Player::toDefend(){
    cout << "Territories to defend: " << endl;
    for(int i = 0; i < *nbOfTerritories; i++){
        toDefArr[i].setPosessor(-1); 
    }
    int counter = 0;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*territories[i].getPosessor() == *this->playerID){
            toDefArr[counter] = territories[i];
            counter++;
        }     
    }
    return toDefArr;
}

// Method that checks neighboring countries near owned territories that are not owned by the Player
// Returns an array of these neighboring countries 
Territory* Player::toAttack(){
    cout << "Territories to attack: " << endl;
    for(int i = 0; i < *nbOfTerritories; i++){
        toAttArr[i].setPosessor(-1); 
    }
    int counter = 0;
    Territory* allTerritories = map->getCountries();

    for(int i = 0; i < *map->getNbTerritories(); i++){
        if(*allTerritories[i].getPosessor() != *this->playerID){
            continue;
        }
         for(int j = 0; j < *map->getNbTerritories(); j++){
            if(j == i){
                continue;
            }

            if(adjacencyMatrix[i][j] == nullptr){
                continue;
            }

            if(*allTerritories[j].getPosessor() == *this->playerID){
                continue;
            }

            for(int k = 0; k <= counter; k++){
                if(*toAttArr[k].getPosessor() == -1){
                    toAttArr[k] = allTerritories[j];
                    counter++;
                    break;
                }else if(*toAttArr[k].getTerritoryName() == *allTerritories[j].getTerritoryName()){
                    break;
                }
            }
        }
    }
    return toAttArr;
}

// Print cards that the player owns
void Player::printCards(){
    cout << "Printing out hand of cards for Player " << *playerID << endl;
    for(int i = 0; i < *sizeOfHand; i++){
        cout << cards->hand[i] << endl;
    }
}

void Player::printToAttToDef(Territory* arrOfDefOrAtt){
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*arrOfDefOrAtt[i].getPosessor() == -1){
            break;
        }
        cout << arrOfDefOrAtt[i] << endl;
    }
}

int Player::nbOfTerToAttToDef(Territory* arrOfDefOrAtt){
    int counter = 0;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*arrOfDefOrAtt[i].getPosessor() == -1){
            break;
        }
        counter++;
    }
    return counter;
}

// Setters
void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}

void Player::setTerritories(Territory territories){
    *this->territories = territories;
}

void Player::setOl(OrdersList ol){
    *this->ol = ol;
}

void Player::setNbOfTerritories(int nbOfTerritories){
    *this->nbOfTerritories = nbOfTerritories;
}

void Player::setOrdersIndex(int ordersIndex){
    *this->ordersIndex = ordersIndex;
}

void Player::setToDefArr(Territory toDefArr){
    *this->toDefArr = toDefArr;
}

void Player::setToAttArr(Territory toAttArr){
    *this->toAttArr = toAttArr;
}

void Player::setAdjacencyMatrix(Territory** adjacencyMatrix){
    *this->adjacencyMatrix = adjacencyMatrix;
}

void Player::setMap(Map map){
    *this->map = map;
}

void Player::setCards(Hand cards){
    *this->cards = cards;
}

void Player::setReinforcementPool(int reinforcementPool){
    *this->reinforcementPool = reinforcementPool;
}

void Player::setNegotiateID(int negotiate){
    *this->negotiateId = negotiate;
}

void Player::setGotCard(bool gotCard){
    *this->gotCard = gotCard;
}

// Getters
int Player::getPlayerID(){
    return *this->playerID;
}

OrdersList* Player::getOrdersList(){
    return this->ol;
}

Hand Player::getCards(){
    return *this->cards;
}

int Player::getSizeOfHand(){
    return *this->sizeOfHand;
}

int Player::getReinforcementPool(){
    return *this->reinforcementPool;
}

int Player::getOrdersIndex(){
    return *this->ordersIndex;
}

int Player::getNegotiateID(){
    return *this->negotiateId;
}

bool Player::getGotCard(){
    return *this->gotCard;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream &strm, const Player &p){
    return strm << "Player ID: " << *p.playerID;
}

// Assignment operator
Player& Player::operator=(const Player& p){
    this->setPlayerID(*p.playerID);
    this->setTerritories(*p.territories);
    this->setOl(*p.ol);
    this->setNbOfTerritories(*p.nbOfTerritories);
    this->setOrdersIndex(*p.ordersIndex);
    this->setToDefArr(*p.toDefArr);
    this->setToAttArr(*p.toAttArr);
    this->setAdjacencyMatrix(*p.adjacencyMatrix);
    this->setMap(*p.map);
    this->setCards(*p.cards);
    this->setReinforcementPool(*p.reinforcementPool);

    return *this;
}