#pragma once
#include <iostream>
#include <string>
#include <math.h>  
#include "Map.h"
#include "Player.h"
using namespace std;

class Player;
//Player neutral = new Player(-1,)

//Order class (PARENT)
class Order {
    public:
        Order();
        ~Order();
        Order(const Order& e); //copy constructor
        Order& operator =(const Order& e); //asignmnet operator
        virtual bool* validate(); //Validate boolean, (virtual for polymorphism)
        virtual void execute() = 0; //Execute
        virtual string* description(); //Shows which order it is
        string* getName();
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
        //Getters
            Territory* getTragetTerr();
            int* getArmies();
            Player* getPlayer();
        //Setters
            void setArmies(int* armies);
            void setTargetTerr(Territory* target); 
            void setPlayer(Player* player);
    private:
        string* name; //used for description
        Territory* target; //Territory to deploy armies to
        int* armies; //number of armies to deploy
        Player* player;
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
        //Getters
            Territory* getTargetTerr();
            Territory* getSourceTerr();
            int* getArmies();
            Player* getPlayer();
            Player* getEnemy();
        //Setters
            void setTargetTerr(Territory* targTerr);
            void setSourceTerr(Territory* sourceTerr);
            void setArmies(int* numArmies);
            void setPlayer(Player* player);
            void setEnemy(Player* enemy);
    private:
        Territory* source; //source terriotry
        Territory* target; //terriotry to advance to
        int* armies; //number of armies to advance
        string* name; //used for description
        Player* player;
        Player* enemy;
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
        //Getters
            Territory* getTargetTerr();
            Player* getPlayer();
            Territory* getSourceTerr();
        //Setters
            void setTargetTerr(Territory* target);
            void setPlayer(Player* player);
            void setSourceTerr(Territory* source);
    private:
        Territory* target; //target territory to bomb
        Territory* source;
        Player* player; //player id issuing the order
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
        //Getters
            Territory* getTargetTerr();
            Player* getPlayer();
        //Setters
            void setTargetTerr(Territory* target);
            void setPlayer(Player* player);
    private:
        Territory* target; //terriotry to blockade
        Player* player;
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

        //Getters
            Territory* getTargetTerr();
            Territory* getSourceTerr();
            int* getArmies();
            Player* getPlayer();

        //Setters
            void setTargetTerr(Territory* target);
            void setSourceTerr(Territory* source);
            void setArmies(int* armies);
            void setPlayer(Player* player);

    private:
        Territory* source; //terriotry sending armies
        Territory* target; //terriotry receiving armies
        int* armies; //number of armies being sent
        Player* player; // player issuing order
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
        //Getters
            Player* getPlayer();
            Territory* getTargetTerr();
            Player* getEnemy();
        //Setters
            void setPlayer(Player* player);
            void setTargetTerr(Territory* target);  
            void setEnemy(Player* enemy);
          
    private:
        Territory* target; //territory to negotiate with
        Player* player; //player id issuing order
        Player* enemy;
        friend std::ostream& operator<<(std::ostream &strm, const Negotiate &a);
        string* name; //used for description
};

//OrdersList class (creates the vector to store orders)
class OrdersList {
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
    Order* getOrder(int i);
    int* end;
private:
    friend std::ostream& operator<<(std::ostream &strm, const OrdersList &a);
    Order** orders; //vecotr created
    int* size;
};