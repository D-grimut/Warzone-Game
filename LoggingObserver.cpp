#include "LoggingObserver.h"

//--- Subject Class ---
Subject::Subject(){
    this->obs = nullptr;
}

Subject::~Subject(){
    delete this->obs;
    this->obs = NULL;
}

void Subject::attach(Observer* o){
    this->obs = o;
}

void Subject::detach(){
    this->obs = NULL;
}

void Subject::notify(ILoggable* il){
    this->obs->update(il);
}

//--- Observer --- TODO

//---LogObserver class ---
void LogObserver::update(ILoggable* il){
    //TODO - Open file, append to end, print string gotten from il
}
