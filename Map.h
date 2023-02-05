#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Author: Daniel

class Territory{
private:
    
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

};

class Map{
private:
    int** adjacencyMatrix;      //2d array for the adjacency between all countries
    int* nbTeritories;          //Number of teritories, passed by MapLoader
    int* nbContinents;          //Number of teritories, passed by MapLoader       
    string* continents;         //Array of all continents, where the index of the continent corresponds to its ID
    Territory* countries;       //Array of all countries

    void dfs(int, bool*, bool*, int&, int&);        //Helper Method for traversal - Depth's First Search

public:
    Map(int* nbTeritories, int* nbContinents);
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
    string* continents;                 //Array of all continents, where the index of the continent corresponds to its ID
    int* nbContinents;
    int* nbTeritories;                  //Number of teritories, passed by MapLoader

    string splitString(string token, int& index);                           //Helper method to split string by token when reading .map files
    int countEntities(string fileName, string entityType);                  //Helper method to count number of entities (countries or continents)
   
   
public:
    MapLoader(string fielName);
    MapLoader();
    ~MapLoader();
    
    Map* getMap();
    void readContinents(string fileName);
    void readCountries(string fileName);
    void readBorders(string fileName);
};
