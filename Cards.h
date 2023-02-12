#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Orders.h"


//all card types
enum class Type {
	bomb,
	reinforcement, 
	blockade,
	airlift,
	diplomacy
};

//Card class
class Card : public Order
{
	public:
		Card();
		~Card();
		Card(const Card& e);//copy constructor
		Card& operator =(const Card& e);//assignment operator
		Card(Type type);
		int getNumber();
		void setNumber(int newNumber);
		Type getType();
		void setType(Type newType);
		Order play(Card card);
	private:
		Type *type;
		string* name;
		Order *specialOrder = new Card();
		int *number = new int();
		friend std::ostream& operator<<(std::ostream &strm, const Card &a);
};

//Deck class
class Deck : public Order
{
	public:
		Deck();//default
		Deck(int deckSize);//overload
		~Deck();//deconstructor
		Deck(const Deck& e);//copy constructor
		Deck& operator =(const Deck& e);//assignment constructor
		Card draw();//draws a card
		Card getDeck(); //gets a card from the deck
		void setDeck(int x, Card card); //fills the deck with a card
		int getInHand(); 
		void setInHand(int newInHand);
		int getCurrentDeckSize();
		string* name;

	private:
		int *currentDeckSize;
		int *random;
		int *inHand;
		Card *deck;
		friend std::ostream& operator<<(std::ostream &strm, const Deck &a);

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
		Card *hand;
	private:
		string* name;
		friend std::ostream& operator<<(std::ostream &strm, const Hand &a);
		

};

