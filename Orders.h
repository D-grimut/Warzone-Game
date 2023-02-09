#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Order class (PARENT)
class Order {
    public:
        Order();
        ~Order();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Deploy class
class Deploy : public Order {
    public:
        Deploy();
        ~Deploy();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Advance class
class Advance : public Order {
    public:
        Advance();
        ~Advance();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Bomb class
class Bomb : public Order {
    public:
        Bomb();
        ~Bomb();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Blockade class
class Blockade : public Order {
    public:
        Blockade();
        ~Blockade();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Airlift class
class Airlift : public Order {
    public:
        Airlift();
        ~Airlift();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//Negotiate class
class Negotiate : public Order {
    public:
        Negotiate();
        ~Negotiate();
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute(); //Execute
        virtual string* description(); //Shows which order it is
    private:
        string* name; //used for description
};

//OrdersList class (creates the vector to store orders)
class OrdersList {
public:
    OrdersList();
    ~OrdersList();
    vector<Order*> orders; //vecotr created
    void addOrder(Order* order); //add orders to the vector
    void moveOrder(int* position1, int* position2); //move from position1 to position2
    void removeOrder(int* position); //remove order from position
    void showList(); //prints all contents in the vector
    int getSize(); //returns size of the vector
    void validate(); //not implemented, prints that it is being called
    void execute(); //not implemented, prints that it is being called
};