#include "Map.h"
#include <iostream>
using namespace std;

//Authors: Daniel & Nico

/*---------------- Map class ----------------*/ 
Map::Map(int nbTeritories, int nbContinents){  
    
    this->nbTeritories = new int(nbTeritories);   
    this->nbContinents = new int(nbContinents);  
       
    //Making the adjacencyMtrix 2d array
    this->adjacencyMatrix = new int*[nbTeritories];
    for(int i = 0; i < nbTeritories; i++){
        adjacencyMatrix[i] = new int[nbTeritories];
    }
}

//Default constructor
Map::Map(){    
    this->nbTeritories = NULL;
    this->nbContinents = NULL;
    this->adjacencyMatrix = NULL;    
}

//Copy constructor
Map::Map(const Map& og){    
    this->nbTeritories = new int(*og.nbTeritories);
    this->nbContinents = new int(*og.nbContinents);
    this->adjacencyMatrix = new int*[*nbTeritories];
    this->continents = new string[*nbContinents];
    this->countries = new Territory[*nbTeritories];
    
    //Creating new adjacency matrix
    for(int i = 0; i < *nbTeritories; i++){
        adjacencyMatrix[i] = new int[*nbTeritories];

        //Copying elemnts from old map adjacency matrix to this one
        for(int s = 0; s < *nbTeritories; s++){
            adjacencyMatrix[i][s] = og.adjacencyMatrix[i][s];
        }
    }

    //Copying the territories array
    for(int s = 0; s < *nbTeritories; s++){
        countries[s] = og.countries[s];
    }

    //Copying the continents array
    for(int s = 0; s < *nbContinents; s++){
        continents[s] = og.continents[s];
    }   
}

//Destructor
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

//Adds edge between two nodes
void Map::addEdge(int x, int y){    
    this->adjacencyMatrix[x][y] = 1;
    this->adjacencyMatrix[y][x] = 1;
}

//Helper method to traverse the graph (DFS)
void Map::dfs(int node, bool* visited, bool* visitedCon, int& ct, int& cc){
    
    visited[node] = true;
    ct++;    

    //Counting number of continents - for continent connectivity
    if(!visitedCon[*this->countries[node].getContinentId()]){
        visitedCon[*this->countries[node].getContinentId()] = true;
        cc++;
    }
    
    for(int i = 0; i < *this->nbTeritories; i++){
       
        if(this->adjacencyMatrix[node][i] == 1 && !visited[i]){            
            dfs(i, visited, visitedCon, ct, cc);
        }
    }
}

//Validate validates if map object is a valid map
//Note: the method checks for graph and continent connectivity in the same DFS sweep.
bool Map::validate(){ 
    
    bool* visits = new bool[*nbTeritories];
    bool* continentVisits = new bool[*nbContinents];
    bool isUnique = true;

    unordered_map<string, int> hashmap;

    //Assuring that visited array is created properly - that is the array has only false values at the start
    for (int i = 0; i < *this->nbTeritories; i++){
        visits[i] = false;
    }

    //Assuring that continentVisits array is created properly - that is the array has only false values at the start
    for (int i = 0; i < *this->nbContinents; i++){
        continentVisits[i] = false;
    }
    //Teritory counter
    int counterT = 0;

    //Continent counter
    int counterC = 0;    

    dfs(0, visits, continentVisits, counterT, counterC);     

    //Deleting visits array; we only need the array for dfs/ validation
    delete visits;
    delete continentVisits;      

    //Only way we can have a country that has 2 continents, is to have a duplicate country, in which case it is an invalid map
    for(int i = 0; i < *this->nbTeritories; i++){      

        if((++hashmap[*this->countries[i].getTerritoryName()]) > 1){
            isUnique = false;
            break;
        }
    }

    //Testing Graph conectivity (if all territories are connected)
    if(counterT == *this->nbTeritories && counterC == *this->nbContinents && isUnique){
        return true;

    }else{
        return false;
    }   
}

//Setter
void Map::setCountries(Territory arr[]){
    this->countries = arr;
}

//Operator overloading for a map
Map& Map::operator=(const Map& og){

    this->nbTeritories = new int(*og.nbTeritories);
    this->nbContinents = new int(*og.nbContinents);
    this->adjacencyMatrix = new int*[*og.nbTeritories];

    //Creating new adjacency matrix
    for(int i = 0; i < *nbTeritories; i++){
        this->adjacencyMatrix[i] = new int[*nbTeritories];

        //Copying elemnts from old map adjacency matrix to this one
        for(int s = 0; s < *nbTeritories; s++){
            adjacencyMatrix[i][s] = og.adjacencyMatrix[i][s];
        }
    }

    return *this;
}

