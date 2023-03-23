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
Card* Deck::draw()
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
	return a; // returns the card
}

//Parent: Card
//default constructor
Card::Card()
{
	this->type = new string("blockade");	
	this->number = new int();

	size = new int(10);

    this->ol = new OrdersList(size);
	this->ordersIndex = new int(0);
}
//overload, changes the type of the card
Card::Card(string type1)
{
	this->type = new string(type1);
	this->number = new int();
	size = new int(10);
    this->ol = new OrdersList(size);
	this->ordersIndex = new int(0);
}

//copy constructor
Card::Card(const Card& e)
{
	type = e.type;
	number = e.number;
	ol = e.ol;
	ordersIndex = e.ordersIndex;
}	

//insertion operator
Card& Card::operator =(const Card& e)
{
	this->type = e.type;
	this->number = e.number;
	this->ol = e.ol;
	this->ordersIndex = e.ordersIndex;
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
string Card::getType()
{
	return *type;
}

//sets the type of the card
void Card::setType(string newType)
{
	this->type = new string(newType);
}

//plays the card by making it a order and removing it from hand
void Card::play(Card card)
{
	//Adds the order
	Order *bomb = new Bomb();	
    this->ol->addOrder(bomb, *ordersIndex); 	
    (*ordersIndex)++;    
	//puts card back in the deck
	int temp = card.getNumber();
	card = Card();
}

OrdersList Card::getOrdersList(){
    return *this->ol;
}

//deconstructor
Card::~Card(){}

// instertion operator
std::ostream &operator<<(std::ostream &strm, const Card &a)
{
	return strm << "Card: " << a.type << endl;
}

//Parent: Hand
//default
Hand::Hand()
{
	size = new int(5);
    hand = new Card *[*size];
	counter = new int(0);
}

//overload, custom handsize (isn't used in the demo)
Hand::Hand(int handSize)
{
	size = new int(handSize);
   	hand = new Card *[*size];
	counter = new int(0);
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

int* Hand::getSize(){
    return this->size;
}

void Hand::addCard(Card *card, int position){
    if(position > *getSize()){
        int *oldSize = getSize();
        resize();
        hand[*oldSize] = card;        
    }
    else
        hand[position] = card;
	int* newCounter = new int((*counter +1));
	this->setCounter(newCounter);
}

void Hand::resize(){
    int *newSize = new int(*getSize() + 1);
    Card **newArr = new Card*[*newSize];
    for(int i = 0; i <= *getSize(); i++){
        newArr[i] = hand[i];
    }
    setSize(newSize);
    delete [] hand;
    hand = newArr;
}

void Hand::removeCard(int *position){
    if(*position > *counter){
        cout << "Invalid remove, please enter a number less than: " << getSize() <<endl;
    }
    for(int i = *position; i<*counter; i++){
        hand[i] = hand[i+1];
    }
    int* newSize = new int(*getSize() - 1);
    setSize(newSize);
	*counter--;
}

void Hand::setSize(int* size){
    this->size = size;
}

Card* Hand::getCard(int i){
    return hand[i];
}

int* Hand::getCounter(){
	return this->counter;
}

void Hand::setCounter(int* counter){
	this->counter = counter;
}

