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

    int* amntToInvade;          //Amnt of soldiers to invade country
    int* numberOfSoldiers;      //Nb soldies on territory 

public:
    
    //Constructors
    Territory(int posessor, string TerritoryName, int TerritoryId, bool isFree, int continentId, int amntToInvade, int nbSoldiers);
    Territory();
    Territory(const Territory&);
    ~Territory();

    //Getters
    int* getPosessor();
    int* getTerritoryId();
    int* getContinentId();
    bool* getIsFree();
    string* getTerritoryName();
    int* getAmntToInvade();
    int* getNumberOfSoldiers();

    //Setters
    void setPosessor(int id);
    void setContinentId(int id);
    void setTerritoryId(int id);
    void setStatus(bool stat);
    void setName(string name);
    void setAmntToInvade(int);
    void setNumberOfSoldiers(int);
    
    Territory& operator=(const Territory& e);
    friend std::ostream& operator<<(std::ostream &strm, const Territory& t);    
};

class Map{
private:
    Territory*** adjacencyMatrix;      //2d array for the adjacency between all countries
    int* nbTeritories;          //Number of teritories, passed by MapLoader
    int* nbContinents;          //Number of teritories, passed by MapLoader 
    Territory* countries;       //Array of all countries 

    void dfs(int, bool*, bool*, int&, int&);        //Helper Method for traversal - Depth's First Search
    friend std::ostream& operator<<(std::ostream &strm, const Map& m);    

public:
    Map(int nbTeritories, int nbContinents);    
    Map();
    Map(const Map& og);
    ~Map();

    bool isAdjacent(Territory terr1, Territory terr2);
    void addEdge(int x, int y, Territory*, Territory*);  
    void toString();     
    bool validate();
    void setCountries(Territory arr[]); 
    int* getNbTerritories();
    Territory* getCountries();
    Map& operator=(const Map&);   
    Territory*** getAdjacencyMatrix();
};

class MapLoader{
private:
    Map* map;                           //Map object to store the map   
    int* contInvade;                    //Array with the number of soldiers to invade in that continent   
    Territory* countries;               //Array of all countries  
    string* continents;                 //Array of all continents, where the index of the continent corresponds to its ID
    int* nbContinents;
    int* nbTeritories;                  //Number of teritories, passed by MapLoader

    string splitString(string token, int& index);                           //Helper method to split string by token when reading .map files
    int countEntities(string fileName, string entityType);                  //Helper method to count number of entities (countries or continents)
   
   
public:
    MapLoader(string fielName);    
    ~MapLoader();
    
    Map* getMap();
    void readContinents(string fileName);
    void readCountries(string fileName);
    void readBorders(string fileName);
};
