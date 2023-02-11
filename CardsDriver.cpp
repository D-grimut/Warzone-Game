#include "Cards.h"
#include <iostream>
using namespace std;

int main() {
    //creates obj of each type to give to the cards in the deck
    Type a = Type::airlift;
    Type b = Type::blockade;
    Type c = Type::bomb;
    Type d = Type::diplomacy;
    Type e = Type::reinforcement;

    //creates the deck and fills it with cards of each type
    Deck *deckA = new Deck();
    for (int i = (0); i < 100; i++){
        if (i < 21){
            deckA->setDeck(i, a);
        } else if (i < 41) {
            deckA->setDeck(i, b);
        } else if (i < 61) {
            deckA->setDeck(i, c);
        } else if (i < 81) {
            deckA->setDeck(i, d);
        } else {
            deckA->setDeck(i, e);
        }
    }

    //creates a new players hand
    Hand *handA = new Hand(5);
    
    //draws cards for the hand
    for (int i = 0; i < 5; i++)
    {
        handA->hand[i] = deckA->draw();
    }

    //plays the cards in hand by creating a new order 


    cout << "Printing stuff :)" << endl;
    return 0;
}