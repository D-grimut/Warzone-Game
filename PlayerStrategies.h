#pragma once
#include <stdio.h>
#include <string>
#include "Map.h"
using namespace std;

class Territory;
class Player;
class Deck;

class PlayerStrategy{
public:
    virtual Territory* toAttack() = 0;
    virtual Territory* toDeffend() = 0;
    virtual void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) = 0;
};

//Human
class HumanPlayerStrategy: PlayerStrategy{
public:
    HumanPlayerStrategy();
    ~HumanPlayerStrategy();

    string* type;
    Territory* toAttack() override;
    Territory* toDeffend() override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) override;
};

//Aggresive
class AggressivePlayerStrategy: PlayerStrategy{
public:
    AggressivePlayerStrategy();
    ~AggressivePlayerStrategy();

    string* type;
    Territory* toAttack() override;
    Territory* toDeffend() override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) override;
};

//Benevolent
class BenevolentPlayerStrategy: PlayerStrategy{
public:
    BenevolentPlayerStrategy();
    ~BenevolentPlayerStrategy();

    string* type;
    Territory* toAttack() override;
    Territory* toDeffend() override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) override;
};

//Neutral
class NeutralPlayerStrategy: PlayerStrategy{
public:
    NeutralPlayerStrategy();
    ~NeutralPlayerStrategy();

    string* type;
    Territory* toAttack() override;
    Territory* toDeffend() override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) override;
};

//Cheater
class CheaterPlayerStrategy: PlayerStrategy{
public:
    CheaterPlayerStrategy();
    ~CheaterPlayerStrategy();

    string* type;
    Territory* toAttack() override;
    Territory* toDeffend() override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, Player* thisPlayer, Deck *&deck) override;
};
