#include "Map.h"
#include <iostream>
#include <vector>
using namespace std;

//Authors: Daniel & Nico

/*---------------- Map class ----------------*/ 
Map::Map(int* nbTeritories){
   
    this->nbTeritories = nbTeritories;    

    //Making the adjacencyMtrix 2d array
    this->adjacencyMatrix = new int*[*nbTeritories];
    for(int i = 0; i < *nbTeritories; i++){
        adjacencyMatrix[i] = new int[*nbTeritories];
    }
}

void Map::addEdge(int x, int y){    
    this->adjacencyMatrix[x][y] = 1;
    this->adjacencyMatrix[y][x] = 1;
}

void Map::dfs(int x, int* visited){
    //Implement DFS (DFS since its easy to do recursively - no need to make a stack)
}

bool Map::validate(){
    //Implement DFS (DFS since its easy to do recursively - no need to make a stack)
    return true;
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

    ifstream mapFile(fileName);    

    int counter = 0;    //Counter to count nb of files

    string text;

    //Counting nb of countries
    while(getline(mapFile, text)){
        if(text.compare("[countries]") == 0){
            while(text.compare("") != 0){
                counter++;
                getline(mapFile, text);
            }
        }
    }
    counter -= 1;
    this->nbTeritories = &counter;
    mapFile.close(); 

    Territory terArr[*nbTeritories];    
    this->countries = terArr;     
    this->map = new Map(nbTeritories);
    this->map->setCountries(this->countries);       //Its ok to share the countries array (shallow copy), since there should ever be only one countries array

    readCountries(fileName);
    
    //Everything works up until now! Yipee!

    readBorders(fileName);   
    this->map->toString();    
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

            while(text.compare("") != 0){
                
                getline(file, text);
                
                //Array to store the territory properties to be parsed from the file
                //We may need to modify it later on if we will use the other .map info
                string propArr[3];

                //Spliting the string by tokens to create teritory object
                for(int i = 0, f = 0; i < text.length() && f < 3; i++, f++){
                                        
                    string token = "";

                    while(text[i] != ' ' && i < text.length()){
                        token += text[i];
                        i++;
                    }

                    propArr[f] = token;  
                                     
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
            break;       
        }
    }
    file.close();
}

void MapLoader::readBorders(string fileName){

    ifstream file(fileName);  
    string text; 
    int currCountry;     //Current country to which we are attributing the borders.  
    bool firstToken = true; 

    //Reading countries only
    while (getline(file, text)){       
        if(text.compare("[borders]") == 0){

            while(text.compare("") != 0){
                
                getline(file, text); 

                //Spliting the string by tokens to create teritory object
                for(int i = 0; i < text.length(); i++){
                                        
                    string token = "";
                    while(text[i] != ' ' && i < text.length()){
                        token += text[i];
                        i++;
                    }
                    
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
            break;       
        }        
    }
    file.close();
}