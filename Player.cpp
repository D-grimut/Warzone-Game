#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "Cards.h"
using namespace std;

// Constructor of Player to initialize values
Player::Player(int playerID, Territory* territories, int nbTerritories, Territory*** adjacencyMatrix, Map* map){ 
    this->nbOfTerritories = new int(nbTerritories);
    this->playerID = new int(playerID);
    this->territories = territories;

    int* size = new int(10);
    this->ol = new OrdersList(size);
    this->reinforcements = new int(0);

    this->ordersIndex = new int(0);

    this->toDefArr = new Territory[*nbOfTerritories];
    this->toAttArr = new Territory[*nbOfTerritories]; 

    this->adjacencyMatrix = adjacencyMatrix;
    this->map = map;

    this->sizeOfHand = new int(6);
    this->cards = new Hand(*sizeOfHand);
}

// Default Constructor
Player::Player(){
    this->playerID = new int(-1);
    this->territories = NULL;
    this->nbOfTerritories = new int(0);

    this->reinforcements = new int(0);

    int* size = new int(10);
    this->ol = new OrdersList(size);

    this->ordersIndex = new int(0);

    this->toDefArr = new Territory[1];
    this->toAttArr = new Territory[1]; 

    this->adjacencyMatrix = NULL;
    this->map = NULL;

    this->sizeOfHand = new int(5);
    this->cards = new Hand(5);  
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
    this->reinforcements = new int(*p.reinforcements);

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

// Method to create orders and adds them to the OrdersList array that the Player owns
// Prints out the list of orders after creating it
void Player::issueOrder(){
    int choice;
    cout << "What order would you like to create: " << endl;
    cout << "1. Deploy\n2. Bomb\n3. Blockade\n4. Negotiate\n5. Airlift\n6. Advance\nChoice: ";
    cin >> choice;

    switch (choice){
        case 1:
        {
            Order *deploy = new Deploy();
            this->ol->addOrder(deploy, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break; 
        }
        case 2:
        {
            Order *bomb = new Bomb();
            this->ol->addOrder(bomb, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break;
        }
        case 3:
        {
            Order *blockade = new Blockade();
            this->ol->addOrder(blockade, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break;
        }
        case 4:
        {
            Order *negotiate = new Negotiate();
            this->ol->addOrder(negotiate, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break;
        }
        case 5:
        {
            Order *airlift = new Airlift();
            this->ol->addOrder(airlift, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break;
        }
        case 6:
        {
            Order *advance = new Advance();
            this->ol->addOrder(advance, *ordersIndex);
            (*ordersIndex)++;
            ol->showList(*ordersIndex);
            break;
        }
        default:
            cout << "Bad choice... Exiting the function" << endl; 
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

// Setters
void Player::setReinforcements(int reinforcements){
    *this->reinforcements = reinforcements;
}

void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}

void Player::setTerritories(Territory* territories){
    this->territories = territories;
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

void Player::setAdjacencyMatrix(Territory*** adjacencyMatrix){
    this->adjacencyMatrix = adjacencyMatrix;
}

void Player::setMap(Map *map){
    this->map = map;
}

void Player::setCards(Hand cards){
    *this->cards = cards;
}

// Getters
int Player::getReinforcements(){
    return *this->reinforcements;
}

int Player::getPlayerID(){
    return *this->playerID;
}

OrdersList Player::getOrdersList(){
    return *this->ol;
}

Hand* Player::getCards(){
    return this->cards;
}

int Player::getSizeOfHand(){
    return *this->sizeOfHand;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream &strm, const Player &p){
    return strm << "Player ID: " << *p.playerID << endl;
}

// Assignment operator
Player& Player::operator=(const Player& p){
    this->setPlayerID(*p.playerID);
    this->setTerritories(p.territories);
    this->setOl(*p.ol);
    this->setNbOfTerritories(*p.nbOfTerritories);
    this->setOrdersIndex(*p.ordersIndex);
    this->setToDefArr(*p.toDefArr);
    this->setToAttArr(*p.toAttArr);
    this->setAdjacencyMatrix(p.adjacencyMatrix);
    this->setMap(p.map);
    this->setCards(*p.cards);

    return *this;
}
