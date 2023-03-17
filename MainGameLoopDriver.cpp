#include <stdio.h>
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"

int main(){

    GameEngine *engine = new GameEngine();
    AssignReinforcementState *en = new AssignReinforcementState(engine);
    IssueOrderState *ios = new IssueOrderState(engine);
    ExecuteOrderState *exo = new ExecuteOrderState(engine);

    // Load map, store map, store all territories, get number of territories
    MapLoader *ml = new MapLoader("C:\\Users\\aless\\github_desktop\\Warzone-Game\\europe.map");

    Map *map = ml->getMap();

    Territory* territories = map->getCountries();

    Territory*** adjacencyMatrix = map->getAdjacencyMatrix();

    int nbTerritories = *ml->getMap()->getNbTerritories();

    bool gotCard = false;
    
    // Create a new player with playerID = 1 and playerID = 2 and territories
    Player *p1 = new Player(1, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    Player *p2 = new Player(2, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);

    const int nbOfPlayers = 2;
    Player *pArr[nbOfPlayers] = {p1, p2};

    // Set first half of territories so that Player 1 owns it
    for(int i = 0; i < nbTerritories/2; i++){
        territories[i].setPosessor(p1->getPlayerID());
        territories[i].setNumberOfSoldiers(0);
    }

    // Set second half of territories so that Player 2 owns it
    for(int i = nbTerritories/2; i < nbTerritories; i++){
        territories[i].setPosessor(p2->getPlayerID());
        territories[i].setNumberOfSoldiers(0);
    }


    //mainGameLoop();
    en->reinforcementPhase(pArr, nbOfPlayers);
    cout << "here" << endl;
    ios->issueOrdersPhase(pArr, nbOfPlayers);
    exo->executeOrderPhase(pArr, nbOfPlayers);

    return 0;
}
