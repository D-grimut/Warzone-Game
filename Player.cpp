#include <iostream>
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
    for(int i = 0; i < 3; i++){
        cout << territories[i].getPosessor() << endl;
    }
}

Territory* Player::toDefend(){

}

void Player::setPlayerID(int playerID){
    *this->playerID = playerID;
}