#include "Map.h"
#include <iostream>
using namespace std;

//Authors: Daniel & Nico

/*---------------- Map class ----------------*/ 
Map::Map(int* nbTeritories, int* nbContinents){  
    
    this->nbTeritories = nbTeritories;   
    this->nbContinents = nbContinents;
    this->counter = new int(0);   
    
    //Making the adjacencyMtrix 2d array
    this->adjacencyMatrix = new int*[*nbTeritories];
    for(int i = 0; i < *nbTeritories; i++){
        adjacencyMatrix[i] = new int[*nbTeritories];
    }
}

Map::Map(){
    this->counter = 0;
    this->nbTeritories = NULL;
    this->nbContinents = NULL;
    this->adjacencyMatrix = NULL;    
}

Map::~Map(){
    delete this->nbContinents;
    this->nbContinents = NULL;

    delete this->nbTeritories;
    this->nbTeritories = NULL;

    for(int i = 0; i < *nbTeritories; i++){
        delete adjacencyMatrix[i];
        adjacencyMatrix[i] = NULL;
    }

    delete this->adjacencyMatrix;
    this->adjacencyMatrix = NULL;
}

void Map::addEdge(int x, int y){    
    this->adjacencyMatrix[x][y] = 1;
    this->adjacencyMatrix[y][x] = 1;
}

void Map::dfs(int node, bool* visited){
    
    visited[node] = true;
    (*this->counter)++;    
    
    for(int i = 0; i < *this->nbTeritories; i++){
       
        if(this->adjacencyMatrix[node][i] == 1 && !visited[i]){            
            dfs(i, visited);
        }
    }
}

//Validate validates if map object is a valid map
//Note: the method checks for graph and continent connectivity in the same DFS sweep.
bool Map::validate(){ 
    
    bool* visits = new bool[*nbTeritories];
    dfs(0, visits);   

    //Deleting visits array; we only need the array for dfs/ validation
    delete visits; 

    cout <<  *this->counter << endl;

    //Testing Graph conectivity (if all territories are connected)
    if(*this->counter == *this->nbTeritories){
        return true;

    }else{
        return false;
    }

    //TODO: Add validation for continents + Add validation for Countrt - Continent Relation; one country can have only one continent
}

void Map::toString(){
    for(int i = 0; i < *this->nbTeritories; i++){
        cout<< "The country is " << *this->countries[i].getTerritoryName() << " - The neighbhors are : ";

        for(int s = 0; s < *this->nbTeritories; s++){
            if(s == i){
                continue;
            }
           
            if(this->adjacencyMatrix[i][s] != 1){
                continue;
            }

            cout<< *this->countries[s].getTerritoryName() << ", ";
        }
        cout<< "\n" << endl;
    }
}

void Map::setCountries(Territory arr[]){
    this->countries = arr;
}

/*---------------- Map Loader class ----------------*/ 

MapLoader::MapLoader(string fileName){   
    
    this->nbTeritories = new int(countEntities(fileName, "[countries]"));
    this->nbContinents = new int(countEntities(fileName, "[continents]"));
   
    //Creating empty continent array   
    string continentsArr[*this->nbContinents];
    this->continents = continentsArr;

    //Creating empty teritorry array and empty map    
    this->countries = new Territory[*this->nbTeritories];     
    this->map = new Map(nbTeritories, nbContinents);    
    this->map->setCountries(this->countries);       //Its ok to share the countries array (shallow copy), since there should ever be only one countries array

    readContinents(fileName);
    readCountries(fileName);    
    readBorders(fileName);     
    //this->map->toString();                        //For debug - DELTE AT THE END 

    this->map->validate();
}

MapLoader::~MapLoader(){
    delete this->nbContinents;
    this->nbContinents = NULL;

    delete this->nbTeritories;
    this->nbTeritories = NULL;

    delete this->map;
    this->map = NULL;

    delete this->countries;
    this->countries = NULL;
}

//Helper method to count a certain type of entities in the .map file
int MapLoader::countEntities(string fileName, string enityType){

    ifstream mapFile(fileName); 
    int counter = 0;    
    string text;    

    //Counting nb of entities
    while(getline(mapFile, text)){
        if(text.compare(enityType) == 0){
            while(text.compare("") != 0){
                counter++;
                getline(mapFile, text);
            }
        }
    }
    mapFile.close();
    return (counter - 1);
}

//TODO: Add error checking/ validation if file is a valid map based of teltale signs
//like formating.

