#pragma once
#include <iostream>
#include <string>
#include "LoggingObserver.h"
using namespace std;

//Order class (PARENT)
class Order: public ILoggable, Subject{
    public:
        Order();
        ~Order();
        Order(const Order& e); //copy constructor
        Order& operator =(const Order& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
        string* getName();
        
        string stringToLog();
    private:
        string* name; //used for description
        friend std::ostream& operator<<(std::ostream &strm, const Order &a);
};

//Deploy class
class Deploy : public Order {
    public:
        Deploy();
        ~Deploy();
        Deploy(const Deploy& e); //copy constructor
        Deploy& operator =(const Deploy& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
        friend std::ostream& operator<<(std::ostream &strm, const Deploy &a);
};

//Advance class
class Advance : public Order {
    public:
        Advance();
        ~Advance();
        Advance(const Advance& e); //copy constructor
        Advance& operator =(const Advance& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
        friend std::ostream& operator<<(std::ostream &strm, const Advance &a);
};

//Bomb class
class Bomb : public Order {
    public:
        Bomb();
        ~Bomb();
        Bomb(const Bomb& e); //copy constructor
        Bomb& operator =(const Bomb& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
        friend std::ostream& operator<<(std::ostream &strm, const Bomb &a);
};

//Blockade class
class Blockade : public Order {
    public:
        Blockade();
        ~Blockade();
        Blockade(const Blockade& e); //copy constructor
        Blockade& operator =(const Blockade& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        friend std::ostream& operator<<(std::ostream &strm, const Blockade &a);
        string* name; //used for description
};

//Airlift class
class Airlift : public Order {
    public:
        Airlift();
        ~Airlift();
        Airlift(const Airlift& e); //copy constructor
        Airlift& operator =(const Airlift& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        friend std::ostream& operator<<(std::ostream &strm, const Airlift &a);
        string* name; //used for description
};

//Negotiate class
class Negotiate : public Order {
    public:
        Negotiate();
        ~Negotiate();
        Negotiate(const Negotiate& e); //copy constructor
        Negotiate& operator =(const Negotiate& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        friend std::ostream& operator<<(std::ostream &strm, const Negotiate &a);
        string* name; //used for description
};

//OrdersList class (creates the vector to store orders)
class OrdersList: public ILoggable, Subject{
public:
    OrdersList();
    OrdersList(int* size);
    ~OrdersList();
    OrdersList(const OrdersList& e); //copy constructor
    OrdersList& operator =(const OrdersList& e); //asignmnet operator
    void addOrder(Order* order, int position); //add orders to the vector
    void moveOrder(int* position1, int* position2); //move from position1 to position2
    void removeOrder(int* position); //remove order from position
    void showList(int x); //prints all contents in the vector
    int* getSize(); //returns size of the vector
    void setSize(int* size);
    void validate(); //not implemented, prints that it is being called
    void execute(); //not implemented, prints that it is being called
    void resize();

    string stringToLog();
private:
    friend std::ostream& operator<<(std::ostream &strm, const OrdersList &a);
    Order** orders; //vecotr created
    int* size;
};