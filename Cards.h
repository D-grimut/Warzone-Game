#pragma once
#include <iostream>
#include <string>
using namespace std;

//#include "Orders.h"

//all card types
enum class Type {
	bomb,
	reinforcement, 
	blockade,
	airlift,
	diplomacy
};

//Card class
class Card //: public Order
{
	public:
		Card();
		~Card();
		Card(const Card& e);//copy constructor
		Card& operator =(const Card& e);//assignment operator
		Card(Type type);
		Type getType();
		void setType(Type newType);
		void play();
	private:
		Type *type;
		string* name;
		friend std::ostream& operator<<(std::ostream &strm, const Card &a);
};

//Deck class
class Deck 
{
	public:
		Deck();
		~Deck();
		Deck(const Deck& e);//copy constructor
		Deck& operator =(const Deck& e);//assignment constructor
		Deck(int deckSize);
		Card draw();
		Card getDeck(int x);
		void setDeck(int x, Card card);
		int getCurrentDeckSize();
		string* name;
	private:
		int *currentDeckSize;
		int *random;
		int *inHand;
		Card *deck;
		friend std::ostream& operator<<(std::ostream &strm, const Card &a);

};

//Hand class
class Hand
{
	public:
		Hand();
		~Hand();
		Hand(const Hand& e);//copy contructor
		Hand& operator =(const Hand& e);//assignment operator
		Hand(int handSize);
		//void addCard();
		Card *hand;
	private:
		string* name;
		friend std::ostream& operator<<(std::ostream &strm, const Hand &a);
		

};