//Printing a map
std::ostream& operator<<(std::ostream &strm, const Map &m){

    string res = "";
    for (int i = 0; i < *m.nbTeritories; i++)
    {
        res += ("The country is " + *m.countries[i].getTerritoryName() + "we need " + to_string(*m.countries[i].getAmntToInvade()) + " soldiers to invade - The neighbhors are : ");       

        for (int s = 0; s < *m.nbTeritories; s++)
        {
            if (s == i)
            {
                continue;
            }

            if (m.adjacencyMatrix[i][s] != 1)
            {
                continue;
            }

            res += *m.countries[s].getTerritoryName();             
        }
         
        res += "\n\n";
    }

    return strm << res << endl;
}

/*---------------- Map Loader class ----------------*/ 

//Map Loader contructor that loads the map
MapLoader::MapLoader(string fileName){  
    
    this->nbTeritories = new int(countEntities(fileName, "[countries]"));
    this->nbContinents = new int(countEntities(fileName, "[continents]"));    

    if(*this->nbTeritories <= 0 || *this->nbContinents <=0){
        cout << "Map is in an invalid format, rejecting map" << endl;

    }else{
        //Creating empty continent array   
        string continentsArr[*this->nbContinents];
        this->continents = continentsArr;

        this->contInvade = new int[*nbContinents];

        //Creating empty teritorry array and empty map    
        this->countries = new Territory[*this->nbTeritories];     
        this->map = new Map(*nbTeritories, *nbContinents);    
        this->map->setCountries(this->countries);       //Its ok to share the countries array (shallow copy), since there should ever be only one countries array

        readContinents(fileName);
        readCountries(fileName);    
        readBorders(fileName);       

        if(!this->map->validate()){
           cout << "Map is invalid; failed validation() method - rejecting map" << endl;
           
        }else{
            cout << "Map is valid!" << endl;
        }
    }  
}

//Map Loader destructor
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

//Method to read the countries in the .map file
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
                    this->countries[counter].setAmntToInvade(this->contInvade[stoi(propArr[2]) - 1]);
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

//Method to read the borders between countries and hence formulate the map (adding edges)
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

//Reading the continents in the .map file
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
                    this->contInvade[counter] = stoi(propArr[1]);
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

Map* MapLoader::getMap(){
    return this->map;
}

/*---------------- Territory Class ----------------*/

//Constructor
Territory::Territory(int posessor, string TerritoryName, int TerritoryId, bool isFree, int continentId, int amntToInvade, int numberOfSoldiers){
    this->posessor = new int(posessor);
    this->TerritoryName = new string(TerritoryName);
    this->TerritoryId = new int(TerritoryId);    
    this->isFree = new bool(isFree);
    this->continentId = new int(continentId);
    this->amntToInvade = new int(amntToInvade);
    this->numberOfSoldiers = new int(numberOfSoldiers);    
}

//Default Consructor
Territory::Territory(){
    this->posessor = new int(-1);
    this->TerritoryName = new string("");
    this->TerritoryId = new int(-1);    
    this->isFree = new bool(true);
    this->continentId = new int(-1);
    this->amntToInvade = new int(-1);
    this->numberOfSoldiers = new int(-1);
}

//Copy Cinstructor
Territory::Territory(const Territory& og){
    this->posessor = new int(*og.posessor);
    this->TerritoryName = new string(*og.TerritoryName);
    this->TerritoryId = new int(*og.TerritoryId);    
    this->isFree = new bool(*og.isFree);
    this->continentId = new int(*og.continentId);
    this->amntToInvade = new int(*og.amntToInvade);
    this->numberOfSoldiers = new int(*og.numberOfSoldiers);
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

    delete this->amntToInvade;
    this->amntToInvade = NULL;

    delete this->numberOfSoldiers;
    this->numberOfSoldiers = NULL;  
}

Territory& Territory::operator=(const Territory& t) {

    this->setContinentId(*t.continentId);
    this->setName(*t.TerritoryName);
    this->setPosessor(*t.posessor);
    this->setStatus(*t.isFree);
    this->setTerritoryId(*t.TerritoryId);
    this->setNumberOfSoldiers(*t.numberOfSoldiers);
    this->setAmntToInvade(*t.amntToInvade);
   
    return *this;
}

std::ostream& operator<<(std::ostream &strm, const Territory &t){

    return strm << "The territorie name: " << t.TerritoryName << " , is occupied: " << t.isFree << ", amnt of soldiers: " << t.numberOfSoldiers
                << ", amount to invade: " << t.amntToInvade << ", id of player possesing it: " << t.posessor << endl;
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

bool* Territory::getIsFree(){
    return this->isFree;
}

string* Territory::getTerritoryName(){
    return this->TerritoryName;
}

int* Territory::getAmntToInvade(){
    return this->amntToInvade;
}

int* Territory::getNumberOfSoldiers(){
    return this->numberOfSoldiers;
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

void Territory::setAmntToInvade(int amnt){
    *this->amntToInvade = amnt;
}

void Territory::setNumberOfSoldiers(int amnt){
    *this->numberOfSoldiers = amnt;
}