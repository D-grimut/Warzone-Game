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
	this->deck = new Card[100];
	this->inHand = new int[100]; //This checks if a card is being used or not
	this->currentDeckSize = new int((int)100);
}
//overload, custom amount of cards (unused for demo and unfinished)
Deck::Deck(int deckSize)
{
	this->deck = new Card[deckSize];
	this->inHand = new int[deckSize];//I want to change this to bool
	this->currentDeckSize = new int((int)deckSize);
}

//copy constructor
Deck::Deck(const Deck& e){
	
}

//assignment constructor
Deck& Deck::operator=(const Deck& e){

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

int Deck::getCurrentDeckSize(){
	return *currentDeckSize;
}

//deconstructor
Deck::~Deck(){}

std::ostream& operator<<(std::ostream &strm, const Deck &a){ //instertion operator
    return strm << "Deploy(" << a.name << ")";
}


Card Deck::draw()
{
	this->random = new int();
	*random = rand() % getCurrentDeckSize(); //chooses a random card in the deck
	while (inHand[*random] == 1) //if the card is taken it will choose another random card
	{
		*random = rand() % getCurrentDeckSize();
	}
	inHand[*random] = 1; // sets the card as taken
	return deck[*random]; // returns the card
}

//Parent: Card
//default constructor
Card::Card()
{
	Type *type = new Type();
}
//overload, changes the type of the card
Card::Card(Type type1)
{
	this->type = new Type(type1);
}

Card::Card(const Card& e){

}

Card& Card::operator =(const Card& e){

}

//returns the type of the card
Type Card::getType()
{
	return *type;
}

//sets the type of the card
void Card::setType(Type newType)
{
	this->type = new Type(newType);
}

//plays the card by making it a order and removing it from hand
void Card::play() //I need Doms help for this
{
	//Adds the order
	
}

//deconstructor
Card::~Card(){}

//Parent: Hand
//default
Hand::Hand()
{
	this->hand = new Card[5];
}
//overload, custom handsize (isn't used in the demo)
Hand::Hand(int handSize)
{
	this->hand = new Card[handSize];
}

Hand::Hand(const Hand& e) {}

Hand& Hand::operator =(const Hand& e){}

//void Hand::addCard() {}

std::ostream& operator<<(std::ostream &strm, const Hand &a){ //instertion operator
    return strm << "This card really do be" << a.hand;
}

//Deconstructor
Hand::~Hand(){}