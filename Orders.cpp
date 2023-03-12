#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <iostream>
#include <string>
using namespace std;

/* TO DO 
- Need to create a create a function that says if players are allowed to attack or not and check in all validate methods (part of negotiate)
- Check in each validate that is card based wether that card is in the players hand or not
- In each function that can conquer a territory, if a territory is conquered, give player a card.
- Figure out math for advance 
- finish negotiate
- figure out how to deal with cards
- neutral player
- check validation for number of armies
*/


//ORDER Class (PARENT)

/*Default Constructor*/
Order::Order(){
    name = new string("0");
} 

/*Copy Constructor*/
Order::Order(const Order& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Order::~Order(){
    delete this;
}

/*Assignment Operator*/
Order& Order::operator=(const Order& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Order &a){
    return strm << "Order(" << a.name << ")";
}

/*Validate Order method*/
bool* Order::validate(){
    cout << "Validating class: Order\n";
    bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Order::execute(){
    cout << "Executing class: Order\n";
}

/*Description: Returns name of order*/
string* Order::description(){
    return this->name;
}

/*-------------------------------------------------------------------------*/
//DEPLOY Class

/*Default Constructor*/
Deploy::Deploy(){
    name = new string("Deploy");
} 

/*Copy Constructor*/
Deploy::Deploy(const Deploy& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Deploy::~Deploy(){
    delete this;
}

/* Getters */
Territory Deploy::getTragetTerr(){
    return target;
}

int* Deploy::getArmies(){
    return armies;
}

int* Deploy:: getPlayerID(){
    return playerID;
}

/* Setters */
void Deploy::setTargetTerr(Territory *target1){
    target = *target1;
}

void Deploy::setArmies(int* armies1){
    armies = armies1;
}

void Deploy::setPlayerID(int* pID){
    playerID = pID;
}

/* Description -> return name of order*/
string* Deploy::description(){
    name = new string("Deploy");
    return this->name;
}

/*Assignment Operator*/
Deploy& Deploy::operator=(const Deploy& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Deploy &a){
    return strm << "Deploy(" << a.name << ")";
}

/*Validate Order method*/
bool* Deploy::validate(){
     bool* ptr = new bool(true);
//If the target territory does not belong to the player that issued the order, the order is invalid.
    if (target.getPosessor() != getPlayerID()){
        *ptr = false;
    }
    else
        *ptr = true;
    return ptr;
}

/*Execute Order method*/
void Deploy::execute(){
    while(getReinforcementPool() != 0){
    //If the target territory belongs to the player that issued the deploy order, the selected number of armies is added to the number of armies on that territory.
        if(*validate() == true){
            target.setNumberOfSoldiers(*target.getNumberOfSoldiers() + *armies);
            setReinforcementPool(getReinforcementPool() - *armies);
        }
        else
            cout << "Invalid deploy, terriotry does not belong to player." << endl;
    }
}

/*-------------------------------------------------------------------------*/
//ADVANCE Class

/*Default Constructor*/
Advance::Advance(){
    name = new string("Advance");
}

/*Copy Constructor*/
Advance::Advance(const Advance& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Advance::~Advance(){
    delete this;
}

/* Getters */
Territory Advance::getSourceTerr(){
    return source;
}

Territory Advance::getTargetTerr(){
    return target;
}

int* Advance::getArmies(){
    return armies;
}

int* Advance:: getPlayerID(){
    return playerID;
}

/* Setters */
void Advance::setSourceTerr(Territory* sourceTerr){
    source = *sourceTerr;
}

void Advance::setTargetTerr(Territory *target1){
    target = *target1;
}

void Advance::setArmies(int* armies1){
    armies = armies1;
}

void Advance::setPlayerID(int* pID){
    playerID = pID;
}

/*Description: Returns name of order*/
string* Advance::description(){ 
    return this->name;
}
   
/*Assignment Operator*/
Advance& Advance::operator=(const Advance& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Advance &a){
    return strm << "Advance(" << a.name << ")";
}


/*Validate Order method*/
bool* Advance::validate(){
    /*If the source territory does not belong to the player that issued the order, the order is invalid.
    * If the target territory is not adjacent to the source territory, the order is invalid.
    */
    bool* ptr = new bool(true);
    if(source.getPosessor() !=  getPlayerID()){
          //if (sourceTerritory !- adjacent) return false
           *ptr = false;
    }
    else
        *ptr = true;
   
    return ptr;
}

/*Execute Order method*/
void Advance::execute(){
    /*If the source and target territory both belong to the player that issued the order, the army units are moved
    from the source to the target territory.
    * If the target territory belongs to another player than the player that issued the advance order, an attack is simulated when the order is executed. An attack is simulated by the following battle simulation mechanism:
    * Each attacking army unit involved has 60% chances of killing one defending army. At the same time, each defending army unit has 70% chances of killing one attacking army unit.
    * If all the defender's armies are eliminated, the attacker captures the territory. The attacking army units that survived the battle then occupy the conquered territory.
    * A player receives a card at the end of his turn if they successfully conquered at least one territory during their turn.
    */
    if(*validate() == true){
        if(target.getPosessor() == getPlayerID()){
            target.setNumberOfSoldiers(*target.getNumberOfSoldiers() + *source.getNumberOfSoldiers());
            source.setNumberOfSoldiers(0);
        }
        if(target.getPosessor() != getPlayerID()){

            if(target.getNumberOfSoldiers() == 0){
                target.setPosessor(*getPlayerID());
                //draw();
            }
        }
    }
}

/*-------------------------------------------------------------------------*/
//BOMB Class

/*Default Constructor*/
Bomb::Bomb(){
    name = new string("Bomb");
}

/*Copy Constructor*/
Bomb::Bomb(const Bomb& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Bomb::~Bomb(){
    delete this;
}

/* Getters */
Territory Bomb::getTargetTerr(){
    return target;
}

int* Bomb:: getPlayerID(){
    return playerID;
}

/* Setters */
void Bomb::setTargetTerr(Territory *target1){
    target = *target1;
}

void Bomb::setPlayerID(int* pID){
    playerID = pID;
}

/*Description: Returns name of order*/
string* Bomb::description(){
    return this->name;
}

/*Assignment Operator*/
Bomb& Bomb::operator=(const Bomb& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Bomb &a){
    return strm << "Bomb(" << a.name << ")";
}

/*Validate Order method*/
bool* Bomb::validate(){
    /*If the target belongs to the player that issued the order, the order is invalid.
    * If the target territory is not adjacent to one of the territory owned by the player issuing the order, then the
    * order is invalid.
    */
    bool* ptr = new bool(true);
    if(target.getPosessor() == getPlayerID()){
        //if(terriotry != adjacent(ownedTerrtiories))
        *ptr = false;
    }
    else
        *ptr = true;
    return ptr;
}

/*Execute Order method*/
void Bomb::execute(){
    if(*validate() == true){
        target.setNumberOfSoldiers(floor(*target.getNumberOfSoldiers()/2));
    }
}


/*-------------------------------------------------------------------------*/
//BLOCKADE Class

/*Default Constructor*/
Blockade::Blockade(){
    name = new string("Blockade");
}

/*Copy Constructor*/
Blockade::Blockade(const Blockade& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Blockade::~Blockade(){
    delete this;
}

/* Getters */
Territory Blockade::getTargetTerr(){
    return target;
}

int* Blockade:: getPlayerID(){
    return playerID;
}

/* Setters */
void Blockade::setTargetTerr(Territory target1){
    target = target1;
}

void Blockade::setPlayerID(int* pID){
    playerID = pID;
}

/*Description: Returns name of order*/
string* Blockade::description(){
    return this->name;
}

/*Assignment Operator*/
Blockade& Blockade::operator=(const Blockade& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Blockade &a){
    return strm << "Blockade(" << a.name << ")";
}

/*Validate Order method*/
bool* Blockade::validate(){
    bool* ptr = new bool(true);
    //If the target territory belongs to an enemy player, the order is declared invalid.
    if(target.getPosessor() != getPlayerID()){
        *ptr = false;
    }
    return ptr;
}

/*Execute Order method*/
void Blockade::execute(){
    if(*validate() == true){
        target.setNumberOfSoldiers(*target.getNumberOfSoldiers()*2);
        target.setPosessor(-1); //-1 will be the neutral player
    }
    /*If the target territory belongs to the player issuing the order, the number of armies on the territory is
    * doubled and the ownership of the territory is transferred to the Neutral player, which must be created if it does not already exist.
    */
}


/*-------------------------------------------------------------------------*/
//AIRLIFT Class

/*Default Constructor*/
Airlift::Airlift(){
    name = new string("Airlift");
}

/*Copy Constructor*/
Airlift::Airlift(const Airlift& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Airlift::~Airlift(){
    delete this;
}

/* Getters */
Territory Airlift::getSourceTerr(){
    return source;
}

Territory Airlift::getTargetTerr(){
    return target;
}

int* Airlift::getArmies(){
    return armies;
}


void Airlift::setSourceTerr(Territory* sourceTerr){
    source = *sourceTerr;
}

int* Airlift:: getPlayerID(){
    return playerID;
}

/* Setters */ 
void Airlift::setTargetTerr(Territory *target1){
    target = *target1;
}

void Airlift::setArmies(int* armies1){
    armies = armies1;
}

void Airlift::setPlayerID(int* pID){
    playerID = pID;
}

/*Description: Returns name of order*/
string* Airlift::description(){
    return this->name;
}

/*Assignment Operator*/
Airlift& Airlift::operator=(const Airlift& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Airlift &a){
    return strm << "Airlift(" << a.name << ")";
}

/*Validate Order method*/
bool* Airlift::validate(){
    bool* ptr = new bool(true);
    //If the source or target does not belong to the player that issued the order, the order is invalid.
    if(source.getPosessor() != getPlayerID() || target.getPosessor() != getPlayerID()){
        *ptr = false;
    }
    return ptr;
}

/*Execute Order method*/
void Airlift::execute(){
    //the selected number of armies is moved from the source to the target territory.
    if(*validate() == true){
        target.setNumberOfSoldiers(*target.getNumberOfSoldiers() + *getArmies());
        source.setNumberOfSoldiers(*source.getNumberOfSoldiers() - *getArmies());
    }
}

/*-------------------------------------------------------------------------*/
//NEGOTIATE Class

/*Default Constructor*/
Negotiate::Negotiate(){
    name = new string("Negotiate");
}

/*Copy Constructor*/
Negotiate::Negotiate(const Negotiate& e){
    this->name = new string(*(e.name));
}

/*Destructor*/
Negotiate::~Negotiate(){
    delete this;
}

/* Getters */
Territory Negotiate::getTargetTerr(){
    return target;
}

int* Negotiate::getPlayerID(){
    return playerID;
}

/*Setters*/
void Negotiate::setTargetTerr(Territory target1){
    target = target1;
}

void Negotiate::setPlayerID(int* pID){
    playerID = pID;
}

/*Description: Returns name of order*/
string* Negotiate::description(){
    return this->name;
}

/*Assignment Operator*/
Negotiate& Negotiate::operator=(const Negotiate& e){
    this->name = new string(*(e.name));
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const Negotiate &a){
    return strm << "Negotiate(" << a.name << ")";
}

/*Validate Order method*/
bool* Negotiate::validate(){
    bool* ptr = new bool(true);
    //If the target is the player issuing the order, then the order is invalid.
    //if(targetTerritory == ownedTerriotry) return false
    if(target.getPosessor() != getPlayerID()){
        *ptr = false;
    }
    return ptr;
}

/*Execute Order method*/
void Negotiate::execute(){
    /*If the target is an enemy player, then the effect is that any attack that may be declared between territories
    of the player issuing the negotiate order and the target player will result in an invalid order.


        Need to create a create a function that says if players are allowed to attack or not and check in all validate methods
    */
}

/*-------------------------------------------------------------------------*/
//OrdersList Class

/*Default Constructor*/
OrdersList::OrdersList(){
    int* size = new int(5);
    setSize(size);
    orders = new Order* [*size];
}

/*Paramaterized Constructor*/
OrdersList::OrdersList(int* size){
    setSize(size);
    orders = new Order* [*size];
}

/*Copy Constructor*/
OrdersList::OrdersList(const OrdersList& e){
    this->size = new int(*(e.size));
    this->orders = new Order*();
}

/*Destructor*/
OrdersList::~OrdersList(){
    delete [] orders;
    orders = nullptr;
}

/*Assignment Operator*/
OrdersList& OrdersList::operator=(const OrdersList& e){
    this->size = new int(*(e.size));
    this->orders = new Order*();
    return *this;
}

/*Stream Insertion Operator*/
std::ostream& operator<<(std::ostream &strm, const OrdersList &a){
    return strm << "OrdersList(" << a.orders << ")";
}


void OrdersList::addOrder(Order* newOrder, int position){
    if(position > *getSize()){
        int* oldSize = getSize();
        resize();
        orders[*oldSize] = newOrder;
    }
    else
        orders[position] = newOrder;
}

void OrdersList::resize(){
    int* newSize = new int(*getSize() + 1);
    Order** newArr = new Order*[*newSize];
    for(int i = 0; i <= *getSize(); i++){
        newArr[i] = orders[i];
    }

    setSize(newSize);
    delete [] orders;
    orders = newArr;
}


void OrdersList::moveOrder(int* position1, int* position2){
    if(*position1 > *getSize() || *position2 > *getSize()){
            cout << "Invalid remove, please enter a number less than: " << *getSize() <<endl;
        }
    Order* temp = orders[*position1];
    if(*position1 > *position2){
        for(int i = *position2; i < *position1; i++){
            orders[i] = orders[i+1]; 
        }
        (orders[*position2]) = temp;
    }
    if(*position1 < *position2){
        for(int i = *position1; i < *position2; i++){
            orders[i] = orders[i+1]; 
        }
        (orders[*position2]) = temp;
    }
}

void OrdersList::removeOrder(int* position){
        if(*position > *getSize()){
            cout << "Invalid remove, please enter a number less than: " << getSize() <<endl;
        }
        for(int i = *position; i<*getSize(); i++){
            orders[i] = orders[i+1];
        }
        int* newSize = new int(*getSize() - 1);
        setSize(newSize);
}

void OrdersList::showList(int x){
    for(int i = 0; i < x; i++){
        string s = *orders[i]->getName();
        if(s.compare("0") == 1){
            break;
        }
         cout << *orders[i]->description() << endl;
    }
}

string* Order::getName(){
    return this->name;
}

int* OrdersList::getSize(){
    return this->size;
}

void OrdersList::setSize(int* size){
    this->size = size;
}

void OrdersList::validate(){
    for(int i = 0; i < *getSize(); i++){
        orders[i]->validate();
    }
}

void OrdersList::execute(){
    for(int i = 0; i < *getSize(); i++){
        orders[i]->execute();
    }
}
