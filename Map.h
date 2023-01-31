#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Author: Daniel

class Territory{
private:
    //TODO: Replace posser by the actual player object that poses this teritory or keep
    //Player ID (Discuss with tho ever is doing player class).
    
    int* posessor;              //Player object (todo), who posese the teritory
    string* TerritoryName;      //name of territory
    int* TerritoryId;           //index of teritory
    int* continentId;           //Index of countrie's continent
    bool* isFree;               //Occupation Status      

    //int* amntToInvade;          //Amnt of soldiers to invade country
    //int* numberOfSoldiers;      //Nb soldies on territory 

public:
    Territory(int posessor, string TerritoryName, int TerritoryId, bool isFree, int continentId);
    Territory();
    ~Territory();

    int* getPosessor();
    int* getTerritoryId();
    int* getContinentId();
    bool* getIsFree();
    string* getTerritoryName();

    void setPosessor(int id);
    void setContinentId(int id);
    void setTerritoryId(int id);
    void setStatus(bool stat);
    void setName(string name);

    // int* getAmntToInvade();
    // int* getNumberOfSoldiers();
};

class Map{
private:
    int** adjacencyMatrix;      //2d array for the adjacency between all countries
    int* nbTeritories;          //Number of teritories, passed by MapLoader    
    int* counter;               //Counter used to validate number of countries when calling validate()
    Territory* countries;       //Array of all countries

    void dfs(int x, bool* visied);        //Helper Method for traversal - Depth's First Search

public:
    Map(int* nbTeritories);
    Map();
    ~Map();

    void addEdge(int x, int y);  
    void toString();
     
    bool validate();   

    void setCountries(Territory arr[]);    
};

class MapLoader{
private:
    Map* map;                           //Map object to store the map   
    Territory* countries;               //Array of all countries  
    int* nbTeritories;                  //Number of teritories, passed by MapLoader

public:
    MapLoader(string fielName);
    MapLoader();
    ~MapLoader();

    Map* getMap();
    void readCountries(string fileName);
    void readBorders(string fileName);
};
