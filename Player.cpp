#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
using namespace std;

Player::Player(int playerID, Territory* territories, int nbTerritories, Territory*** adjacencyMatrix, Map* map){ 
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
}

Player::Player(){
    this->playerID = new int(-1);
    this->territories = NULL;
}

Player::~Player(){
    delete this->playerID;
    this->playerID = NULL;

    delete this->territories;
    this->territories = NULL;

    delete this->ol;
    this->ol = NULL;

    delete this->nbOfTerritories;
    this->nbOfTerritories = NULL;
}

void Player::ownedTerritories(){
    cout << "Territories owned by Player " << this->getPlayerID() << endl;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*territories[i].getPosessor() == *this->playerID && *territories[i].getPosessor() != -1){
            cout << territories[i] << endl;  
        }     
    }
}

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

Territory* Player::toDefend(){
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

//Look what the players own, then the neighbors of those countries (2d matrix in map)
//check who is not owned by the player, then attack them

/*
1st for loop, if that row is owned by the player, if not, skip it
2nd for loop, check for posesor
*/
Territory* Player::toAttack(){
    for(int i = 0; i < *nbOfTerritories; i++){
        toAttArr[i].setPosessor(-1); 
    }
    int counter = 0;
    Territory* allTerritories = map->getCountries();

    cout << *map << endl;

    // for(int i = 0; i < *map->getNbTerritories(); i++){
    //     cout << "Current country: " << allTerritories[i];

    //      for(int j = 0; j < *map->getNbTerritories(); j++){
    //         if(j == i){
    //             continue;
    //         }

    //         if(adjacencyMatrix[i][j] == nullptr){
    //             continue;
    //         }

    //         // if(*allTerritories[j].getPosessor() == *this->playerID){
    //         //     continue;
    //         // }

    //         // toAttArr[counter] = allTerritories[j];
    //         // counter++;

    //         // if(allTerritories[j].getPosessor() != this->playerID){
    //         //     cout << *allTerritories[j].getTerritoryName() << endl;
    //         // }
    //         cout << *allTerritories[j].getTerritoryName() << ", " << *allTerritories[j].getPosessor() << endl;
    //     }
    // }
    // return toAttArr;
}

void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}

int Player::getPlayerID(){
    return *this->playerID;
}

OrdersList Player::getOrdersList(){
    return *this->ol;
}

std::ostream& operator<<(std::ostream &strm, const Player &p){
    return strm << "Player ID: " << *p.playerID << endl;
}