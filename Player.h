#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
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
- Add Card and Order to the Player constructor
- Do issueOrder
*/

class Player{
    private:
         // [Territory(1, "Canada", 0, 1 = "NA", false), Territory(2, "USA", 1, 1 = "NA", false)] I'm Player(1, Territory[], Card[], Order[])
        /*
        toDefend -> go through array of ALL territories
        check if the id of the possesor of the territory matches the player
        if yes -> add to an array then return array

        toAttack -> go through array of ALL territories
        check if the id of the possesor of the territory matches the player
        if yes -> add to an array then return array
        
        */



        int* playerID; // Gives the player an ID
        Territory* territories; // Creates an array of Territories
        /*
        Card *cards;
        Order *orders;
        */
    
    public:
        Player(int playerID, Territory* territories /*, Card *cards, Order *orders*/);
        Player();
        ~Player(); // Destruct Player object

        void setPlayerID(int playerID);
        void allTerritories(); // Show all territories
        Territory* toDefend(); // Show territories to attack
        Territory* toAttack(); // Show territories to defend
        // Order* issueOrder();
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