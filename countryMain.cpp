#include "Map.h"
#include <iostream>

int main(int argc, char const *argv[]){

    //Invalid file
    //MapLoader* invalidMap = new MapLoader("C:\\Users\\user1\\Desktop\\yes.txt");

    //Valid file - BUT because it has 180 countries DFS does not lacks concistency (idk why
    //c++ is wierd)
    //MapLoader* validMap = new MapLoader("C:\\Users\\user1\\Desktop\\bigeurope.map");  

    //Valid map - WORK
    MapLoader* validMap = new MapLoader("C:\\Users\\user1\\Desktop\\canada.map");

    //Valid map - NOT WORK
    MapLoader* validMap2 = new MapLoader("C:\\Users\\user1\\Desktop\\GTA_SAN_AN.map");
    return 0;
}
