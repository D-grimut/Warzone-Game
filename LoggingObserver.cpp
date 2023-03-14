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
void Observer::update(ILoggable* il){    
    cout << il->stringToLog() << endl;
}

//---LogObserver class ---
void LogObserver::update(ILoggable* il){ 
    ofstream gamelog;   
    gamelog.open("gamelog.txt", fstream::app);
    gamelog << il->stringToLog() + "\n";
    gamelog.close();    
}
