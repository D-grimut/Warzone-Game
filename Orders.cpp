#include "Orders.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;

//default
Orders::Orders(){
    name = "No action";
}
//overload
Orders::Orders(string name1){
    name = name1;
}

//Accessor
string Orders::getName() const {
    return name;
}

//Mutator
void Orders::setName(string newName){
    name = newName;
}

void Orders::execute(){
    cout << "Executing ";
}

bool Orders::validate(){
    cout << "Validating ";
}

//default
Deploy::Deploy() : Orders(){
}
//overload
Deploy::Deploy(string name1) {
    name = name1;
}

//Accessor
string Deploy::getName() const {
    return name;
}

//Mutator
void Deploy::setName(string newName){
    name = newName;
}


Advance::Advance() 