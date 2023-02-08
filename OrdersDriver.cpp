#include <iostream>
#include <vector>
#include <string>
#include "Orders.h"
using namespace std;

int main(){
    //Creating orders
    Deploy* dep = new Deploy();
    Advance* ad = new Advance();
    Bomb* bo1 = new Bomb();
    Blockade* blo1 = new Blockade();
    Airlift* ar = new Airlift();
    Negotiate* ne = new Negotiate();

    //Creating object OrderList to store orders, then adding them
    OrdersList newList;
    newList.addOrder(dep);
    newList.addOrder(ad);
    newList.addOrder(bo1);
    newList.addOrder(blo1);
    newList.addOrder(ar);
    newList.addOrder(ne);

    //Show full list
    cout << "\nFirst list\n" << endl;
        newList.showList();

    //Call validate function (not implemented)
    cout <<"\nChecking validate \n" <<endl;
        newList.validate();

    //call execute fn (not implemented)
    cout <<"\nChecking execute \n" <<endl;
        newList.execute();

    //test moving positions
    cout <<"\nMoving from position 2 to position 5\n" << endl; 
        int* position1 = new int(1);
        int* position2 = new int(4);
        newList.moveOrder(position1, position2);
        newList.showList();

    //test removing
    cout<<"\nRemoving position 3\n" << endl;
        int* position = new int(2);
        newList.removeOrder(position);
        newList.showList();

  
    return 0;



}