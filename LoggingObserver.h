#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class ILoggable{
public:
    virtual string stringToLog() = 0;
protected:
    virtual ~ILoggable();
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
private:
    //Subject* sub; //I do not think we need this; the observer gets an ILoggable object anyways

public:
    virtual void update(ILoggable*);
};

class LogObserver: public Observer{

public:
    void update(ILoggable*);
};