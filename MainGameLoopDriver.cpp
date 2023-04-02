#include <stdio.h>
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"
#include "PlayerStrategies.h"

int main(){

    GameEngine *engine = new GameEngine();
    MainGameState *mgs = new MainGameState(engine);

    // Load map, store map, store all territories, get number of territories
    MapLoader *ml = new MapLoader("europe.map");

    Map *map = ml->getMap();

    Territory* territories = map->getCountries();

    Territory*** adjacencyMatrix = map->getAdjacencyMatrix();

    int nbTerritories = *ml->getMap()->getNbTerritories();

    bool gotCard = false;
   Deck* deck = new Deck();
    // Create a new player with playerID = 1 and playerID = 2 and territories
    Player *p1 = new Player(0, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    Player *p2 = new Player(1, territories, nbTerritories, adjacencyMatrix, map, 0, 0, &gotCard);
    
    PlayerStrategy* ps1 = new BenevolentPlayerStrategy();
    PlayerStrategy* ps2 = new CheaterPlayerStrategy();
    
    p1->setStrategy(ps1);
    p2->setStrategy(ps2);

    cout << "here3" << endl;

        // Card* card1 = new Card("bomb");
        // Card* card2 = new Card("diplomacy");
        // Card* card3 = new Card("blockade");
        // Card* card4 = new Card("airlift");

        // Hand* hand1 = new Hand(2);
        // Hand* hand2 = new Hand(2);

        // p1->getCards()->addCard(card1, 1);
        // p1->getCards()->addCard(card2, 2);
        // p2->getCards()->addCard(card3, 1);
        // p2->getCards()->addCard(card4, 2);

 

    const int nbOfPlayers = 2;
    Player *pArr[nbOfPlayers] = {p2, p1};

    //Set first half of territories so that Player 1 owns it
    for(int i = 0; i < nbTerritories/2; i++){
        territories[i].setPosessor(*p1->getPlayerID());
        territories[i].setNumberOfSoldiers(0);
    }

    // Set second half of territories so that Player 2 owns it
    for(int i = nbTerritories/2; i < nbTerritories; i++){
        territories[i].setPosessor(*p2->getPlayerID());
        territories[i].setNumberOfSoldiers(0);
    }

    for(int i = 0; i < nbTerritories; i++){
        cout << territories[i] << endl;
    }

    p1->initToAttack();
    p1->initToDefend();
    p2->initToAttack();
    p2->initToDefend();

    mgs->mainGameLoop(pArr, nbOfPlayers, map);
    return 0;
}
