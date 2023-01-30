#pragma once
#include <string>
using namespace std;

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