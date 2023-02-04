#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
using namespace std;

// Author: Alessio and Nicholas

Player::Player(int playerID, Territory* territories){ 
// I've already made a pointer to an array
// and im passing it, so just point to the reference
    this->playerID = new int(playerID);
    this->territories = territories;
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
}

void Player::allTerritories(){
    for(int i = 0; i < 24; i++){
        cout << "Possesor ID: " << *territories[i].getPosessor() << ", Territory name: ";
        cout << *territories[i].getTerritoryName() << endl;        
    }
}

Territory* Player::toDefend(){
    for(int i = 0; i < 24; i++){
        if(*territories[i].getPosessor() == *this->playerID){
            cout << "Possesor ID: " << *territories[i].getPosessor() << ", Territory name: ";
            cout << *territories[i].getTerritoryName() << endl;  
        }     
    }
}

// Make static variable with amount of territories and change the value 3
// to that static variable

Territory* Player::toAttack(){
    for(int i = 0; i < 24; i++){
        if(*territories[i].getPosessor() != *this->playerID){
            cout << "Possesor ID: " << *territories[i].getPosessor() << ", Territory name: ";
            cout << *territories[i].getTerritoryName() << endl;  
        }     
    }
}

int Player::getPlayerID(){
    return *this->playerID;
}

void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}