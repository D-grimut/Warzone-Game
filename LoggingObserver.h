#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Observer;

class ILoggable{
public:
    virtual string stringToLog() = 0;
};

class Subject{
private:
    Observer* obs;

public:
    void attach(Observer*);
    void detach();
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