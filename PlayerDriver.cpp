#include "Player.h"
#include "Map.h"
#include <iostream>

// Author: Alessio

int main(){
    // cout << "Hello world" << endl;

    Territory* territories[3] = {new Territory(1, "Canada", 1, false, 1), 
                                new Territory(2, "USA", 2, false, 1),
                                new Territory(2, "UK", 3, false, 2)};

    //Territory(int posessor, string TerritoryName, 
                                        //int TerritoryId, bool isFree, int continentId);
    // territories[0] = new Territory(1, "Canada", 1, false, 1);
    // territories[1] = new Territory(2, "USA", 2, false, 1);
    // territories[2] = new Territory(2, "UK", 3, false, 2);

    Player *p1 = new Player(1, territories);

    p1->allTerritories();

    return 0;
}

//Make 1 boolean array, size of max amount of territories, possession array
//