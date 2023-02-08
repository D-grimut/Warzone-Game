#include "Orders.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Order Class (PARENT)

Order::Order(){} //default constructor

bool* Order::validate(){
    cout << "Validating class: Order";
    bool* ptr = new bool(true);
    return ptr;
}

void Order::execute(){
    cout << "Executing class: Order";
}

string* Order::description(){
    name = new string("Order - Parent");
    return this->name;
}

Order::~Order(){} //destructor

//Deploy Class

Deploy::Deploy(){} //default constructor

bool* Deploy::validate(){
    cout << "Validating class: Deploy";
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

bool* Advance::validate(){
    cout << "Validating class: Advance";
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

bool* Bomb::validate(){
    cout << "Validating class: Bomb";
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

bool* Blockade::validate(){
    cout << "Validating class: Blockade";
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

bool* Airlift::validate(){
    cout << "Validating class: Airlift";
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

bool* Negotiate::validate(){
    cout << "Validating class: Negotiate";
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


void OrdersList::addOrder(Order* order){
   orders.push_back(order); 
}

void OrdersList::moveOrder(int* position1, int* position2){
    if(*position1 > orders.size() || *position2 > orders.size()){
            cout << "Invalid remove, please enter a number less than: " << orders.size() <<endl;
        }
    Order* temp = orders[*position1];
    orders.erase(orders.begin() + *position1);
    orders.insert(orders.begin() + *position2, temp);
}

void OrdersList::removeOrder(int* position){
        if(*position > orders.size()){
            cout << "Invalid remove, please enter a number less than: " << orders.size() <<endl;
        }
        orders.erase(orders.begin() + *position);
}

void OrdersList::showList(){
    for(int i = 0; i < orders.size(); i++){
            cout << *orders.at(i)->description()  << endl;
        }
}

int OrdersList::getSize(){
    return orders.size();
}

void OrdersList::validate(){
    for(int i = 0; i < orders.size(); i++){
        cout << *orders.at(i)->validate() << endl;
    }
}

void OrdersList::execute(){
    for(int i = 0; i < orders.size(); i++){
        orders.at(i)->execute();
    }
}
OrdersList::~OrdersList(){} //destructor