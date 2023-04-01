#include "PlayerStrategies.h"
#include <algorithm>

HumanPlayerStrategy::HumanPlayerStrategy(){
    this->type = new string("Human");
}

HumanPlayerStrategy::~HumanPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void HumanPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, 
                                        Player* enemy, Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex){
    if(orderName == "Deploy"){
        Deploy *deploy = new Deploy();
        deploy->setPlayer(p);
        deploy->setTargetTerr(targetTerr);
        deploy->setArmies(nbOfArmies);
        p->getOrdersList()->addOrder(deploy, ordersIndex);
        ordersIndex++;
    }
    if(orderName == "Bomb"){
        Bomb *bomb = new Bomb();
        bomb->setTargetTerr(targetTerr);
        bomb->setSourceTerr(sourceTerr);
        bomb->setPlayer(p);
        p->getOrdersList()->addOrder(bomb, ordersIndex);
        ordersIndex++;
    }
    if(orderName == "Blockade"){
        Blockade *blockade = new Blockade();
        blockade->setPlayer(p);
        blockade->setTargetTerr(targetTerr);
        p->getOrdersList()->addOrder(blockade, ordersIndex);
        ordersIndex++;
    }
     if(orderName == "Negotiate"){
        Negotiate *negotiate = new Negotiate();
        negotiate->setTargetTerr(targetTerr);
        negotiate->setPlayer(p);
        negotiate->setEnemy(enemy);
        p->getOrdersList()->addOrder(negotiate, ordersIndex);
        ordersIndex++;
    }
    if(orderName == "Airlift"){
        Airlift *airlift = new Airlift();
        airlift->setTargetTerr(targetTerr);
        airlift->setSourceTerr(sourceTerr);
        airlift->setPlayer(p);
        airlift->setArmies(nbOfArmies);
        p->getOrdersList()->addOrder(airlift, ordersIndex);
        ordersIndex++;
    }
     if(orderName == "Advance"){
        Advance *advance = new Advance();
        advance->setEnemy(enemy);
        advance->setPlayer(thisPlayer);
        advance->setTargetTerr(targetTerr);
        advance->setSourceTerr(sourceTerr);
        advance->setArmies(nbOfArmies);
        advance->setDeck(deck);
        p->getOrdersList()->addOrder(advance, ordersIndex);
        ordersIndex++;
    }
}

Territory* HumanPlayerStrategy::toAttack(Player* p){
    for(int i = 0; i < *p->nbOfTerritories; i++){
        p->toAttArr[i].setPosessor(-1); 
    }
    int counter = 0;
    Territory* allTerritories = p->territories;

    for(int i = 0; i < *p->map->getNbTerritories(); i++){
        if(*allTerritories[i].getPosessor() != *p->getPlayerID()){
            continue;
        }
         for(int j = 0; j < *p->map->getNbTerritories(); j++){
            if(j == i){
                continue;
            }

            if(p->adjacencyMatrix[i][j] == nullptr){
                continue;
            }

            if(*allTerritories[j].getPosessor() == *p->getPlayerID()){
                continue;
            }

            for(int k = 0; k <= counter; k++){
                if(*p->toAttArr[k].getPosessor() == -1){
                    p->toAttArr[k] = allTerritories[j];
                    counter++;
                    break;
                }else if(*p->toAttArr[k].getTerritoryName() == *allTerritories[j].getTerritoryName()){
                    break;
                }
            }
        }
    }
    return p->toAttArr;
}

Territory* HumanPlayerStrategy::toDeffend(Player* p){
    for(int i = 0; i < *p->nbOfTerritories; i++){
        p->toDefArr[i].setPosessor(-1); 
    }
    int counter = 0;
    for(int i = 0; i < *p->nbOfTerritories; i++){
        if(*p->territories[i].getPosessor() == *p->getPlayerID()){
            p->toDefArr[counter] = p->territories[i];
            counter++;
        }     
    }
    return p->toDefArr;
}

//Aggresive Class
AggressivePlayerStrategy::AggressivePlayerStrategy(){
    this->type = new string("Aggresive");
}

