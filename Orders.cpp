#include "Orders.h"
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

string Order::getName(){
   return *this->name;
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
    cout << "Validating class: Deploy\n";
     bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Deploy::execute(){
    cout << "Executing class: Deploy\n";
}

/*Description: Returns name of order*/
string* Deploy::description(){
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
    cout << "Validating class: Advance\n";
    bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Advance::execute(){
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
    cout << "Validating class: Bomb\n";
    bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Bomb::execute(){
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
    cout << "Validating class: Blockade\n";
     bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Blockade::execute(){
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
    cout << "Validating class: Airlift\n";
     bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Airlift::execute(){
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
    cout << "Validating class: Negotiate\n";
    bool* ptr = new bool(true);
    return ptr;
}

/*Execute Order method*/
void Negotiate::execute(){
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

/*First checks if the position is out of bounds of the array,
* Resizes if needed
* Adds order at index [position]
*/
void OrdersList::addOrder(Order* newOrder, int position){
    if(position > *getSize()){
        int* oldSize = getSize();
        resize();
        orders[*oldSize] = newOrder;        
    }
    else
        orders[position] = newOrder;
}

/*Creates a new array of size (size+1), then copied all elements from the old array
* Deletes old array and assigns pointer to new array
*/
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

/*Checks where position1 and position2 are
* moves all positions according to comparison
* moves position1 to position2
*/
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

/*Checks if position is a valid index
* Moves index over, reduces size
*/
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

/*Iterates through the array, printing description (name) of each order in the array*/
void OrdersList::showList(int x){
    for(int i = 0; i < x; i++){
        string s = orders[i]->getName();
        if(s.compare("0") == 1){
            break;
        }
         cout <<*orders[i]->description() << endl;
    }
}

/*Returns int* of the size of the array*/
int* OrdersList::getSize(){
    return this->size;
}

/*Sets size of the array to an int* */
void OrdersList::setSize(int* size){
    this->size = size;
}

/*Iterates through array and validates each order object*/
void OrdersList::validate(){
    for(int i = 0; i < *getSize(); i++){
        orders[i]->validate();
    }
}

/*Iterates through array and executes each order object*/
void OrdersList::execute(){
    for(int i = 0; i < *getSize(); i++){
        orders[i]->execute();
    }
}