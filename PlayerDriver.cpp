#include "Player.h"
#include "Map.h"
#include "Orders.h"
#include "Cards.h"
#include <iostream>

int main(){
    // Load map, store map, store all territories, get number of territories
    MapLoader *ml = new MapLoader("C:\\Users\\aless\\github_desktop\\Warzone-Game\\europe.map");

    Map *map = ml->getMap();

    Territory* territories = map->getCountries();

    Territory*** adjacencyMatrix = map->getAdjacencyMatrix();

    int nbTerritories = *ml->getMap()->getNbTerritories();
    
    // Create a new player with playerID = 1 and playerID = 2 and territories

    Player *p1 = new Player(1, territories, nbTerritories, adjacencyMatrix, map, 0, 0);
    Player *p2 = new Player(2, territories, nbTerritories, adjacencyMatrix, map, 0, 0);
    Player *neutral = new Player(-1, territories, nbTerritories, adjacencyMatrix, map, 0, 0);


    // Set first half of territories so that Player 1 owns it
    for(int i = 0; i < nbTerritories/2; i++){
        territories[i].setPosessor(p1->getPlayerID());
    }

    // Set second half of territories so that Player 2 owns it
    for(int i = nbTerritories/2; i < nbTerritories; i++){
        territories[i].setPosessor(p2->getPlayerID());
    }

    // Prints Player's ID
    cout << *p1 << endl;

    // Prints all owned territories of player 1
    p1->ownedTerritories();

    cout << endl;

    // Prints Player's ID
    cout << *p2 << endl;

    // Prints all owned territories of player 2
    p2->ownedTerritories();

    cout << endl;

    // Creates order
    p1->issueOrder();

    cout << endl;

    // Creates order
    //p1->issueOrder();

    OrdersList o1 = p1->getOrdersList();
    o1.execute();

    // // ToDefend()
    // Territory* toDef = p1->toDefend();

    // for(int i = 0; i < nbTerritories; i++){
    //     if(*toDef[i].getPosessor() == -1){
    //         break;
    //     }
    //     cout << toDef[i] << endl;
    // }

    // // ToAttack()
    // Territory* toAtt = p1->toAttack();

    // for(int i = 0; i < nbTerritories; i++){
    //     if(*toAtt[i].getPosessor() == -1){
    //         break;
    //     }
    //     cout << toAtt[i] << endl;
    // }

    // // Print out hands of players
    // p1->printCards();

    return 0;
}