AggressivePlayerStrategy::~AggressivePlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void AggressivePlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                                            Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex){
                                                
    if(orderName == "Deploy"){
        Deploy *deploy = new Deploy();
        deploy->setPlayer(p);
        deploy->setTargetTerr(targetTerr);
        deploy->setArmies(nbOfArmies);
        p->getOrdersList()->addOrder(deploy, ordersIndex);
        ordersIndex++;
    }  
    if(orderName == "Advance"){
        Advance *advance = new Advance();
        cout << "here advance" << endl;
        advance->setEnemy(enemy);
        advance->setPlayer(thisPlayer);
        advance->setTargetTerr(targetTerr);
        advance->setSourceTerr(sourceTerr);
        advance->setArmies(nbOfArmies);
        advance->setDeck(deck);
        p->getOrdersList()->addOrder(advance, ordersIndex);
        cout << "here" << endl;
        ordersIndex++;
    }    
}

Territory* AggressivePlayerStrategy::toAttack(Player* p){
    for(int i = 0; i < *p->nbOfTerritories; i++){
        p->toAttArr[i].setPosessor(-1); 
    }
    int counter = 0;
    Territory* allTerritories = p->territories;

    for(int i = 0; i < *p->map->getNbTerritories(); i++){
        if(*allTerritories[i].getPosessor() != *p->getPlayerID()){
            continue;
        }
         for(int j = 0; j < *p->map->getNbTerritories(); j++){
            if(j == i){
                continue;
            }

            if(p->adjacencyMatrix[i][j] == nullptr){
                continue;
            }

            if(*allTerritories[j].getPosessor() == *p->getPlayerID()){
                continue;
            }

            for(int k = 0; k <= counter; k++){
                if(*p->toAttArr[k].getPosessor() == -1){
                    p->toAttArr[k] = allTerritories[j];
                    counter++;
                    break;
                }else if(*p->toAttArr[k].getTerritoryName() == *allTerritories[j].getTerritoryName()){
                    break;
                }
            }
        }
    }
    return p->toAttArr;
}

Territory* AggressivePlayerStrategy::toDeffend(Player* p){
 for(int i = 0; i < *p->nbOfTerritories; i++){
        p->toDefArr[i].setPosessor(-1); 
    }
    int counter = 0;
    for(int i = 0; i < *p->nbOfTerritories; i++){
        if(*p->territories[i].getPosessor() == *p->getPlayerID()){
            p->toDefArr[counter] = p->territories[i];
            counter++;
        }     
    }
    Territory temp;  
   
    for(int i = 0; i < counter; i++){
        for(int j = i; j < counter; j++){
            if(*p->toDefArr[i].getNumberOfSoldiers() < *p->toDefArr[j].getNumberOfSoldiers()){
                temp = p->toDefArr[i];
                p->toDefArr[i] = p->toDefArr[j];
                p->toDefArr[j] = temp;
            }
        }   
    } 

    return p->toDefArr;   
}

//Cheater Class
CheaterPlayerStrategy::CheaterPlayerStrategy(){
    this->type = new string("Cheater");
}

CheaterPlayerStrategy::~CheaterPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void CheaterPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                                        Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex){

}

Territory* CheaterPlayerStrategy::toAttack(Player* p){
    return NULL;
}

Territory* CheaterPlayerStrategy::toDeffend(Player* p){
    return NULL;
}

//Benevolent Class
BenevolentPlayerStrategy::BenevolentPlayerStrategy(){
    this->type = new string("Benevolent");
}

BenevolentPlayerStrategy::~BenevolentPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void BenevolentPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                                            Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex){

}

Territory* BenevolentPlayerStrategy::toAttack(Player* p){
    return NULL;
}

Territory* BenevolentPlayerStrategy::toDeffend(Player* p){
    return NULL;
}

//Neutral Class
NeutralPlayerStrategy::NeutralPlayerStrategy(){
    this->type = new string("Neutral");
}

NeutralPlayerStrategy::~NeutralPlayerStrategy(){
    delete this->type;
    this->type = NULL;
}

void NeutralPlayerStrategy::issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                                        Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex){

}

Territory* NeutralPlayerStrategy::toAttack(Player* p){
    return NULL;
}

Territory* NeutralPlayerStrategy::toDeffend(Player* p){
    return NULL;
}

