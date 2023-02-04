#include "Player.h"
#include "Map.h"
#include <iostream>

// Author: Alessio

int main(){
    // Territory* territories = new Territory[3];
    // territories[0].setPosessor(1);
    // territories[1].setPosessor(2);
    // territories[2].setPosessor(2);

    // territories[0].setName("Canada");
    // territories[1].setName("USA");
    // territories[2].setName("UK");

    MapLoader *ml = new MapLoader("C:\\Users\\aless\\github_desktop\\Warzone-Game\\europe.map");
    Map *map = ml->map;
    Territory* territories = map->getCountries();

    Player *p1 = new Player(1, territories);
    territories[0].setPosessor(p1->getPlayerID());

    cout << "Player's ID: " << p1->getPlayerID() << "\n" << endl;

    cout << "All territories: " << endl;
    p1->allTerritories();

    cout << "\n" << endl;

    cout << "Territories to defend: " << endl;
    p1->toDefend();

    cout << "\n" << endl;

    cout << "Territories to attack: " << endl;
    p1->toAttack();

    return 0;
}