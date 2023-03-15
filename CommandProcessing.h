#pragma once
#include "GameEngine.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Command
{
private:
    string *commandType;        //Holds the command type
    string *effect;             //Holds the command efect

public:
    //Constructors and Destructor
    Command();
    Command(string);
    Command(const Command &);
    ~Command();

    //Setters and Getters for the commandType and effect
    void setCommandType(string);    
    string getCommandType();

    void saveEffect(string);
    string getEffect();
   
    //Assignment and insertion operators
    Command &operator=(const Command &);
    friend std::ostream &operator<<(std::ostream &strm, const Command &t);
};

// Resizable array class for Command Objects
class CommandList
{
private:
    Command **commands;     //Pointer array to store the commands
    int *size;              //Size of the array
    int *end;               //Pointer that holds the index of the cell ONE AFTER the last element in the array
    void resize();          //Method to resize the array once we add an element beyond the size of the array

public:
    //Constructors
    CommandList();
    CommandList(int);
    CommandList(CommandList*);// TODO
    ~CommandList();

    void storeCommand(Command *);       //Adds a Command object into the array
    int getSize();                      //Getter for size
    int getEnd();                       //Getter to get the index of the end of the array    
    Command *getAtIndex(int);           //Method to get the element at a given index, return null if out of bounds

    //Assignment and insertion operators - TODO
    CommandList &operator=(const Command &);
    friend std::ostream &operator<<(std::ostream &strm, const CommandList &cl);
};

class CommandProcessor
{
protected:
    CommandList *commandList;           //Dynimic array for Commands
    virtual string readCommand();       //Method to read the command from the console
    void saveCommand(string);           //Method that saves the command into the commandList array

public:
    //Constructors and Destructs
    CommandProcessor();
    CommandProcessor(int);
    CommandProcessor(CommandProcessor*); //TODO
    ~CommandProcessor();

    string getCommand();                                                            //Method that reads a command from the console and saves it    
    void validate(string, string, string, bool, function<bool(string)> func);       //Method that validates all user input that is passed by console
    bool validate(Command &command, int state, string effect);                      //Method to validate specific Command objects at specific states

    //Assignment and insertion operators - TODO
    CommandList &operator=(const Command &);
    friend std::ostream &operator<<(std::ostream &strm, const CommandList &cl);
};