#include "PlayerStrategies.h"

//Human Class - TODO W/ DOM
HumanPlayerStrategy::HumanPlayerStrategy(){
    this->type = new string("Human");
}

HumanPlayerStrategy::~HumanPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void HumanPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck){

}

Territory* HumanPlayerStrategy::toAttack(){

}

Territory* HumanPlayerStrategy::toDeffend(){

}

//Cheater Class
CheaterPlayerStrategy::CheaterPlayerStrategy(){
    this->type = new string("Cheater");
}

CheaterPlayerStrategy::~CheaterPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void CheaterPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck){

}

Territory* CheaterPlayerStrategy::toAttack(){

}

Territory* CheaterPlayerStrategy::toDeffend(){
    
}

//Aggresive Class
AggressivePlayerStrategy::AggressivePlayerStrategy(){
    this->type = new string("Aggresive");
}

AggressivePlayerStrategy::~AggressivePlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void AggressivePlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck){

}

Territory* AggressivePlayerStrategy::toAttack(){

}

Territory* AggressivePlayerStrategy::toDeffend(){
    
}

//Benevolent Class
BenevolentPlayerStrategy::BenevolentPlayerStrategy(){
    this->type = new string("Benevolent");
}

BenevolentPlayerStrategy::~BenevolentPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void BenevolentPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck){

}

Territory* BenevolentPlayerStrategy::toAttack(){

}

Territory* BenevolentPlayerStrategy::toDeffend(){
    
}

//Neutral Class
NeutralPlayerStrategy::NeutralPlayerStrategy(){
    this->type = new string("Neutral");
}

NeutralPlayerStrategy::~NeutralPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void NeutralPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck){

}

Territory* NeutralPlayerStrategy::toAttack(){
  
}

Territory* NeutralPlayerStrategy::toDeffend(){

}

