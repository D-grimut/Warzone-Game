#include "Cards.h"
#include "Orders.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "this runs A" << endl;
    //creates obj of each type to give to the cards in the deck
    Type a = Type::airlift;
    Type b = Type::blockade;
    Type c = Type::bomb;
    Type d = Type::diplomacy;
    Type e = Type::reinforcement;

    //creates the deck and fills it with cards of each type
    Deck *deckA = new Deck(10);
    cout << "this runs B" << endl;
    for (int i = (0); i < 10; i++){
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

    cout << "this runs" << endl;
    //creates a new players hand
    Hand *handA = new Hand();
    
    cout << "this runs" << endl;
    //draws cards for the hand
    for (int i = 0; i < 5; i++)
    {
        handA->hand[i] = deckA->draw();
    }

    cout << "this runs" << endl;
    cout << "Showing cards in hand: "<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Card " << i << ": " << handA->hand[i] << endl;
    }
    //creating a new orders and assigning cards to them
    int* size = new int(5);
    OrdersList newList(size);
    cout << "Showing newly filled list:" << endl;
    newList.showList();

    Order *orderA = new Order();
    Order *orderB = new Order();
    Order *orderC = new Order();
    Order *orderD = new Order();
    Order *orderE = new Order();

    *orderA = handA->hand[0].play(handA->hand[0]);
    *orderB = handA->hand[1].play(handA->hand[1]);
    *orderC = handA->hand[2].play(handA->hand[2]);
    *orderD = handA->hand[3].play(handA->hand[3]);
    *orderE = handA->hand[4].play(handA->hand[4]);

    //adding the orders to the OrderList
    newList.addOrder(orderA, 0);
    newList.addOrder(orderB, 1);
    newList.addOrder(orderC, 2);
    newList.addOrder(orderD, 3);
    newList.addOrder(orderE, 4);

    //outputting the list
    cout << "Showing newly filled list:" << endl;
    newList.showList();
    
    //showing the cards in hand (they should be blank)
    cout << "Showing cards in hand: "<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Card " << i << ": " << handA->hand[i] << endl;
    }

    cout << "Thank you for using this program!" << endl;
    return 0;
}