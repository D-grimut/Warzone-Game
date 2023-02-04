#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Orders{ //parent class
    public:
        //default
        Orders(); 
        //overload
        Orders(string name); 
    

        //Accessor Functions
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
            //setName
            //@param string - name of action

        bool validate();
        void execute();
    private:
        string name;
};

class Deploy : public Orders{
    public:
        Deploy();
        Deploy(string name);
                //Accessor Functions
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
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
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
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
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
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
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
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
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
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
        string getName() const;
            //get name
            //@return - name of action
        
        //Mutators
        void setName(string); 
            //setName
            //@param string - name of action
    private:
        string name;
};