#include "Orders.h"
#include <iostream>
#include <string>
using namespace std;

//Order Class (PARENT)

Order::Order(){} //default constructor

Order::Order(const Order& e){ //copy constructor
    this->name = new string(*(e.name));
}
Order& Order::operator=(const Order& e){ //assignmnet operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Order &a){ //insertion operator
    return strm << "Order(" << a.name << ")";
}

bool* Order::validate(){
    cout << "Validating class: Order\n";
    bool* ptr = new bool(true);
    return ptr;
}

void Order::execute(){
    cout << "Executing class: Order\n";
}

string* Order::description(){
    name = new string("Order - Parent");
    return this->name;
}

Order::~Order(){} //destructor

//Deploy Class

Deploy::Deploy(){} //default constructor

Deploy::Deploy(const Deploy& e){ //copy constructor
    this->name = new string(*(e.name));
}

Deploy& Deploy::operator=(const Deploy& e){ //assignment operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Deploy &a){ //instertion operator
    return strm << "Deploy(" << a.name << ")";
}

bool* Deploy::validate(){
    cout << "Validating class: Deploy\n";
     bool* ptr = new bool(true);
    return ptr;
}

void Deploy::execute(){
    cout << "Executing class: Deploy\n";
}


string* Deploy::description(){
    name = new string("Deploy");
    return this->name;
}

Deploy::~Deploy(){} //destructor

//Advance Class

Advance::Advance(){} //default constructor

Advance::Advance(const Advance& e){ //copy constructor
    this->name = new string(*(e.name));
}

Advance& Advance::operator=(const Advance& e){ //assignment operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Advance &a){ //instertion operator
    return strm << "Advance(" << a.name << ")";
}

bool* Advance::validate(){
    cout << "Validating class: Advance\n";
    bool* ptr = new bool(true);
    return ptr;
}

void Advance::execute(){
    cout << "Executing class: Advance\n";
}

string* Advance::description(){
    name = new string("Advance");
    return this->name;
}

Advance::~Advance(){} //destructor

//Bomb Class

Bomb::Bomb(){} //default constructor

Bomb::Bomb(const Bomb& e){ //copy constructor
    this->name = new string(*(e.name));
}

Bomb& Bomb::operator=(const Bomb& e){ //assignmnet operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Bomb &a){ //instertion operator
    return strm << "Bomb(" << a.name << ")";
}

bool* Bomb::validate(){
    cout << "Validating class: Bomb\n";
    bool* ptr = new bool(true);
    return ptr;
}

void Bomb::execute(){
    cout << "Executing class: Bomb\n";
}

string* Bomb::description(){
    name = new string("Bomb");
    return this->name;
}

Bomb::~Bomb(){} //destructor

//Blockade Class

Blockade::Blockade(){} //default constructor

Blockade::Blockade(const Blockade& e){ //copy constructor
    this->name = new string(*(e.name));
}

Blockade& Blockade::operator=(const Blockade& e){//assignmnet operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Blockade &a){ //instertion operator
    return strm << "Blockade(" << a.name << ")";
}

bool* Blockade::validate(){
    cout << "Validating class: Blockade\n";
     bool* ptr = new bool(true);
    return ptr;
}

void Blockade::execute(){
    cout << "Executing class: Blockade\n";
}

string* Blockade::description(){
    name = new string("Blockade");
    return this->name;
}

Blockade::~Blockade(){} //destructor


//Airlift Class

Airlift::Airlift(){} //default constructor

Airlift::Airlift(const Airlift& e){ //copy constructor
    this->name = new string(*(e.name));
}

Airlift& Airlift::operator=(const Airlift& e){//assignmnet operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Airlift &a){ //instertion operator
    return strm << "Airlift(" << a.name << ")";
}

bool* Airlift::validate(){
    cout << "Validating class: Airlift\n";
     bool* ptr = new bool(true);
    return ptr;
}

void Airlift::execute(){
    cout << "Executing class: Airlift\n";
}

string* Airlift::description(){
    name = new string("Airlift");
    return this->name;
}

Airlift::~Airlift(){} //destructor

//Negotiate Class

Negotiate::Negotiate(){} //default constructor

Negotiate::Negotiate(const Negotiate& e){ //copy constructor
    this->name = new string(*(e.name));
}

Negotiate& Negotiate::operator=(const Negotiate& e){ //assignmnet operator
    this->name = new string(*(e.name));
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Negotiate &a){ //instertion operator
    return strm << "Negotiate(" << a.name << ")";
}

bool* Negotiate::validate(){
    cout << "Validating class: Negotiate\n";
    bool* ptr = new bool(true);
    return ptr;
}

void Negotiate::execute(){
    cout << "Executing class: Negotiate\n";
}

string* Negotiate::description(){
    name = new string("Negotiate");
    return this->name;
}

Negotiate::~Negotiate(){} //destructor


//OrdersList Class

OrdersList::OrdersList(){} //default constructor

OrdersList::OrdersList(int* size){
    setSize(size);
    orders = new Order* [*size];
}

OrdersList::OrdersList(const OrdersList& e){ //copy constructor
    this->size = new int(*(e.size));
    this->orders = new Order*();
}

OrdersList& OrdersList::operator=(const OrdersList& e){ //assignmnet operator
    this->size = new int(*(e.size));
    this->orders = new Order*();
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const OrdersList &a){ //instertion operator
    return strm << "OrdersList(" << a.orders << ")";
}

void OrdersList::addOrder(Order* newOrder, int position){
    if(position > *getSize()){
        int* oldSize = getSize();
        resize();
        orders[*oldSize] = newOrder;
        showList();
        
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

void OrdersList::showList(){
    for(int i = 0; i < *getSize(); i++){
            cout << *orders[i]->description() << endl;
        }
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
OrdersList::~OrdersList(){
} //destructor