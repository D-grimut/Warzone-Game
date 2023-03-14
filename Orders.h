#pragma once
#include <iostream>
#include <string>
#include "LoggingObserver.h"
using namespace std;

//Order class (PARENT)
class Order: public ILoggable, public Subject{
    public:
    /*Default Constructor*/
        Order();
    /*Destructor*/
        ~Order();
    /*Copy Constructor*/
        Order(const Order& e);
    /*Assignment Operator*/
        Order& operator =(const Order& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
        string getName();
    string stringToLog();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Order &a);
};

//Deploy class
class Deploy : public Order {
    public:
    /*Default Constructor*/
        Deploy();
    /*Destructor*/
        ~Deploy();
    /*Copy Constructor*/
        Deploy(const Deploy& e);
    /*Assignment Operator*/
        Deploy& operator =(const Deploy& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Deploy &a);
};

//Advance class
class Advance : public Order {
    public:
    /*Default Constructor*/
        Advance();
    /*Destructor*/
        ~Advance();
    /*Copy Constructor*/
        Advance(const Advance& e);
    /*Assignment Operator*/
        Advance& operator =(const Advance& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Advance &a);
};

//Bomb class
class Bomb : public Order {
    public:
    /*Default Constructor*/
        Bomb();
    /*Destructor*/
        ~Bomb();
    /*Copy Constructor*/
        Bomb(const Bomb& e);
    /*Assignment Operator*/
        Bomb& operator =(const Bomb& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Bomb &a);
};

//Blockade class
class Blockade : public Order {
    public:
    /*Default Constructor*/
        Blockade();
    /*Destructor*/
        ~Blockade();
    /*Copy Constructor*/
        Blockade(const Blockade& e);
    /*Assignment Operator*/
        Blockade& operator =(const Blockade& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Blockade &a);
};

//Airlift class
class Airlift : public Order {
   public:
    /*Default Constructor*/
        Airlift();
    /*Destructor*/
        ~Airlift();
    /*Copy Constructor*/
        Airlift(const Airlift& e);
    /*Assignment Operator*/
        Airlift& operator =(const Airlift& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Airlift &a);
};

//Negotiate class
class Negotiate : public Order {
    public:
    /*Default Constructor*/
        Negotiate();
    /*Destructor*/
        ~Negotiate();
    /*Copy Constructor*/
        Negotiate(const Negotiate& e);
    /*Assignment Operator*/
        Negotiate& operator =(const Negotiate& e);
    /*Validate, boolean*/
        virtual bool* validate();
    /*Execute*/
        virtual void execute();
    /*Description (shows order name)*/
        virtual string* description();
    private:
    /*Name of order*/
        string* name;
    /*Insertion stream*/
        friend std::ostream& operator<<(std::ostream &strm, const Negotiate &a);
};

//OrdersList class (creates the vector to store orders)
class OrdersList: public ILoggable, public Subject{
    public:
    /*Default Constructor*/
        OrdersList();
    /*Parameterized Constructor*/
        OrdersList(int* size);
    /*Destructor*/
        ~OrdersList();
    /*Copy Constructor*/
        OrdersList(const OrdersList& e);
    /*Assignment Operator*/
        OrdersList& operator =(const OrdersList& e);
    /*Add orders to array order at position*/
        void addOrder(Order* order, int position);
    /*Move order from position1 to position2*/
        void moveOrder(int* position1, int* position2);
    /*Remove order from position*/
        void removeOrder(int* position);
    /*Print list of all the orders in the array*/
        void showList(int);
    /*Returns size of the array*/
        int* getSize();
    /*Sets size of the array*/
        void setSize(int* size);
    /*Loops through the array, validating each order*/
        void validate(); 
    /*Loops through the array, executing each order*/
        void execute();
    /*Resizes the array*/
        void resize();

    /*end of the array*/
        int* end;

    string stringToLog();
    private:
    /*Stream insertion operator*/
        friend std::ostream& operator<<(std::ostream &strm, const OrdersList &a);
    /*Array of orders*/
        Order** orders;
    /*Pointer to the size of the array*/
        int* size;
};