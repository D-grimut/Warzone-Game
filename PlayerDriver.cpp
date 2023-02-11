#include "Player.h"
#include "Map.h"
#include "Orders.h"
#include <iostream>

// Author: Alessio

int main(){
    MapLoader *ml = new MapLoader("C:\\Users\\aless\\github_desktop\\Warzone-Game\\europe.map");
    Map *map = ml->getMap();
    int nbTerritories = *ml->getMap()->getNbTerritories();
    Territory* territories = map->getCountries();
    // Order* orders = new Order();
    int* size = new int(10);
    OrdersList* ol = new OrdersList(size);

    Player *p1 = new Player(1, territories, ol, nbTerritories);
    territories[0].setPosessor(p1->getPlayerID());

    cout << *p1 << endl;

    p1->ownedTerritories();

    cout << endl;

    p1->issueOrder();

    cout << endl;

    ol->showList();

    // cout << "\n" << endl;

    // cout << "Territories to defend: " << endl;
    // p1->toDefend();

    // cout << "\n" << endl;

    // cout << "Territories to attack: " << endl;
    // p1->toAttack();

    return 0;
}