#pragma once
#include <stdio.h>
#include <string>
#include "Map.h"
#include "Orders.h"
#include "Cards.h"
class Player;
using namespace std;

class Territory;
class Player;
class Deck;

class PlayerStrategy{
public:
    virtual Territory* toAttack(Player* p) = 0;
    virtual Territory* toDeffend(Player* p) = 0;
    virtual void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                            Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) = 0;
};

//Human
class HumanPlayerStrategy: public PlayerStrategy{
public:
    HumanPlayerStrategy();
    ~HumanPlayerStrategy();

    string* type;
    Territory* toAttack(Player* p) override;
    Territory* toDeffend(Player* p) override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                    Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) override;
};

//Aggresive
class AggressivePlayerStrategy: public PlayerStrategy{
public:
    AggressivePlayerStrategy();
    ~AggressivePlayerStrategy();

    string* type;
    Territory* toAttack(Player* p) override;
    Territory* toDeffend(Player* p) override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy,
                    Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) override;
};

//Benevolent
class BenevolentPlayerStrategy: public PlayerStrategy{
public:
    BenevolentPlayerStrategy();
    ~BenevolentPlayerStrategy();

    string* type;
    Territory* toAttack(Player* p) override;
    Territory* toDeffend(Player* p) override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, 
                    Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) override;
};

//Neutral
class NeutralPlayerStrategy: public PlayerStrategy{
public:
    NeutralPlayerStrategy();
    ~NeutralPlayerStrategy();

    string* type;
    Territory* toAttack(Player* p) override;
    Territory* toDeffend(Player* p) override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, 
                    Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) override;
};

//Cheater
class CheaterPlayerStrategy: public PlayerStrategy{
public:
    CheaterPlayerStrategy();
    ~CheaterPlayerStrategy();

    string* type;
    Territory* toAttack(Player* p) override;
    Territory* toDeffend(Player* p) override;
    void issueOrders(string orderName, int *nbOfArmies, Territory* targetTerr, Territory* sourceTerr, Player* enemy, 
                    Player* thisPlayer, Deck *&deck, Player* p, int& ordersIndex) override;
};
