#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Orders.h"
#include "Cards.h"
using namespace std;

class Player{
    private:
        int* playerID;                  // The player's ID
        Territory* territories;         // Array of Territories
        OrdersList* ol;                 // List of Orders
        int* nbOfTerritories;           // Number of Territories
        int* ordersIndex;               // Index of Orders
        Territory* toDefArr;            // Array of Territories to defend
        Territory* toAttArr;            // Array of Territories to attack
        Territory*** adjacencyMatrix;   // 2D-array of territories
        Map* map;                       // Map object
        int* sizeOfHand;
        Hand* cards;                    // List Of Cards

        friend std::ostream& operator<<(std::ostream &strm, const Player &p); // Stream insertion operator

    public:
        // Constructor with parameters, default constructor, and destructor
        Player(int playerID, Territory* territories, int nbTerritories, Territory*** adjacencyMatrix, Map* map);
        Player();
        Player(const Player&);
        ~Player();

        // Methods
        void ownedTerritories();    // Show all owned territories
        void issueOrder();          // Create order and add it to array of orders
        Territory* toDefend();      // Show territories to defend
        Territory* toAttack();      // Show territories to attack
        void printCards();

        // Setters
        void setPlayerID(int playerID);
        void setTerritories(Territory territories);
        void setOl(OrdersList ol);
        void setNbOfTerritories(int nbOfTerritories);
        void setOrdersIndex(int ordersIndex);
        void setToDefArr(Territory toDefArr);
        void setToAttArr(Territory toAttArr);
        void setAdjacencyMatrix(Territory** adjacencyMatrix);
        void setMap(Map map);
        void setCards(Hand cards);
        
        // Getters
        int getPlayerID();
        OrdersList getOrdersList();
        Hand getCards();
        int getSizeOfHand();

        Player& operator=(const Player& p);
};

class PlayerDriver{
    private:
        Player* player;         // Player object
        Territory* territories; // Array of territories

    public:
        // Constructor with parameters, default constructor, and destructor
        PlayerDriver(Player player);
        PlayerDriver();
        ~PlayerDriver();
};