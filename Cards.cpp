#include <iostream>
#include <random> 
#include "Cards.h"

/*
The way this currently checks for in use cards is inefficient and jank. I understand how to optimise it but I'm pressed on time
Please forgive my sins (They will be explained in detail other comments)
*/
//Parent: Deck
//default
Deck::Deck()
{
	Card deck[100];
	int inHand[100];
	currentDeckSize = 100;
}
//overload, custom amount of cards (unused for demo and unfinished)
Deck::Deck(int deckSize)
{
	Card deck[deckSize];
	int inHand[deckSize];//I want to change this to a different data structure, maybe a list?
	currentDeckSize = deckSize;
}

//gets a card in the deck
Card Deck::getDeck(int x)
{
	return deck[x];
}

//sets a card in the deck, used for initializing the deck
void Deck::setDeck(int x, Card card)
{
	deck[x] = card;
}




//this function isn't efficient if we have most of the cards drawn
Card Deck::draw()
{
	random = rand() % currentDeckSize; //chooses a random card in the deck
	while (inHand[random] == 1) //if the card is taken it will choose another random card
	{
		random = rand() % currentDeckSize;
	}
	inHand[random] = 1; // sets the card as taken
	return deck[random]; // returns the card
}

//Parent: Card
//default constructor
Card::Card()
{
	Type type;
}
//overload, changes the type of the card
Card::Card(Type type1)
{
	type = type1;
}

//returns the type of the card
Type Card::getType()
{
	return type;
}

//sets the type of the card
void Card::setType(Type newType)
{
	type = newType;
}

//plays the card by making it a order and removing it from hand
void Card::play() //I need Doms help for this
{
	//Adds the order
	orderCounter++;
	newList.addOrder();

}

//Parent: Hand
//default
Hand::Hand()
{
	Card hand[5];
}
//overload, custom handsize (isn't used in the demo)
Hand::Hand(int handSize)
{
	Card hand[handSize];
}

//void Hand::addCard() {}
