#include <iostream>
#include <random> 
#include "Cards.h"
#include "Orders.h"

//Parent: Deck
//default
Deck::Deck()
{
	this->deck = new Card[100];
	this->inHand = new int[100]; //This checks if a card is being used or not
	this->currentDeckSize = new int(100);
}

//overload, custom amount of cards (unused for demo and unfinished)
Deck::Deck(int deckSize)
{
	this->deck = new Card[deckSize];
	this->inHand = new int[deckSize];
	this->currentDeckSize = new int((int)deckSize);
}

//copy constructor
Deck::Deck(const Deck& e)
{
	deck = e.deck;
	inHand = e.inHand;
	currentDeckSize = e.currentDeckSize;	
}

//assignment constructor
Deck& Deck::operator=(const Deck& e)
{
	this->deck = e.deck;
	this->inHand = e.inHand;
	this->currentDeckSize = e.currentDeckSize;
    return *this;
}

//gets a card in the deck
Card Deck::getDeck()
{
	return *deck;
}

//sets a card in the deck, used for initializing the deck
void Deck::setDeck(int x, Card card)
{
	deck[x] = card;
}

//inHand getter
int Deck::getInHand()
{
	return *inHand;
}

//sets the type of the card
void Deck::setInHand(int newInHand)
{
	this->inHand = new int(newInHand);
}

//currentDeckSize getter
int Deck::getCurrentDeckSize()
{
	return *currentDeckSize;
}

//deconstructor
Deck::~Deck(){}

//instertion operator
std::ostream& operator<<(std::ostream &strm, const Deck &a)
{ 
    return strm << "Deck:" << a.deck;
}

//the draw method
Card Deck::draw()
{
	this->random = new int();
	*random = rand() % getCurrentDeckSize(); //chooses a random card in the deck
	while (inHand[*random] == 1) //if the card is taken it will choose another random card
	{
		*random = rand() % getCurrentDeckSize();
	}
	inHand[*random] = 1; // sets the card as taken
	Card *a = new Card(deck[*random]);
	a->setNumber(*random);
	return *a; // returns the card
}

//Parent: Card
//default constructor
Card::Card()
{
	cout << "1 " << endl;
	this->type = new Type();
	cout << "2 " << endl;
	this->number = new int(-1);
	cout << "3 " << endl;
}
//overload, changes the type of the card
Card::Card(Type type1)
{
	this->type = new Type(type1);
	this->number = new int();
}

//copy constructor
Card::Card(const Card& e)
{
	type = e.type;
	number = e.number;
}	

//insertion operator
Card& Card::operator =(const Card& e)
{
	this->type = e.type;
	this->number = e.number;
    return *this;
}

//returns number
int Card::getNumber()
{
	return *number;
}

//sets the type of the card
void Card::setNumber(int newNumber)
{
	this->number = new int(newNumber);
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
Order Card::play(Card card)
{
	//Adds the order
	this->specialOrder = new Order();
    *specialOrder = card;
	//puts card back in the deck
	int temp = card.getNumber();
	card = Card();
	//returns the order to be added to the Orderlist
	return *specialOrder;
}

//deconstructor
Card::~Card(){}

//instertion operator
std::ostream& operator<<(std::ostream &strm, const Card &a)
{ 
    return strm << "Card: " << a.type;
}


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

//copy constructor
Hand::Hand(const Hand& e) 
{
	hand = e.hand;
}

//assignment constructor
Hand& Hand::operator =(const Hand& e)
{
	this->hand = e.hand;
    return *this;
}

//instertion operator
std::ostream& operator<<(std::ostream &strm, const Hand &a)
{ 
    return strm << "Hand: " << a.hand;
}

//Deconstructor
Hand::~Hand(){}