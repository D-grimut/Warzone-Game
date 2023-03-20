#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Orders.h"

class OrdersList;

//Card class
class Card
{
	public:
		Card();
		~Card();
		Card(const Card& e);//copy constructor
		Card& operator =(const Card& e);//assignment operator
		Card(string type);
		int getNumber();
		void setNumber(int newNumber);
		string getType();
		void setType(string newType);
		void play(Card card);
		OrdersList getOrdersList();
	private:
		string *type;
		int* size;
		OrdersList *ol;// list of orders
		int *ordersIndex;// Index of Orders
		int *number;

		friend std::ostream& operator<<(std::ostream &strm, const Card &a);
};

//Deck class
class Deck
{
	public:
		Deck();//default
		Deck(int deckSize);//overload
		~Deck();//deconstructor
		Deck(const Deck& e);//copy constructor
		Deck& operator =(const Deck& e);//assignment constructor
		Card* draw();//draws a card
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
		int* getSize();
		void addCard(Card *card, int position);
		void removeCard(int *position);
        void setSize(int *size);
        void resize();
		Card **hand;
		Card* getCard(int i);
		int* getCounter();
		void setCounter(int *counter);
	private:
		int* counter;
		int *size;
		string *name;
		friend std::ostream& operator<<(std::ostream &strm, const Hand &a);	
};