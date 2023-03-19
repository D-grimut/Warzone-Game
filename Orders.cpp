#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "Cards.h"
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
bool Order::validate(){
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
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;

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
Territory* Deploy::getTragetTerr(){
    return this->target;
}

int* Deploy::getArmies(){
    return this->armies;
}


Player* Deploy::getPlayer(){
    return this->player;
}

/* Setters */
void Deploy::setTargetTerr(Territory *target1){
   this->target = target1;
}

void Deploy::setArmies(int* armies1){
    *this->armies = *armies1;
}

void Deploy::setPlayer(Player* player){
    this->player =  player;
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
bool Deploy::validate(){
    bool ptr = true;
    //cout << *target->getPosessor() << ", " << getPlayer()->getPlayerID() << endl;
    if (*target->getPosessor() != getPlayer()->getPlayerID()){ //if deploying to an enemy territory, return false
        ptr = false;
        cout << "DEPLOY INVALID: Cannot deploy to enemy territory!" << endl;
    }
    else if (getPlayer()->getReinforcementPool() < *getArmies()){
        ptr = false;
        cout << "DEPLOY INVALID: Too many armies deployed" << endl;
    }
   else{
        ptr = true;
        cout << "DEPLOY VALID"<< endl;
    }
    return ptr;
}

/*Execute Order method*/
void Deploy::execute(){
        bool valid = this->validate();
        // cout << *armies << " armies, " << *target->getNumberOfSoldiers() << " # of soldiers" << endl;
        // cout << "Math: " << (*target->getNumberOfSoldiers()) + (*armies) << endl;
        //cout << valid << endl;
        if(valid){
            target->setNumberOfSoldiers((*target->getNumberOfSoldiers()) + (*armies)); //add armies to target
          //cout << *target->getNumberOfSoldiers() << "target armies " << endl;

          // cout <<(*target->getNumberOfSoldiers()) + (*armies)<< " target test " << endl;
            getPlayer()->setReinforcementPool(getPlayer()->getReinforcementPool() - *armies); //remove armies from origin
            cout<< "DEPLOY EXECUTE: " << *target->getTerritoryName() << " now has " << *target->getNumberOfSoldiers() << " armies. Number of reinforcements left in pool: " << getPlayer()->getReinforcementPool() <<endl;
        }
        else
            cout << "DEPLOY INVALID" << endl;
}

/*-------------------------------------------------------------------------*/
//ADVANCE Class

/*Default Constructor*/
Advance::Advance(){
    name = new string("Advance");
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
    this->enemy = new Player;
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
Territory* Advance::getSourceTerr(){
    return this->source;
   
}

Territory* Advance::getTargetTerr(){
    return this->target;
}

int* Advance::getArmies(){
    return this->armies;
}

Player* Advance::getPlayer(){
    return this->player;
}

Player* Advance::getEnemy(){
    return this->enemy;
}
/* Setters */
void Advance::setSourceTerr(Territory* sourceTerr){
    source = sourceTerr;
    
}

void Advance::setTargetTerr(Territory* target1){
    this->target = target1;
}

void Advance::setEnemy(Player* enemy){
    this->enemy = enemy;
}

void Advance::setArmies(int* armies1){
    *this->armies = *armies1;
}

void Advance::setPlayer(Player* player){
    this->player = player;
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
bool Advance::validate(){
    bool ptr = true;
    //cout << *getArmies() << "->Armies, " << *source->getNumberOfSoldiers()<<"source armies, " <<*target->getNumberOfSoldiers()<< "target armies"<< endl;
    if(*source->getPosessor() != getPlayer()->getPlayerID()){ //if source does not belong to player
            ptr = false;
           cout<< "INVALID ADVANCE: source territory does not belong to you!" << endl;
    }
     else if(getPlayer()->getNegotiateID() == *target->getPosessor()){
        ptr = false;
        cout << "INVALID ADVANCE: Negotiation between territories" << endl;
    }else if(*getArmies() > *source->getNumberOfSoldiers()){
        ptr = false;
        cout<< *getArmies() << " armies; " << *source->getTerritoryName() << " source armies" << endl;
        cout << "INVALID ADVANCE: Too many armies!" << endl;
    }
    else{
        ptr = true;
        cout << "ADVANCE VALID"<< endl;
    }
    return ptr;
}

/*Execute Order method*/
void Advance::execute(){
    Deck* deck = new Deck;
   // cout << *target->getNumberOfSoldiers() << ", " << *source->getNumberOfSoldiers() << ", " << *getArmies() << endl;
    if(validate()){
        cout << *target->getPosessor() << " ID, " << getPlayer()->getPlayerID() << " player id" << endl;
        if(*target->getPosessor() == getPlayer()->getPlayerID()){
            target->setNumberOfSoldiers(*target->getNumberOfSoldiers() + *source->getNumberOfSoldiers());
            source->setNumberOfSoldiers(*source->getNumberOfSoldiers() - *getArmies());
            cout << "ADAVANCE EXECUTE: "<<target->getTerritoryName() << " now has "<< target->getNumberOfSoldiers()<< endl;
        }
        else if(*target->getPosessor() != getPlayer()->getPlayerID()){
           int defendKill = 0;
           int attackKill = 0;
           while(*target->getNumberOfSoldiers() > 0 && *source->getNumberOfSoldiers() > 0){
                defendKill = rand() % 100;
                attackKill = rand() % 100;
                cout << "defendKill"<< defendKill << endl;
                cout << "attack"<< defendKill << endl;
                if(defendKill < 70)
                    source->setNumberOfSoldiers(*source->getNumberOfSoldiers() - 1);
                if(attackKill < 60)
                    target->setNumberOfSoldiers(*target->getNumberOfSoldiers() - 1);
            }
            if(*target->getNumberOfSoldiers() == 0){
                target->setPosessor(getPlayer()->getPlayerID());
                target->setNumberOfSoldiers(*source->getNumberOfSoldiers());
                source->setNumberOfSoldiers(0);
                cout << "ADAVANCE EXECUTE: "<< *target->getTerritoryName() << " was conquered! "<< endl;
                if(getPlayer()->getGotCard() == false){
                    Card* newCard = deck->draw();
                    getPlayer()->getCards()->addCard(newCard, (*getPlayer()->getCards()->getSize() + 1));
                    getPlayer()->setGotCard(true);
                    cout <<getPlayer()->getPlayerID() << " has received a new card " << endl;
                }
                else if(getPlayer()->getGotCard() == true){
                    cout <<getPlayer()->getPlayerID() << " has already recieved a card this turn." << endl;
                }
            }
            else if(*source->getNumberOfSoldiers() == 0){
                source->setPosessor(*target->getPosessor());
                source->setNumberOfSoldiers(*target->getNumberOfSoldiers());
                target->setNumberOfSoldiers(0);
                cout << "ADAVANCE EXECUTE: "<< *source->getTerritoryName() << " was taken by enemy!"<< endl;
                getEnemy()->getCards()->addCard(deck->draw(), (*getEnemy()->getCards()->getSize()+1));
            }
        }
    }
}

/*-------------------------------------------------------------------------*/
//BOMB Class

/*Default Constructor*/
Bomb::Bomb(){
    name = new string("Bomb");
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
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
Territory* Bomb::getTargetTerr(){
    return this->target;
}

Territory* Bomb::getSourceTerr(){
    return this->source;
}

Player* Bomb::getPlayer(){
    return this->player;
}

/* Setters */
void Bomb::setTargetTerr(Territory* target1){
    this->target = target1;
}

void Bomb::setSourceTerr(Territory* source){
    this->source = source;
}

void Bomb::setPlayer(Player* player){
    this->player = player;
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
bool Bomb::validate(){
    bool ptr = true;
    int* position = 0;
    for(int i = 0; i < player->getSizeOfHand(); i++){
       if(getPlayer()->getCards()->getCard(i)->getType() != Type::bomb){
        ptr = false;
       }
       else if(getPlayer()->getCards()->getCard(i)->getType() == Type::bomb)
        ptr = true;
        *position = i;
        cout << "BOMB VALIDATE: Card in hand."<< endl;
    }
    if(ptr == false){
        cout<< "BOMB INVALID: you do not own this card" <<endl;
        return ptr;
    }
    if(*getTargetTerr()->getPosessor() == getPlayer()->getPlayerID()){
        ptr = false;
        cout << "BOMB INVALID: cannot bomb your own territory"<< endl;
    }
    // else if(!(map->isAdjacent(*source, *target))){
    //     *ptr = false;
    //     cout << "BOMB INVALID: terriotry is too far away"<< endl;
    // }
    else if(getPlayer()->getNegotiateID() == *target->getPosessor()){
        ptr = false;
        cout << "BOMB INVALID: Negotiation between territories" << endl;
    }
    else{
        ptr = true;
        cout << "BOMB VALID"<< endl;
        getPlayer()->getCards()->removeCard(position);
    }
    return ptr;
}

/*Execute Order method*/
void Bomb::execute(){
    if(validate() == true){
        target->setNumberOfSoldiers(floor(*target->getNumberOfSoldiers()/2));
        cout << "BOMB EXECUTE: " << target->getTerritoryName() << " was bombed, now has " << target->getNumberOfSoldiers() << " armies" << endl;
    }
}


/*-------------------------------------------------------------------------*/
//BLOCKADE Class

/*Default Constructor*/
Blockade::Blockade(){
    name = new string("Blockade");
    this->target = new Territory;
    this->player = new Player;
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
Territory* Blockade::getTargetTerr(){
    return this->target;
}

Player* Blockade::getPlayer(){
    return this->player;
}

/* Setters */
void Blockade::setTargetTerr(Territory* target1){
    this->target = target1;
}

void Blockade::setPlayer(Player* player){
    this->player = player;
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
bool Blockade::validate(){
    int* position = 0;
    bool ptr = true;
    for(int i = 0; i < getPlayer()->getSizeOfHand(); i++){
       if(getPlayer()->getCards()->getCard(i)->getType() != Type::blockade){
        ptr = false;
       }
       else if(getPlayer()->getCards()->getCard(i)->getType() == Type::blockade)
        ptr = true;
        *position = i;
        cout << "BLOCKADE VALIDATE: Card in hand."<< endl;
    }
    if(ptr == false){
        cout<< "BLOCKADE INVALID: you do not own this card" <<endl;
        return ptr;
    }
    
    if(*target->getPosessor() != getPlayer()->getPlayerID()){
        ptr = false;
        cout << "BLOCKADE INVALID: Cannot call a blockade on enemy terriotry" << endl;
    }
    else{
        ptr = true;
        cout << "BLOCKADE VALID"<< endl;
        getPlayer()->getCards()->removeCard(position);
    }
    return ptr;
}

/*Execute Order method*/
void Blockade::execute(){
    if(validate() == true){
        target->setNumberOfSoldiers(*target->getNumberOfSoldiers()*2);
        target->setPosessor(-1); //-1 will be the neutral player
        cout << "BLOCKADE EXECUTE: "<<target->getTerritoryName()<<" now belongs to neutral player and has " << target->getNumberOfSoldiers() << " armies" << endl;
    }
}


/*-------------------------------------------------------------------------*/
//AIRLIFT Class

/*Default Constructor*/
Airlift::Airlift(){
    name = new string("Airlift");
    this->armies = new int(0);
    this->target = new Territory;
    this->player = new Player;
    this->source = new Territory;
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
Territory* Airlift::getSourceTerr(){
    return this->source;
}

Territory* Airlift::getTargetTerr(){
    return this->target;
}

int* Airlift::getArmies(){
    return this->armies;
}

void Airlift::setSourceTerr(Territory* sourceTerr){
    this->source = sourceTerr;
}

Player* Airlift::getPlayer(){
    return this->player;
}

/* Setters */ 
void Airlift::setTargetTerr(Territory* target1){
    this->target = target1;
}

void Airlift::setArmies(int* armies1){
    *this->armies = *armies1;
}

void Airlift::setPlayer(Player* player){
    this->player =  player;
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
bool Airlift::validate(){
    int* position = 0;
    bool ptr = true;
    for(int i = 0; i < getPlayer()->getSizeOfHand(); i++){
       if(getPlayer()->getCards()->getCard(i)->getType() != Type::airlift){
        ptr = false;
       }
       else if(getPlayer()->getCards()->getCard(i)->getType() == Type::airlift)
        ptr = true;
        *position = i;
        cout << "AIRLIFT VALIDATE: Card in hand."<< endl;
    }
    if (ptr == false){
        cout<< "AIRLIFT INVALID: you do not own this card" <<endl;
        return ptr;
    }

    if(*source->getPosessor() != getPlayer()->getPlayerID() || *target->getPosessor() != getPlayer()->getPlayerID()){
        ptr = false;
        cout << "AIRLIFT INVALID: Source or Target does not belong to you" <<endl;
    }
    else{
        ptr = true;
        cout << "AIRLIFT VALID"<< endl;
        getPlayer()->getCards()->removeCard(position);
    }
    return ptr;
}

/*Execute Order method*/
void Airlift::execute(){
    //the selected number of armies is moved from the source to the target territory.
    if(validate() == true){
        target->setNumberOfSoldiers(*target->getNumberOfSoldiers() + *getArmies());
        source->setNumberOfSoldiers(*source->getNumberOfSoldiers() - *getArmies());
        cout << "AIRLIFT EXECUTE: " << target->getTerritoryName() << " now has " << target->getNumberOfSoldiers() << " and " << source->getTerritoryName() << " now has "<<source->getNumberOfSoldiers()<<endl;
    }
}

/*-------------------------------------------------------------------------*/
//NEGOTIATE Class

/*Default Constructor*/
Negotiate::Negotiate(){
    name = new string("Negotiate");
    this->target = new Territory;
    this->player = new Player;
    this->enemy = new Player;
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
Territory* Negotiate::getTargetTerr(){
    return this->target;
}

Player* Negotiate::getPlayer(){
    return this->player;
}

Player* Negotiate::getEnemy(){
    return this->enemy;
}

/*Setters*/
void Negotiate::setTargetTerr(Territory* target1){
   this->target = target1;
}

void Negotiate::setPlayer(Player* player){
    this->player = player;
}

void Negotiate::setEnemy(Player* enemy){
    this->enemy = enemy;
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
bool Negotiate::validate(){
    int* position = 0;
    bool ptr = true;
    for(int i = 0; i < getPlayer()->getSizeOfHand(); i++){
       if(getPlayer()->getCards()->getCard(i)->getType() != Type::blockade){
        ptr = false;
       }
       else if(getPlayer()->getCards()->getCard(i)->getType() == Type::blockade)
        ptr = true;
        *position = i;
        cout << "NEGOTIATE CARD VALIDATE: Card in hand."<< endl;
    }
    if(ptr == false){
        cout<< "NEGOTIATE INVALID: you do not own this card" <<endl;
        return ptr;
    }
    //If the target is the player issuing the order, then the order is invalid.
    if(*target->getPosessor() != getPlayer()->getPlayerID()){
        ptr = false;
    }
    else{
        ptr = true;
        cout << "NEGOTIATE VALID"<< endl;
        getPlayer()->getCards()->removeCard(position);
    }
    return ptr;
}

/*Execute Order method*/
void Negotiate::execute(){
    if(validate() == true){
        getPlayer()->setNegotiateID(getEnemy()->getPlayerID());
        getEnemy()->setNegotiateID(getPlayer()->getPlayerID());
        cout << "NEGOTIATE EXECUTE: Player " << getPlayer()->getPlayerID() << " is in negotiation with " << getEnemy()->getPlayerID();
        cout <<"All attacks between them will be stopped for this turn."<<endl; 
    }
}

/*-------------------------------------------------------------------------*/
//OrdersList Class

/*Default Constructor*/
OrdersList::OrdersList(){
    this->size = new int(5);
    orders = new Order* [*size];
    this->end = new int(0);

}

/*Paramaterized Constructor*/
OrdersList::OrdersList(int* size){
    this->size =  new int(*size);
    orders = new Order* [*size];
    this->end = new int(0);
}

/*Copy Constructor*/
OrdersList::OrdersList(const OrdersList& e){
    this->size = new int(*(e.size));
    this->orders = new Order*();
    this->end = new int(*(e.end));
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
    *this->end = *e.end;
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
    else{
        orders[position] = newOrder;
    }
    *this->end = *this->end + 1;   
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
        *this->end = *this->end - 1;
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
    *this->size = *size;
}

void OrdersList::validate(){
    for(int i = 0; i < *getSize(); i++){
        orders[i]->validate();
    }
}

void OrdersList::execute(){
    for(int i = 0; i < *this->end; i++){
        orders[i]->execute();
    }
}

Order* OrdersList::getOrder(int i){
    return orders[i];
}
