#include <iostream>
#include <vector>
#include <string>
#include "Orders.cpp"
#include "Orders.h"
using namespace std;

void fillVector(vector<Orders>&);
//Fill the vector - fills in the orders

int main(){

    Deploy d1("deploy");
    Advance a1("advance");
    Bomb b1("bomb");
    Blockade bl1("blockade");
    Airlift ar1("airlift");
    Negotiate n1("negotiate");

    vector<Orders> vectorOrder = {d1, a1, b1, bl1, ar1, n1};

    for(int i = 0; i < vectorOrder.size(); i++){
        vectorOrder[i].execute();
    }
}

void fillVector(vector<Orders>& newOrder){
    
}