void MapLoader::readCountries(string fileName){

    ifstream file(fileName);  
    string text;
    int counter = 0;

    //Reading countries only
    while (getline(file, text)){
        if(text.compare("[countries]") == 0){

            while(text.compare("") != 0 || text.compare("[borders]") != 0){
                
                getline(file, text);
                
                //Array to store the territory properties to be parsed from the file
                //We may need to modify it later on if we will use the other .map info
                string propArr[3];

                //Spliting the string by tokens to create teritory object
                for(int i = 0, f = 0; i < text.length() && f < 3; i++, f++){

                    propArr[f] = splitString(text, i);
                }                  

                //We do -1 since the values read start from 1, and we want 
                //the ID to corespond to the position in the countries array.      
                if(counter < *this->nbTeritories){
                    this->countries[counter].setTerritoryId(stoi(propArr[0]) - 1);
                    this->countries[counter].setName(propArr[1]);                    
                    this->countries[counter].setContinentId(stoi(propArr[2]) - 1);
                    counter++;                 
                }else{
                    break;
                }                             
            }
            file.close();
            break;       
        }
    }    
}

void MapLoader::readBorders(string fileName){

    ifstream file(fileName);  
    string text; 
    int currCountry;            //Current country to which we are attributing the borders.  
    bool firstToken = true; 

    //Reading countries only
    while (getline(file, text)){       
        if(text.compare("[borders]") == 0){

            while(text.compare("") != 0){
                
                getline(file, text); 
                
                for(int i = 0; i < text.length(); i++){
                                        
                    string token = splitString(text, i);

                    if(firstToken){                        
                        firstToken = false;
                        currCountry = (stoi(token) - 1);
                    }else{                        
                        //Creating edge (border) between the current country we are possesing and its neighbhor.
                        this->map->addEdge(currCountry, (stoi(token) - 1));
                    }
                }
                firstToken = true;                                                            
            }
            file.close();
            break;       
        }        
    }    
}

void MapLoader::readContinents(string fileName){
    
    ifstream file(fileName);  
    string text; 
    int counter = 0; 

    while (getline(file, text)){       
        if(text.compare("[continents]") == 0){

            while(text.compare("") != 0 || text.compare("[countries]") != 0){
                
                getline(file, text); 

                //Array to store the continent properties to be parsed from the file
                //We may need to modify it later on if we will use the other .map info (color in this case)
                string propArr[2];

                //Spliting the string by tokens to create teritory object
                for(int i = 0, f = 0; i < text.length() && f < 2; i++, f++){

                    propArr[f] = splitString(text, i);                                      
                }
            
                if(counter < *this->nbContinents){
                    this->continents[counter] = propArr[0];
                    counter++;
                }else{                                      
                    break;
                }                
            }
            file.close();
            break; 
        }       
    }   
}

//Helper method to split the string by tokens
string MapLoader::splitString(string text, int &i){

    string token = "";
    while (text[i] != ' ' && i < text.length()){
        token += text[i];
        i++;
    }
    return token;
}

/*---------------- Teritory Class ----------------*/

//Constructor
Territory::Territory(int posessor, string TerritoryName, int TerritoryId, bool isFree, int continentId){

    this->posessor = new int(posessor);
    this->TerritoryName = new string(TerritoryName);
    this->TerritoryId = new int(TerritoryId);    
    this->isFree = new bool(isFree);
    this->continentId = new int(continentId);

    //These properties do not figure on the .map file so we comment them out for now
    //this->amntToInvade = new int(amntToInvade);
    //this->numberOfSoldiers = new int(numberOfSoldiers);
}

//Default Consructor
Territory::Territory(){
    this->posessor = new int(-1);
    this->TerritoryName = new string("");
    this->TerritoryId = new int(-1);    
    this->isFree = new bool(true);
    this->continentId = new int(-1);
}

//Destructor
Territory::~Territory(){
    delete this->posessor;
    this->posessor = NULL;

    delete this->TerritoryName;
    this->TerritoryName = NULL;

    delete this->TerritoryId; 
    this->TerritoryId = NULL;

    delete this->isFree;
    this->isFree = NULL;

    delete this->continentId;
    this->continentId = NULL;
    
    //delete this->amntToInvade;
    //this->amntToInvade = NULL;

    //delete this->numberOfSoldiers;
    //this->numberOfSoldiers = NULL;
}

int* Territory:: getPosessor(){
    return this->posessor;    
}

int* Territory::getTerritoryId(){
    return this->TerritoryId;
}

int* Territory::getContinentId(){
    return this->continentId;
}

// int* Territory::getAmntToInvade(){
//     return this->amntToInvade;
// }

// int* Territory::getNumberOfSoldiers(){
//     return this->numberOfSoldiers;
// }

bool* Territory::getIsFree(){
    return this->isFree;
}

string* Territory::getTerritoryName(){
    return this->TerritoryName;
}

//Setters
void Territory::setPosessor(int id){
    *this->posessor = id;
}

void Territory::setTerritoryId(int id){
    *this->TerritoryId = id;
}

void Territory::setStatus(bool stat){
    *this->isFree = stat;
}

void Territory::setName(string name){
    *this->TerritoryName = name;
}

void Territory::setContinentId(int id){
    *this->continentId = id;
}