#include "Territory.h"
#include <iostream>

//Author: Daniel 

//Constructor
Territory::Territory(int posessor, string TerritoryName, int TerritoryId, bool isFree, int continentId){

    this->posessor = new int(posessor);
    this->TerritoryName = new string(TerritoryName);
    this->TerritoryId = new int(TerritoryId);    
    this->isFree = new bool(isFree);
    this->continentId = new int(continentId);

    //These properties do not figure on the .map file so we comment them out for now
    //this->amntToInvade = new int(amntToInvade);
    //this->numberOfSoldiers = new int(numberOfSoldiers);
}

//Default Consructor
Territory::Territory(){
    this->posessor = new int(-1);
    this->TerritoryName = new string("");
    this->TerritoryId = new int(-1);    
    this->isFree = new bool(true);
    this->continentId = new int(-1);
}

//Destructor
Territory::~Territory(){
    delete this->posessor;
    delete this->TerritoryName;
    delete this->TerritoryId;    
    delete this->isFree;
    delete this->continentId;
    
    //delete this->amntToInvade;
    //delete this->numberOfSoldiers;
}

int* Territory:: getPosessor(){
    return this->posessor;    
}

int* Territory::getTerritoryId(){
    return this->TerritoryId;
}

int* Territory::getContinentId(){
    return this->continentId;
}

// int* Territory::getAmntToInvade(){
//     return this->amntToInvade;
// }

// int* Territory::getNumberOfSoldiers(){
//     return this->numberOfSoldiers;
// }

bool* Territory::getIsFree(){
    return this->isFree;
}

string* Territory::getTerritoryName(){
    return this->TerritoryName;
}

//Setters
void Territory::setPosessor(int id){
    *this->posessor = id;
}

void Territory::setTerritoryId(int id){
    *this->TerritoryId = id;
}

void Territory::setStatus(bool stat){
    *this->isFree = stat;
}

void Territory::setName(string name){
    *this->TerritoryName = name;
}

void Territory::setContinentId(int id){
    *this->continentId = id;
}