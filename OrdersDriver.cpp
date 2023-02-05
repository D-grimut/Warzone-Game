#include <iostream>
#include <string>
#include "Orders.h"
using namespace std;

int main(){
    Deploy* dep;
    Deploy d1("deploy");
    *dep = d1;

    Advance* ad;
    Advance a1("advance");
    *ad = a1;
    
    Bomb* bo1;
    Bomb b1("bomb");
    *bo1 = b1;

    Blockade* blo1;
    Blockade bl1("blockade");
    *blo1 = bl1;

    Airlift* ar;
    Airlift ar1("airlift");
    *ar = ar1;

    Negotiate* ne;
    Negotiate n1("negotiate");
    *ne = n1;

    int* size;
    *size = 6;
    OrdersList newList(size);
    newList.add(dep);
    newList.add(ad);
    newList.add(bo1);
    newList.add(blo1);
    newList.add(ar);
    newList.add(ne);
    cout << newList.getsize();
    cout << "Full List of Orders: \n";
     for(int i = 0; i < newList.getsize(); i++){
        cout << newList.getArray(i).getName();
     }

    int* position1; 
    int* position2;
    *position1 = 0;
    *position2 = 3;
    newList.move(position1, position2);
    cout << "Full list of orders after moving position 1 to position 4: \n";
    for(int i = 0; i < newList.getsize(); i++){
        cout << newList.getArray(i).getName();
    }
    cout << "Full list of orders after removing position: \n";
    newList.remove(position2);
    for(int i = 0; i < newList.getsize(); i++){
        cout << newList.getArray(i).getName();
    }

    cout << "Validating: \n";
    for(int i = 0; i < newList.getsize(); i++){
        cout << newList.getArray(i).validate();
    }
    cout << "Executing: \n";
    for(int i = 0; i < newList.getsize(); i++){
        cout << newList.getArray(i).execute();
    }

    return 0;
}
