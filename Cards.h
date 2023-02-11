#ifndef CARDS_H
#define CARDS_H
//#include "Orders.h"
#include <random>

//Order specialOrder;
//OrderList newList(5)
int orderCounter = 0;
Card deck[];
int inHand[];

//all card types
enum class Type{
	bomb,
	reinforcement, 
	blockade,
	airlift,
	diplomacy
};

//Deck class
class Deck 
{
	public:
		Deck();
		Deck(int deckSize);
		Card draw();
		Card getDeck(int x);
		void setDeck(int x, Card card);
	private:
		//many might need to be friend to access within play()
		int currentDeckSize;
		int random;
};

//Card class
class Card //: public Order
{
	public:
		Card();
		Card(Type type);
		Type getType();
		void setType(Type newType);
		void play();
	private:
		Type type;
};

//Hand class
class Hand
{
	public:
		Hand();
		Hand(int handSize);
		//void addCard();
		Card hand[5];
	private:
		

};


#endif