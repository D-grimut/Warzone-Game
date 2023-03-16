#pragma once
#include "LoggingObserver.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class GameEngine;

class Command : public ILoggable, public Subject
{
private:
    string *commandType;
    string *effect;

public:
    Command();
    Command(string);
    Command(const Command &); // TODO
    ~Command();

    void setCommandType(string);
    string getCommandType();

    void saveEffect(string);
    string getEffect();

    string stringToLog();

    // TODO AT END
    Command &operator=(const Command &);
    friend std::ostream &operator<<(std::ostream &strm, const Command &t);
};

// Resizable array for Command Objects
class CommandList
{
private:
    Command **commands;
    int *size;
    int *end;

public:
    CommandList();
    CommandList(int);
    ~CommandList();

    void storeCommand(Command *);
    int getSize();
    int getEnd();
    void resize();
    Command *getAtIndex(int);
};

class CommandProcessor : public ILoggable, public Subject
{
protected:
    CommandList *commandList;
    virtual string readCommand();
    void saveCommand(string);

public:
    CommandProcessor();
    CommandProcessor(int);
    ~CommandProcessor();

    string getCommand();
    string stringToLog();
    void toString();
    void validate(string, string, string, bool, function<bool(string)> func);
    bool validate(Command &command, int state, string effect);
};