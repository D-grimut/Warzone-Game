#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Observer;

// Resizable array for Observer Objects
class ObserverList
{
private:
    Observer **obs;
    int *size;
    int *end;

public:
    ObserverList();
    ObserverList(int);
    ~ObserverList();

    void add(Observer* );
    int getSize();
    int getEnd();
    void resize();   
    void removeAtIndex(int);
    Observer* getAtIndex(int); 
};

class ILoggable{
public:
    virtual string stringToLog() = 0;
};

class Subject{
private:
    ObserverList* obs;

public:
    void attach(Observer*);
    void detach(Observer* o);
    void notify(ILoggable*);

    Subject();
    ~Subject();
};

class Observer{
public:
    virtual void update(ILoggable*);
};

class LogObserver: public Observer{

public:
    void update(ILoggable*);
};
