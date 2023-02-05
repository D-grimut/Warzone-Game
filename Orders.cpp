#include "Orders.h"
#include <iostream>
#include <string>
using namespace std;



//PARENT: ORDERS
//default
Orders::Orders(){
    name = "No action";
}
//overload
Orders::Orders(string name1){
    name = name1;
}

//Accessor
string Orders::getName() {
    return name;
}

//Mutator
void Orders::setName(string newName){
    name = newName;
}

bool Orders::execute(){
    cout << "Executing " << getName();
    return true;
}

bool Orders::validate(){
    cout << "Validating " << getName();
    return true;
}


//DEPLOY
//default
Deploy::Deploy() : Orders(){
}
//overload
Deploy::Deploy(string name1) : Orders() {
    name = name1;
}

//Accessor
string Deploy::getName() {
    return name;
}

//Mutator
void Deploy::setName(string newName){
    name = newName;
}

//ADVANCE
Advance::Advance() : Orders(){
}

Advance::Advance(string newName) : Orders(){
    name = newName;
}

//Accessor
string Advance::getName() {
    return name;
}

//Mutator
void Advance::setName(string newName){
    name = newName;
}

//BOMB
Bomb::Bomb() : Orders(){
}

Bomb::Bomb(string newName) : Orders(){
    name = newName;
}
//Accessor
string Bomb::getName() {
    return name;
}

//Mutator
void Bomb::setName(string newName){
    name = newName;
}

//BLOCKADE
Blockade::Blockade() : Orders(){
}

Blockade::Blockade(string newName) : Orders(){
    name = newName;
}

//Accessor
string Blockade::getName() {
    return name;
}

//Mutator
void Blockade::setName(string newName){
    name = newName;
}

//AIRLIFT
Airlift::Airlift() : Orders(){
}

Airlift::Airlift(string newName) : Orders(){
    name = newName;
}

//Accessor
string Airlift::getName() {
    return name;
}

//Mutator
void Airlift::setName(string newName){
    name = newName;
}

//NEGOTIATE
Negotiate::Negotiate() : Orders(){
}

Negotiate::Negotiate(string newName) : Orders(){
    name = newName;
}

//Accessor
string Negotiate::getName() {
    return name;
}

//Mutator
void Negotiate::setName(string newName){
    name = newName;
}

OrdersList::OrdersList(){};

OrdersList::OrdersList(int* const size ){
    Orders* orderList[*size];
}

void OrdersList::add(Orders* a1){
    int i = 0;
    while(orderList[i]){
        i++;
    }
    orderList[i] = a1;
}

Orders OrdersList::getArray(int i){
    return *orderList[i];
}

void OrdersList::move(int* position1, int* position2){
    if(*position2 < getsize() && *position1 != *position2){
        if(*position1 < *position2){
            int temp = *position1;
            for(int i = *position1; i < *position2; i++){
                this[i] = this[i + 1];
            }
            *position2 = temp;
        }
        if(*position1 > *position2){
            int temp = *position1;
            for(int i = *position1; i > *position2; i--){
                this[i] = this[i - 1];
            }
            *position2 = temp;
        }
    }
}

void OrdersList::remove(int* position){
    this[*position] = NULL;
    for(int i = 0; i < getsize(); i++){
        this[i] = this[i + 1];
        int* newSize;
        *newSize = getsize()-1;
        setSize(newSize);
    }
}

void OrdersList::resize(){
    int* newSize;
    *newSize = getsize() * 2;
    OrdersList newOrderList(newSize);
}

bool OrdersList::needResize(int count){
    if(count > getsize()){
        return true;
    }
    return false;
}

int OrdersList::getsize(){
    return *size;
}

void OrdersList::setSize(int* newSize){
    this->size = newSize;
}
