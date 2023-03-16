#include "LoggingObserver.h"

//--- Subject Class ---
Subject::Subject(){
    this->obs = new ObserverList();
}

Subject::~Subject(){
    for(int i = 0; i < this->obs->getEnd(); i++){
        delete obs->getAtIndex(i);
    }
    delete [] this->obs;
    this->obs = NULL;
}

void Subject::attach(Observer* o){
    this->obs[obs->getEnd()].add(o);
}

void Subject::detach(Observer* o){
    for(int i = 0; i < this->obs->getEnd(); i++){
        if(obs->getAtIndex(i) == o){
            this->obs->removeAtIndex(i);
        }
    }    
}

void Subject::notify(ILoggable* il){  
    for(int i = 0; i < this->obs->getEnd(); i++){
       this->obs->getAtIndex(i)->update(il);
    }  
}

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

/*---------CommandList class---------*/
ObserverList::ObserverList()
{
    this->size = new int(50);
    this->obs = new Observer *[50];
    this->end = new int(0);
}

ObserverList::ObserverList(int size)
{
    this->size = new int(size);
    this->obs = new Observer *[size];
    this->end = new int(0);
}

ObserverList::~ObserverList()
{
    delete this->size;
    this->size = NULL;

    for(int i = 0; i < *this->end; i++){
        delete obs[i];
    }

    delete[] this->obs;
    this->obs = NULL;

    delete this->end;
    this->end = NULL;
}

void ObserverList::add(Observer *o)
{

    if (*this->end == *this->size - 1)
    {
        resize();
    }
    
    this->obs[*this->end] = o;
    *this->end = *this->end + 1;
}

int ObserverList::getSize()
{
    return *this->size;
}

int ObserverList::getEnd()
{
    return *this->end;
}

void ObserverList::resize()
{
    int newSize = *this->size * 2;
    Observer **newList = new Observer *[newSize];

    for (int i = 0; i < *this->size; i++)
    {
        newList[i] = this->obs[i];
    }

    *this->size = newSize;
    delete this->obs;
    this->obs = newList;
}

Observer* ObserverList::getAtIndex(int index)
{
    if (index < 0 || index >= *this->size)
    {
        return NULL;
    }
    else
    {
        return this->obs[index];
    }
}

void ObserverList::removeAtIndex(int s){
    this->obs[s] = NULL;

    for(int i = s; i < *this->end - 1; i++){
        obs[i] = obs[i + 1];
    }
    *this->end = *this->end - 1;
}
