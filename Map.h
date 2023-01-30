#pragma once
#include "Territory.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// Author: Daniel

//TODO: Merge Territory class into here; component should be just the Map.h and Map.cpp duo

class Map{
private:
    int** adjacencyMatrix;      //2d array for the adjacency between all countries
    int* nbTeritories;          //Number of teritories, passed by MapLoader
    Territory* countries;       //Array of all countries

public:
    Map(int* nbTeritories);
    ~Map();

    void addEdge(int x, int y);     
    void dfs(int x, int* visied);  
    bool validate(); 
    void toString();  

    void setCountries(Territory arr[]);    
};

class MapLoader{
private:
    Map* map;                           //Map object to store the map   
    Territory* countries;               //Array of all countries  
    int* nbTeritories;                  //Number of teritories, passed by MapLoader

public:
    MapLoader(string fielName);
    ~MapLoader();

    Map* getMap();
    void readCountries(string fileName);
    void readBorders(string fileName);
};