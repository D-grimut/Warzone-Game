#include <iostream>
#include <string>
#include "Orders.h"
using namespace std;

int main(){
    //Creating orders
    Order* dep = new Deploy();
    Order* ad = new Advance();
    Order* bo1 = new Bomb();
    Order* blo1 = new Blockade();
    Order* ar = new Airlift();
    Order* ne = new Negotiate();

    //Creating object OrderList to store orders, then adding them
    int* size = new int(6);
    OrdersList newList(size);
  
    newList.addOrder(dep, 0);
    //cout << 1 << endl;
    newList.addOrder(ad, 1);
    newList.addOrder(bo1, 2);
    newList.addOrder(blo1, 3);
    newList.addOrder(ar, 4);
    newList.addOrder(ne, 5);
 
    //Show full list
    cout << "\nList of orders:" << endl;
        newList.showList();

    //Call validate function (not implemented)
    cout <<"\nChecking validate: \n" <<endl;
    newList.validate();

    //call execute fn (not implemented)
    cout <<"\nChecking execute: \n" <<endl;
    newList.execute();

    //test moving positions
    cout <<"\nMoving from position 2 to position 5:\n" << endl; 
        int* position1 = new int(1);
        int* position2 = new int(4);
        newList.moveOrder(position1, position2);
        newList.showList();

    //test removing
    cout<<"\nRemoving position 3:\n" << endl;
        int* position = new int(2);
        newList.removeOrder(position);
        newList.showList();

    //testing resize
    cout <<"\nTesting resize:"<<endl;
    Order* newOrder = new Deploy();
    newList.addOrder(newOrder, 7);

    newList.~OrdersList();

    return 0;
}