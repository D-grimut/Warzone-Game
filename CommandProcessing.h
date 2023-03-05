#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Command{
private:
    string* commandType;
    string* effect;

public:
    Command();
    Command(string);
    Command(const Command&);    //TODO
    ~Command();

    void setCommandType(string);
    string getCommandType();

    void saveEffect(string);
    string getEffect();   

    //TODO AT END
    Command& operator=(const Command&);
    friend std::ostream& operator<<(std::ostream &strm, const Command& t);    
};

//Resizable array for Command Objects
class CommandList {
private:    
    Command** commands;
    int* size;
    int* end;

public:   
    CommandList();
    CommandList(int);
    ~CommandList();

    void storeCommand(Command*);  
    int getSize();  
    int getEnd();    
    void resize();
    Command* getAtIndex(int);
};

class CommandProcessor{
private:

    CommandList* commandList;
    string readCommand();         
    void saveCommand(string);         

public:      
    CommandProcessor();
    CommandProcessor(int);
    ~CommandProcessor();

    string getCommand();
    void toString();
    void validate(string, string, string, bool, function<bool(string)> func);    //TODO
};