#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
using namespace std;

// Author: Alessio and Nicholas 

// Player::Player(int playerID, Territory* territories, Order* orders, int nbTerritories){ 
//     this->nbOfTerritories = new int(nbTerritories);
//     this->playerID = new int(playerID);
//     this->territories = territories;
//     this->orders = orders;
// }

Player::Player(int playerID, Territory* territories, OrdersList* ol, int nbTerritories){ 
    this->nbOfTerritories = new int(nbTerritories);
    this->playerID = new int(playerID);
    this->territories = territories;

    // this->orders = orders;
    this->ol = ol;
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

    // delete this->orders;
    // this->orders = NULL;

    delete this->ol;
    this->ol = NULL;

    delete this->nbOfTerritories;
    this->nbOfTerritories = NULL;
}

void Player::ownedTerritories(){
    cout << "Territories owned by Player " << this->getPlayerID() << endl;
    for(int i = 0; i < *nbOfTerritories; i++){
        if(*territories[i].getPosessor() == *this->playerID){
            cout << "Possesor ID: " << *territories[i].getPosessor() << ", Territory name: ";
            cout << *territories[i].getTerritoryName() << endl;   
        }     
    }
}

void Player::issueOrder(){
    // Create an order
    // Add it to my array
    int choice;
    cout << "What order would you like to create: " << endl;
    cout << "1. Deploy\n2. Bomb\n3. Blockade\n4. Negotiate\n5. Airlift\n6. Advance\nChoice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Deploy" << endl;
        Order *deploy = new Deploy();
        this->ol->addOrder(deploy, 0);
        // 
        break;
    // case 2:
    //     cout << "Bomb" << endl;
    //     break;
    // case 3:
    //     cout << "Blockade" << endl;
    //     break;
    // case 4:
    //     cout << "Negotiate" << endl;
    //     break;
    // case 5:
    //     cout << "Airlift" << endl;
    //     break;
    // case 6:
    //     cout << "Advance" << endl;
    //     break;
    // default:
    //     cout << "Bad choice... Exiting the function" << endl;  
    }        
}

// Territory* Player::toDefend(){
//     int counter = 0;
//     for(int i = 0; i < *nbOfTerritories; i++){
//         if(*territories[i].getPosessor() == *this->playerID){
//             counter++;  
//         }     
//     }
// }

// Territory* Player::toAttack(){
//     for(int i = 0; i < *nbOfTerritories; i++){
//         if(*territories[i].getPosessor() != *this->playerID){
//             cout << "Possesor ID: " << *territories[i].getPosessor() << ", Territory name: ";
//             cout << *territories[i].getTerritoryName() << endl;  
//         }     
//     }
// }

int Player::getPlayerID(){
    return *this->playerID;
}

void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}

std::ostream& operator<<(std::ostream &strm, const Player &p){
    return strm << "Player ID: " << *p.playerID << endl;
}