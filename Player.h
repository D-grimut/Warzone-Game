#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Orders.h"
using namespace std;

// Author: Alessio

// Player owns collection of Territories, owns a hand of Cards, owns a list of Orders
// Implement methods
// toDefend() -> returns list of territories to defend
// toAttack() -> returns list of territories to attack
// Both of the methods is to show a list, that's all
// issueOrder() -> creates Order object, puts it in list of Orders
// Create PlayerDriver to create players and show the functions

/*
TODO:
- Add Card to the Player constructor
- Do issueOrder
- All classes implement a correct copy constructor, assignment operator, and stream insertion operator.
*/

class Player{
    private:
        int* playerID; // Gives the player an ID
        Territory* territories; // Creates an array of Territories
        // Order* orders;
        OrdersList* ol;
        int* nbOfTerritories;
        friend std::ostream& operator<<(std::ostream &strm, const Player &p);
        /*
        Card *cards;
        */
    
    public:
        // Player(int playerID, Territory* territories /*, Card *cards*/, Order* orders, int nbTerritories);
        Player(int playerID, Territory* territories /*, Card *cards*/, OrdersList* ol, int nbTerritories);
        Player();
        ~Player(); // Destruct Player object

        void setPlayerID(int playerID);
        int getPlayerID();
        void ownedTerritories(); // Show all territories
        Territory* toDefend(); // Show territories to attack
        Territory* toAttack(); // Show territories to defend
        void issueOrder(); // Create order and add it to array of orders
};

class PlayerDriver{
    private:
        Player* player; // Player object
        Territory* territories; // Array of territories

    public:
        PlayerDriver(Player player);
        PlayerDriver();
        ~PlayerDriver();
};