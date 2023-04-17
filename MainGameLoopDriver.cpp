#include <stdio.h>
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"
#include "PlayerStrategies.h"

int main()
{

    GameEngine *engine = new GameEngine();
    MainGameState *mgs = new MainGameState(engine);

    // Load map, store map, store all territories, get number of territories
    MapLoader *ml = new MapLoader("brasil.map");

    Map *map = ml->getMap();

    Territory *territories = map->getCountries();

    Territory ***adjacencyMatrix = map->getAdjacencyMatrix();

    int nbTerritories = *ml->getMap()->getNbTerritories();

    bool gotCard = false;
    Deck *deck = new Deck();
    // Create a new player with playerID = 1 and playerID = 2 and territories
    Player *p1 = new Player(0, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    Player *p2 = new Player(1, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    Player *p3 = new Player(2, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    Player *p4 = new Player(3, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);

    //Chnage the player startegies to test the other player strategies
    PlayerStrategy *ps1 = new AggressivePlayerStrategy();
    PlayerStrategy *ps2 = new NeutralPlayerStrategy();
    PlayerStrategy *ps3 = new NeutralPlayerStrategy();
    PlayerStrategy *ps4 = new NeutralPlayerStrategy();

    // PlayerStrategy *ps1 = new AggressivePlayerStrategy();
    // PlayerStrategy *ps2 = new NeutralPlayerStrategy();
    // PlayerStrategy *ps3 = new CheaterPlayerStrategy();
    // PlayerStrategy *ps4 = new BenevolentPlayerStrategy();

    p1->setStrategy(ps1);
    p2->setStrategy(ps2);
    p3->setStrategy(ps3);
    p4->setStrategy(ps4);

    //Change the nb of player and the order of the player in teh array to test all combinations of the player startegies
    int nbOfPlayers = 4;
    Player **pArr = new Player *[nbOfPlayers];
    pArr[0] = p1;
    pArr[1] = p2;
    pArr[2] = p3;
    pArr[3] = p4;

    territories[0].setPosessor(*p1->getPlayerID());
    territories[0].setNumberOfSoldiers(0);
    territories[1].setPosessor(*p2->getPlayerID());
    territories[1].setNumberOfSoldiers(0);  
    territories[2].setPosessor(*p3->getPlayerID());
    territories[2].setNumberOfSoldiers(0);
    territories[3].setPosessor(*p4->getPlayerID());
    territories[3].setNumberOfSoldiers(0);

    p1->initToAttack();
    p1->initToDefend();
    p2->initToAttack();
    p2->initToDefend();
    p3->initToAttack();
    p3->initToDefend();
    p4->initToAttack();
    p4->initToDefend();   
    
    mgs->mainGameLoop(pArr, nbOfPlayers, map, 50);
    return 0;
}
