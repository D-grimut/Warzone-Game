#include "Map.h"
#include <iostream>

int main(int argc, char const *argv[]){

    //Invalid file
    cout << "Testing an INVALID file - wrong format:\n ";
    MapLoader* invalidMap = new MapLoader("C:\\Users\\user1\\Desktop\\yes.txt");
    cout << "---------------------------------------\n" << endl;

    //Inavlid map - duplicate country
    cout << "Testing an INVALID file - duplicate country:\n ";
    MapLoader* invalidMap2 = new MapLoader("C:\\Users\\user1\\Desktop\\canada-invalid.map");
    cout << "---------------------------------------\n" << endl;

    //Inavlid map - unused continent
    cout << "Testing an INVALID file - unused continent (not conected continent): \n";
    MapLoader* invalidMap3 = new MapLoader("C:\\Users\\user1\\Desktop\\canada-invalid - Copy.map");
    cout << "---------------------------------------\n" << endl;

    //Valid map 
    cout << "Testing an VALID file: \n";
    MapLoader* validMap = new MapLoader("C:\\Users\\user1\\Desktop\\bigeurope.map");  
    cout << "---------------------------------------\n" << endl;

    //Valid map
    cout << "Testing an VALID file: \n";
    MapLoader* validMap1 = new MapLoader("C:\\Users\\user1\\Desktop\\canada.map");
    cout << "---------------------------------------\n" << endl;

    //Valid map
    cout << "Testing an VALID file: \n";
    MapLoader* validMap2 = new MapLoader("C:\\Users\\user1\\Desktop\\GTA_SAN_AN.map");
    cout << "---------------------------------------\n" << endl;

    //Demonstrating use of valid map print function
    cout << *validMap2->getMap() << endl;    
    
    return 0;
}
