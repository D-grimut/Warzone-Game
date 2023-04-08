#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <iostream>
#include <string>
using namespace std;

// ORDER Class (PARENT)

/*
TODO FOR DOM HEHEH AHAHHA:
- Add that getPlayer() thing everywhere where we use the other logic
- Test everything to see if bugs occur
*/

/*Default Constructor*/
Order::Order()
{
    name = new string("0");
}

/*Copy Constructor*/
Order::Order(const Order &e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Order::~Order()
{
    delete name;
    name = nullptr;
}

/*Assignment Operator*/
Order &Order::operator=(const Order &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Order &a)
{
    return strm << "Order(" << a.name << ")";
}

/*Validate Order method*/
bool Order::validate()
{
    cout << "Validating class: Order\n";
    bool *ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Order::execute()
{
    cout << "Executing class: Order\n";
}

/*Description: Returns name of order*/
string *Order::description()
{
    return this->name;
}

/*-------------------------------------------------------------------------*/
// DEPLOY Class

/*Default Constructor*/
Deploy::Deploy()
{
    name = new string("Deploy");
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;
}

/*Copy Constructor*/
Deploy::Deploy(const Deploy &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Deploy::~Deploy()
{
    delete target;
    target = nullptr;
    delete armies;
    armies = nullptr;
    player = nullptr;
}

/* Getters */
Territory *Deploy::getTragetTerr()
{
    return this->target;
}

int *Deploy::getArmies()
{
    return this->armies;
}

Player *Deploy::getPlayer()
{
    return this->player;
}

/* Setters */
void Deploy::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Deploy::setArmies(int *armies1)
{
    *this->armies = *armies1;
}

void Deploy::setPlayer(Player *player)
{
    this->player = player;
}

/* Description -> return name of order*/
string *Deploy::description()
{
    name = new string("Deploy");
    return this->name;
}

/*Assignment Operator*/
Deploy &Deploy::operator=(const Deploy &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Deploy &a)
{
    return strm << "Deploy(" << a.name << ")";
}

/*Validate Order method*/
bool Deploy::validate()
{
    bool ptr = true;

    if (*target->getPosessor() != *getPlayer()->getPlayerID())
    { // if deploying to an enemy territory, return false
        ptr = false;
        cout << "DEPLOY INVALID: Cannot deploy to enemy territory!" << endl;
    }
    else if (getPlayer()->getReinforcementPool() < *getArmies())
    {
        ptr = false;
        cout << "DEPLOY INVALID: Too many armies deployed" << endl;
    }
    else
    {
        ptr = true;
        cout << "DEPLOY VALID" << endl;
    }
    return ptr;
}

/*Execute Order method*/
void Deploy::execute()
{
    bool valid = this->validate();
    if (valid)
    {
        target->setNumberOfSoldiers(*target->getNumberOfSoldiers() + (*armies));          // add armies to target
        getPlayer()->setReinforcementPool(getPlayer()->getReinforcementPool() - *armies); // remove armies from origin
        getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
        cout << "DEPLOY EXECUTE: " << *target->getTerritoryName() << " now has " << *target->getNumberOfSoldiers() << " armies. Number of reinforcements left in pool: " << getPlayer()->getReinforcementPool() << endl;
    }
    else
        cout << "DEPLOY INVALID" << endl;
}

/*-------------------------------------------------------------------------*/
// ADVANCE Class

/*Default Constructor*/
Advance::Advance()
{
    name = new string("Advance");
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
    this->enemy = new Player;
}

/*Copy Constructor*/
Advance::Advance(const Advance &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Advance::~Advance()
{
    delete source;
    source = nullptr;
    delete target;
    target = nullptr;
    delete armies;
    armies = nullptr;
    player = nullptr;
    delete enemy;
    enemy = nullptr;
}

/* Getters */
Territory *Advance::getSourceTerr()
{
    return this->source;
}

Territory *Advance::getTargetTerr()
{
    return this->target;
}

int *Advance::getArmies()
{
    return this->armies;
}

Player *Advance::getPlayer()
{
    return this->player;
}

Player *Advance::getEnemy()
{
    return this->enemy;
}

Deck *Advance::getDeck()
{
    return this->deck;
}

/* Setters */
void Advance::setSourceTerr(Territory *sourceTerr)
{
    source = sourceTerr;
}

void Advance::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Advance::setEnemy(Player *enemy)
{
    this->enemy = enemy;
}

void Advance::setArmies(int *armies1)
{
    *this->armies = *armies1;
}

void Advance::setPlayer(Player *player)
{
    this->player = player;
}

void Advance::setDeck(Deck *&deck)
{
    this->deck = deck;
}

/*Description: Returns name of order*/
string *Advance::description()
{
    return this->name;
}

/*Assignment Operator*/
Advance &Advance::operator=(const Advance &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Advance &a)
{
    return strm << "Advance(" << a.name << ")";
}

/*Validate Order method*/
bool Advance::validate()
{
    bool ptr = true;
    if (*source->getPosessor() != *getPlayer()->getPlayerID())
    { // if source does not belong to player
        ptr = false;
        cout << "INVALID ADVANCE: source territory does not belong to you!" << endl;
    }
    else if (*getPlayer()->getNegotiateID() == *target->getPosessor())
    {
        ptr = false;
        cout << "INVALID ADVANCE: Negotiation between territories" << endl;
    }
    else if (*getArmies() > *source->getNumberOfSoldiers())
    {
        ptr = false;
        cout << "INVALID ADVANCE: Too many armies!" << endl;
    }
    else if (!(getPlayer()->getMap()->isAdjacent(source, target)))
    {
        ptr = false;
        cout << *source->getTerritoryName() << " is the source, " << *target->getTerritoryName() << " is the target" << endl;
        cout << "ADVANCE INVALID: terriotry is too far away" << endl;
    }
    else
    {
        ptr = true;
        cout << "ADVANCE VALID" << endl;
    }
    return ptr;
}

/*Execute Order method*/
void Advance::execute()
{
    if (validate())
    {
        if (*target->getPosessor() == *getPlayer()->getPlayerID())
        {
            target->setNumberOfSoldiers(*target->getNumberOfSoldiers() + *getArmies());
            source->setNumberOfSoldiers(*source->getNumberOfSoldiers() - *getArmies());
            getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
            getPlayer()->getMap()->getCountries()[*source->getTerritoryId()].setNumberOfSoldiers(*source->getNumberOfSoldiers());
            cout << "ADAVANCE EXECUTE: " << *target->getTerritoryName() << " now has " << *target->getNumberOfSoldiers() << endl;
        }
        else if (*target->getPosessor() != *getPlayer()->getPlayerID())
        {
            if (*enemy->strat->type == "Neutral")
            {
                enemy->setStrategy(new AggressivePlayerStrategy());
            }
            else if (*getPlayer()->strat->type == "Cheater")
            {
                getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setPosessor(*getPlayer()->getPlayerID());
                cout << "ADAVANCE EXECUTE: " << *target->getTerritoryName() << " was conquered! " << endl;
                cout << "Target id " << *target->getPosessor() << endl;
                return;
            }
            int defendKill = 0;
            int attackKill = 0;
            while (*target->getNumberOfSoldiers() > 0 && *source->getNumberOfSoldiers() > 0)
            {
                defendKill = rand() % 100;
                attackKill = rand() % 100;
                if (defendKill < 70)
                {
                    int sold = (*source->getNumberOfSoldiers() - 1);
                    source->setNumberOfSoldiers(sold);
                    int *army = new int((*getArmies() - 1));
                    setArmies(army);
                    delete army;
                }
                if (attackKill < 60)
                {
                    target->setNumberOfSoldiers(*target->getNumberOfSoldiers() - 1);
                }
            }
            if (*target->getNumberOfSoldiers() == 0)
            { // this player gets territory
                target->setPosessor(*getPlayer()->getPlayerID());
                // int* tempNumOfSold = new int(*source->getNumberOfSoldiers());//DELETE IT AFTER FYI
                target->setNumberOfSoldiers(*source->getNumberOfSoldiers());

                getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setPosessor(*getPlayer()->getPlayerID());
                getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*getArmies());
                getPlayer()->getMap()->getCountries()[*source->getTerritoryId()].setNumberOfSoldiers((*source->getNumberOfSoldiers() - *getArmies()));

                cout << "ADAVANCE EXECUTE: " << *target->getTerritoryName() << " was conquered! " << endl;
                cout << "Target id " << *target->getPosessor() << endl;
                if (getPlayer()->getGotCard() == false)
                {
                    getPlayer()->getCards()->addCard(getDeck()->draw(), (*getPlayer()->getCards()->getCounter() + 1));
                    getPlayer()->setGotCard(true);
                    cout << *getPlayer()->getPlayerID() << " has received a new card " << endl;
                }
                else if (getPlayer()->getGotCard() == true)
                {
                    cout << *getPlayer()->getPlayerID() << " has already recieved a card this turn." << endl;
                }
            }
            else if (*source->getNumberOfSoldiers() == 0)
            {                                                      // enemy gets terriotry
                int *tempId = new int(*getEnemy()->getPlayerID()); // DELETE IT AFTER FYI
                source->setPosessor(*tempId);
                int *tempNumOfSold = new int(*target->getNumberOfSoldiers()); // DELETE IT AFTER FYI
                source->setNumberOfSoldiers(*tempNumOfSold);
                target->setNumberOfSoldiers(0);

                getEnemy()->getMap()->getCountries()[*source->getTerritoryId()].setPosessor(*getEnemy()->getPlayerID());
                getEnemy()->getMap()->getCountries()[*source->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
                getEnemy()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(0);

                cout << "ADAVANCE EXECUTE: " << *source->getTerritoryName() << " was taken by enemy!" << endl;
                getEnemy()->getCards()->addCard(deck->draw(), (*getEnemy()->getCards()->getCounter() + 1));

                delete tempId;
                delete tempNumOfSold;
            }
        }
    }
}

/*-------------------------------------------------------------------------*/
// BOMB Class

/*Default Constructor*/
Bomb::Bomb()
{
    name = new string("Bomb");
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
}

/*Copy Constructor*/
Bomb::Bomb(const Bomb &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Bomb::~Bomb()
{
    delete target;
    target = nullptr;
    delete source;
    source = nullptr;
    player = nullptr;
}

/* Getters */
Territory *Bomb::getTargetTerr()
{
    return this->target;
}

Territory *Bomb::getSourceTerr()
{
    return this->source;
}

Player *Bomb::getPlayer()
{
    return this->player;
}

/* Setters */
void Bomb::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Bomb::setSourceTerr(Territory *source)
{
    this->source = source;
}

void Bomb::setPlayer(Player *player)
{
    this->player = player;
}

/*Description: Returns name of order*/
string *Bomb::description()
{
    return this->name;
}

/*Assignment Operator*/
Bomb &Bomb::operator=(const Bomb &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Bomb &a)
{
    return strm << "Bomb(" << a.name << ")";
}

/*Validate Order method*/
bool Bomb::validate()
{
    bool ptr = false;
    int *position = new int(0);

    for (int i = 0; i < *getPlayer()->getCards()->getCounter(); i++)
    {
        if (getPlayer()->getCards()->getCard(i)->getType() == "bomb")
        {
            ptr = true;
            position = new int(i);
            cout << "BOMB VALIDATE: Card in hand." << endl;
        }
    }

    if (ptr == false)
    {
        cout << "BOMB INVALID: you do not own this card" << endl;
        return ptr;
    }
    if (*getTargetTerr()->getPosessor() == *getPlayer()->getPlayerID())
    {
        ptr = false;
        cout << "BOMB INVALID: cannot bomb your own territory" << endl;
    }
    else if (*getPlayer()->getNegotiateID() == *target->getPosessor())
    {
        ptr = false;
        cout << "BOMB INVALID: Negotiation between territories" << endl;
    }
    else if (!(getPlayer()->getMap()->isAdjacent(source, target)))
    {
        ptr = false;
        cout << "BOMB INVALID: terriotry is too far away" << endl;
    }
    else
    {
        ptr = true;
        cout << "BOMB VALID" << endl;
        getPlayer()->getCards()->removeCard(position);
    }
    delete position;
    return ptr;
}

/*Execute Order method*/
void Bomb::execute()
{
    if (validate())
    {
        if (*target->getNumberOfSoldiers() == 0)
            cout << "BOMB EXECUTE: 0 armies in " << *target->getTerritoryName() << endl;
        target->setNumberOfSoldiers(floor(*target->getNumberOfSoldiers() / 2));
        getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
        cout << "BOMB EXECUTE: " << *target->getTerritoryName() << " was bombed, now has " << *target->getNumberOfSoldiers() << " armies" << endl;
    }
}

/*-------------------------------------------------------------------------*/
// BLOCKADE Class

/*Default Constructor*/
Blockade::Blockade()
{
    name = new string("Blockade");
    this->target = new Territory;
    this->player = new Player;
}

/*Copy Constructor*/
Blockade::Blockade(const Blockade &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Blockade::~Blockade()
{
    delete target;
    target = nullptr;
    player = nullptr;
}

/* Getters */
Territory *Blockade::getTargetTerr()
{
    return this->target;
}

Player *Blockade::getPlayer()
{
    return this->player;
}

/* Setters */
void Blockade::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Blockade::setPlayer(Player *player)
{
    this->player = player;
}

/*Description: Returns name of order*/
string *Blockade::description()
{
    return this->name;
}

/*Assignment Operator*/
Blockade &Blockade::operator=(const Blockade &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Blockade &a)
{
    return strm << "Blockade(" << a.name << ")";
}

/*Validate Order method*/
bool Blockade::validate()
{
    int *position = new int(0);
    bool ptr = false;
    for (int i = 0; i < *getPlayer()->getCards()->getCounter(); i++)
    {
        if (getPlayer()->getCards()->getCard(i)->getType() == "blockade")
        {
            ptr = true;
            position = new int(i);
            cout << "BLOCKADE VALIDATE: Card in hand." << endl;
        }
    }
    if (ptr == false)
    {
        cout << "BLOCKADE INVALID: you do not own this card" << endl;
        return ptr;
    }

    if (*target->getPosessor() != *getPlayer()->getPlayerID())
    {
        ptr = false;
        cout << "BLOCKADE INVALID: Cannot call a blockade on enemy terriotry" << endl;
    }
    else
    {
        ptr = true;
        cout << "BLOCKADE VALID" << endl;
        getPlayer()->getCards()->removeCard(position);
    }
    delete position;
    return ptr;
}

/*Execute Order method*/
void Blockade::execute()
{
    if (validate() == true)
    {
        target->setNumberOfSoldiers(*target->getNumberOfSoldiers() * 2);
        target->setPosessor(-1); //-1 will be the neutral player
        getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
        getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setPosessor(-1);
        cout << "BLOCKADE EXECUTE: " << *target->getTerritoryName() << " now belongs to neutral player and has " << *target->getNumberOfSoldiers() << " armies" << endl;
    }
}

/*-------------------------------------------------------------------------*/
// AIRLIFT Class

/*Default Constructor*/
Airlift::Airlift()
{
    name = new string("Airlift");
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
}

/*Copy Constructor*/
Airlift::Airlift(const Airlift &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Airlift::~Airlift()
{
    delete source;
    source = nullptr;
    delete target;
    target = nullptr;
    delete armies;
    armies = nullptr;
    player = nullptr;
}

/* Getters */
Territory *Airlift::getSourceTerr()
{
    return this->source;
}

Territory *Airlift::getTargetTerr()
{
    return this->target;
}

int *Airlift::getArmies()
{
    return this->armies;
}

void Airlift::setSourceTerr(Territory *sourceTerr)
{
    this->source = sourceTerr;
}

Player *Airlift::getPlayer()
{
    return this->player;
}

/* Setters */
void Airlift::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Airlift::setArmies(int *armies1)
{
    *this->armies = *armies1;
}

void Airlift::setPlayer(Player *player)
{
    this->player = player;
}

/*Description: Returns name of order*/
string *Airlift::description()
{
    return this->name;
}

/*Assignment Operator*/
Airlift &Airlift::operator=(const Airlift &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Airlift &a)
{
    return strm << "Airlift(" << a.name << ")";
}

/*Validate Order method*/
bool Airlift::validate()
{
    int *position = new int(0);
    bool ptr = false;
    for (int i = 0; i < *getPlayer()->getCards()->getCounter(); i++)
    {
        if (getPlayer()->getCards()->getCard(i)->getType() == "airlift")
        {
            ptr = true;
            position = new int(i);
            cout << "AIRLIFT VALIDATE: Card in hand." << endl;
        }
    }

    if (ptr == false)
    {
        cout << "AIRLIFT INVALID: you do not own this card" << endl;
        return ptr;
    }
    else if (*source->getNumberOfSoldiers() - *getArmies() < 0)
    {
        cout << "AIRLIFT INVALID: not enough armies to airlift " << endl;
        ptr = false;
    }
    else if (*source->getPosessor() != *getPlayer()->getPlayerID() || *target->getPosessor() != *getPlayer()->getPlayerID())
    {
        ptr = false;
        cout << "AIRLIFT INVALID: Source or Target does not belong to you" << endl;
    }
    else
    {
        ptr = true;
        cout << "AIRLIFT VALID" << endl;
        getPlayer()->getCards()->removeCard(position);
    }
    delete position;
    return ptr;
}

/*Execute Order method*/
void Airlift::execute()
{
    // the selected number of armies is moved from the source to the target territory.
    if (validate() == true)
    {
        target->setNumberOfSoldiers(*target->getNumberOfSoldiers() + *getArmies());
        source->setNumberOfSoldiers(*source->getNumberOfSoldiers() - *getArmies());
        getPlayer()->getMap()->getCountries()[*target->getTerritoryId()].setNumberOfSoldiers(*target->getNumberOfSoldiers());
        getPlayer()->getMap()->getCountries()[*source->getTerritoryId()].setNumberOfSoldiers(*source->getNumberOfSoldiers());
        cout << "AIRLIFT EXECUTE: " << *target->getTerritoryName() << " now has " << *target->getNumberOfSoldiers() << " and " << *source->getTerritoryName() << " now has " << *source->getNumberOfSoldiers() << endl;
    }
}

/*-------------------------------------------------------------------------*/
// NEGOTIATE Class

/*Default Constructor*/
Negotiate::Negotiate()
{
    name = new string("Negotiate");
    this->target = new Territory;
    this->player = new Player;
    this->enemy = new Player;
}

/*Copy Constructor*/
Negotiate::Negotiate(const Negotiate &e) : Order(e)
{
    this->name = new string(*(e.name));
}

/*Destructor*/
Negotiate::~Negotiate()
{
    delete target;
    target = nullptr;
    delete enemy;
    enemy = nullptr;
    player = nullptr;
}

/* Getters */
Territory *Negotiate::getTargetTerr()
{
    return this->target;
}

Player *Negotiate::getPlayer()
{
    return this->player;
}

Player *Negotiate::getEnemy()
{
    return this->enemy;
}

/*Setters*/
void Negotiate::setTargetTerr(Territory *target1)
{
    this->target = target1;
}

void Negotiate::setPlayer(Player *player)
{
    this->player = player;
}

void Negotiate::setEnemy(Player *enemy)
{
    this->enemy = enemy;
}

/*Description: Returns name of order*/
string *Negotiate::description()
{
    return this->name;
}

/*Assignment Operator*/
Negotiate &Negotiate::operator=(const Negotiate &e)
{
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const Negotiate &a)
{
    return strm << "Negotiate(" << a.name << ")";
}

/*Validate Order method*/
bool Negotiate::validate()
{
    int *position = new int(0);
    bool ptr = false;
    for (int i = 0; i < *getPlayer()->getCards()->getCounter(); i++)
    {
        if (getPlayer()->getCards()->getCard(i)->getType() == "diplomacy")
            ptr = true;
        position = new int(i);
        cout << "NEGOTIATE CARD VALIDATE: Card in hand." << endl;
    }
    if (ptr == false)
    {
        cout << "NEGOTIATE INVALID: you do not own this card" << endl;
        return ptr;
    }
    // If the target is the player issuing the order, then the order is invalid.
    if (*target->getPosessor() == *getPlayer()->getPlayerID())
    {
        ptr = false;
        cout << "NEGOTIATE INVALID: can't negotiate with yourself" << endl;
    }
    else
    {
        ptr = true;
        cout << "NEGOTIATE VALID" << endl;
        getPlayer()->getCards()->removeCard(position);
    }
    delete position;
    return ptr;
}

/*Execute Order method*/
void Negotiate::execute()
{
    if (validate())
    {
        getPlayer()->setNegotiateID(getEnemy()->getPlayerID());
        getEnemy()->setNegotiateID(getPlayer()->getPlayerID());
        cout << "NEGOTIATE EXECUTE: Player " << *getPlayer()->getPlayerID() << " is in negotiation with " << *getEnemy()->getPlayerID() << endl;
        cout << "All attacks between them will be stopped for this turn." << endl;
    }
}

/*-------------------------------------------------------------------------*/
// OrdersList Class

/*Default Constructor*/
OrdersList::OrdersList()
{
    this->size = new int(5);
    orders = new Order *[*size];
    for (int i = 0; i < *size; i++)
    {
        orders[i] = nullptr;
    }
    this->end = new int(0);
}

/*Paramaterized Constructor*/
OrdersList::OrdersList(int *size)
{
    this->size = new int(*size);
    orders = new Order *[*size];
    for (int i = 0; i < *size; i++)
    {
        orders[i] = nullptr;
    }
    this->end = new int(0);
}

/*Copy Constructor*/
OrdersList::OrdersList(const OrdersList &e)
{
    this->size = new int(*(e.size));
    this->orders = new Order *();
    this->end = new int(*(e.end));
}

/*Destructor*/
OrdersList::~OrdersList()
{
    for (int i = 0; i < *this->end; i++)
    {
        delete orders[i];
        orders[i] = nullptr;
    }
    delete[] orders;
    orders = nullptr;
}

/*Assignment Operator*/
OrdersList &OrdersList::operator=(const OrdersList &e)
{
    this->size = new int(*(e.size));
    this->orders = new Order *();
    *this->end = *e.end;
    return *this;
}

/*Stream Insertion Operator*/
std::ostream &operator<<(std::ostream &strm, const OrdersList &a)
{
    return strm << "OrdersList(" << a.orders << ")";
}

void OrdersList::addOrder(Order *newOrder, int position)
{
    if (position > *getSize())
    {
        int *oldSize = getSize();
        resize();
        orders[*oldSize] = newOrder;
    }
    else
    {
        orders[position] = newOrder;
    }
    *this->end = *this->end + 1;
}

void OrdersList::resize()
{
    int newSize = *getSize() * 2;
    Order **newArr = new Order *[newSize];
    for (int i = 0; i < *getSize(); i++)
    {
        newArr[i] = orders[i];
    }

    setSize(&newSize);
    delete[] orders;
    orders = newArr;
}

void OrdersList::moveOrder(int *position1, int *position2)
{
    if (*position1 > *getSize() || *position2 > *getSize())
    {
        cout << "Invalid remove, please enter a number less than: " << *getSize() << endl;
    }
    Order *temp = orders[*position1];
    if (*position1 > *position2)
    {
        for (int i = *position2; i < *position1; i++)
        {
            orders[i] = orders[i + 1];
        }
        (orders[*position2]) = temp;
    }
    if (*position1 < *position2)
    {
        for (int i = *position1; i < *position2; i++)
        {
            orders[i] = orders[i + 1];
        }
        (orders[*position2]) = temp;
    }
}

void OrdersList::removeOrder()
{
    // if (*getSize() <= 0)
    // {
    //     return;
    // }
    // if (*position > *getSize())
    // {
    //     cout << "Invalid remove, please enter a number less than: " << *getSize() << endl;
    // }
    // for (int i = *position; i < *getSize(); i++)
    // {
    //     orders[i] = orders[i + 1];
    // }
    // int *newSize = new int(*getSize() - 1);
    // setSize(newSize);
    // *this->end = *this->end - 1;

    for (int i = 0; i < *this->end; i++)
    {
        orders[i] = nullptr;
    }
    *this->end = 0;
}

void OrdersList::showList(int x)
{
    for (int i = 0; i < x; i++)
    {
        string s = *orders[i]->getName();
        if (s.compare("0") == 1)
        {
            break;
        }
        cout << *orders[i]->description() << endl;
    }
}

string *Order::getName()
{
    return this->name;
}

int *OrdersList::getSize()
{
    return this->size;
}

void OrdersList::setSize(int *size)
{
    *this->size = *size;
}

void OrdersList::validate()
{
    for (int i = 0; i < *getSize(); i++)
    {
        orders[i]->validate();
    }
}

void OrdersList::execute()
{

    for (int i = 0; i < *this->end; i++)
    {
        orders[i]->execute();
    }
}

Order *OrdersList::getOrder(int i)
{
    return orders[i];
}
