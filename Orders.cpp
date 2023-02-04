#include "Orders.h"
#include <iostream>
#include<string>
using namespace std;


OrdersList::OrdersList(){};

OrdersList::OrdersList(int* size ){
    Orders* orderList[*size];
}

void OrdersList::move(int* position1, int* position2){

}

void OrdersList::remove(int* position){

}




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

void Orders::execute(){
    cout << "Executing " << getName();
}

bool Orders::validate(){
    cout << "Validating ";
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