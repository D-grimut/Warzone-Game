#pragma once
#include <iostream>
#include <string>

using namespace std;

class Orders{ //parent class
    public:
        //default
        Orders(); 
        //overload
        Orders(string name); 
    

        //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action

        bool validate();
        bool execute();
    private:
        string name;
};

class Deploy : public Orders{
    public:
        Deploy();
        Deploy(string name);
                //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
    private:
        string name;
};

class Advance : public Orders{
     public:
        Advance();
        Advance(string name);
                //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
   private:
        string name;
};

class Bomb : public Orders{
    public:
        Bomb();
        Bomb(string name);
                //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
    private:
        string name;
};

class Blockade : public Orders{
    public:
        Blockade();
        Blockade(string name);
                //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
    private:
        string name;
    
};

class Airlift : public Orders{
    public:
        Airlift();
        Airlift(string name);
                //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
    private:

        string name;
};

class Negotiate : public Orders{
    public:
        Negotiate();
        Negotiate(string name);
        //Accessor Functions
        string getName();
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string name); 
            //setName
            //@param string - name of action
    private:
        string name;
};

class OrdersList{
    public:
        OrdersList();
        OrdersList( int* const size);
        void move(int* position1, int* position2);
        void remove(int* position);
        void resize();
        bool needResize(int count);
        int getsize();
        void setSize(int* newSize);
        void add(Orders* a1);
        Orders getArray(int i);
    private:
        int* size;
        Orders* orderList[];
     
};