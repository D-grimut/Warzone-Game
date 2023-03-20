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
    ObserverList(const ObserverList &other);

    void add(Observer *);
    int getSize();
    int getEnd();
    void resize();
    void removeAtIndex(int);
    Observer *getAtIndex(int);

    // assign and insertion
    ObserverList &operator=(const ObserverList &other);
    friend ostream &operator<<(ostream &os, const ObserverList &obj);
};

class ILoggable
{
public:
    virtual string stringToLog() = 0;
};

class Subject
{
private:
    ObserverList *obs;

public:
    void attach(Observer *);
    void detach(Observer *o);
    void notify(ILoggable *);

    Subject();
    ~Subject();
    Subject(const Subject &other);

    friend ostream &operator<<(ostream &os, const Subject &sub);
    Subject &operator=(const Subject &other);
};

class Observer
{
public:
    virtual void update(ILoggable *);
    friend ostream &operator<<(ostream &os, const Observer &obs);
};

class LogObserver : public Observer
{

public:
    void update(ILoggable *);
    friend ostream &operator<<(ostream &os, const LogObserver &lobs);
};
