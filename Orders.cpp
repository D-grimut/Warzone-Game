#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

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
            target.setNumberOfSoldiers(*target.getNumberOfSoldiers() + *armies) ;
        }
    }
}

Territory Deploy::getTragetTerr(){
    return target;
}

void Deploy::setTargetTerr(Territory *target1){
    target = *target1;
}

int* Deploy::getArmies(){
    return armies;
}

void Deploy::setArmies(int* armies1){
    armies = armies1;
}

int* Deploy:: getPlayerID(){
    return playerID;
}

void Deploy::setPlayerID(int* pID){
    playerID = pID;
}

string* Deploy::description(){
    name = new string("Deploy");
    return this->name;
}


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
    if(sourceTerriotry.getPossesor() != this.getPlayerID()){
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
    if(*validate() == true)
    //if(target != ownedTerrority) 
    cout << "Executing class: Advance\n";
}

/*Description: Returns name of order*/
string* Advance::description(){
    return this->name;
}

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
    if(targetTerritory.getPossesor() == this.getPlayerID()){
        //if(terriotry != adjacent(ownedTerrtiories))
        *ptr = false;
    }
    else
        *ptr = true;
    return ptr;
}

/*Execute Order method*/
void Bomb::execute(){
    if(*validate() == true)
    //targetTerritories.armies -= targetTerritories.armies/2
    cout << "Executing class: Bomb\n";
}

/*Description: Returns name of order*/
string* Bomb::description(){
    return this->name;
}

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
    //If the target territory belongs to an enemy player, the order is declared invalid.
    /* if(targetTerriotry != ownedTerritory) return false;
    */
    cout << "Validating class: Blockade\n";
     bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Blockade::execute(){
    if(*validate() == true)
    /*If the target territory belongs to the player issuing the order, the number of armies on the territory is
    * doubled and the ownership of the territory is transferred to the Neutral player, which must be created if it does not already exist.
    * 
    * targetTerritories.armies *=2;
    * if(!neutralPlayer){
    *  neutralPLayer();
    *  neutralPlayer.add(targetTerritory)
    * }
    */
    cout << "Executing class: Blockade\n";
}

/*Description: Returns name of order*/
string* Blockade::description(){
    return this->name;
}

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
    //If the source or target does not belong to the player that issued the order, the order is invalid.
    //if(sourceTerriotry != ownedTerriotry || tagerTerritory!= ownedTerritory) return false
    cout << "Validating class: Airlift\n";
     bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Airlift::execute(){
    //the selected number of armies is moved from the source to the target territory.
    if(*validate() == true)
    //sourceTerriotry -= numberArmies
    //targetTerriotry += numberArmies
    cout << "Executing class: Airlift\n";
}

/*Description: Returns name of order*/
string* Airlift::description(){
    return this->name;
}


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
    //If the target is the player issuing the order, then the order is invalid.
    //if(targetTerritory == ownedTerriotry) return false
    cout << "Validating class: Negotiate\n";
    bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Negotiate::execute(){
    /*If the target is an enemy player, then the effect is that any attack that may be declared between territories
    of the player issuing the negotiate order and the target player will result in an invalid order.
    
    */
    cout << "Executing class: Negotiate\n";
}

/*Description: Returns name of order*/
string* Negotiate::description(){
    return this->name;
}


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
