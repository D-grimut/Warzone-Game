#include "CommandProcessing.h"

/*---------Command class---------*/
Command::Command(){
    this->commandType = new string("");
    this->effect = new string("");
}

Command::Command(string comandType){
    this->commandType = new string(comandType);
    this->effect = new string("");
}

Command::~Command(){
    delete this->commandType;
    this->commandType = NULL;

    delete this->effect;
    this->effect = NULL;
}

void Command::setCommandType(string commandType){
    *this->commandType = commandType;
}

string Command::getCommandType(){
    return *this->commandType;
}

void Command::saveEffect(string effect){
    *this->effect = effect;
}

string Command::getEffect(){
    return *this->effect;
}

/*---------Command class---------*/
CommandList::CommandList(){
    this->size = new int(50);
    this->commands = new Command*[50];
    this->end = new int(0);
}

CommandList::CommandList(int size){
    this->size = new int(size);
    this->commands = new Command*[size];
    this->end = new int(0);
}

CommandList::~CommandList(){
    delete this->size;
    this->size = NULL;

    delete [] this->commands;
    this->commands = NULL;
    
    delete this->end;
    this->end = NULL;
}

void CommandList::storeCommand(Command* newCommand){

    if(*this->end == *this->size - 1){
        resize();
    }
    //cout << *this->end << endl;    
    this->commands[*this->end] = newCommand;    
    *this->end = *this->end + 1;

}

int CommandList::getSize(){
    return *this->size;
}

int CommandList::getEnd(){
    return *this->end;
}

void CommandList::resize(){
    int newSize = *this->size * 2;
    Command** newList = new Command*[newSize];

    for(int i = 0; i < *this->size; i++){
        newList[i] = this->commands[i];
    }
    
    *this->size = newSize;
    delete this->commands;
    this->commands = newList;    
}

Command* CommandList::getAtIndex(int index){
    if(index < 0 || index >= *this->size){
        return NULL;
    }else{
        return this->commands[index];
    }
}

/*---------CommandProcessor class---------*/
CommandProcessor::CommandProcessor(){
    this->commandList = new CommandList(); 
}

CommandProcessor::CommandProcessor(int size){
    this->commandList = new CommandList(size);     
}

CommandProcessor::~CommandProcessor(){
    delete this->commandList;
    this->commandList = NULL;
}

string CommandProcessor::readCommand(){
    cout << "Your move: ";
    string command;
    cin >> command;
    return command;
}

void CommandProcessor::saveCommand(string type){
    Command* newCommand = new Command(type);      
    this->commandList->storeCommand(newCommand);    
}

string CommandProcessor::getCommand(){
    string temp = this->readCommand();
    this->saveCommand(temp);

    return temp;
}

//TODO: remove at end
//FOR TESTING
void CommandProcessor::toString(){    
    cout << this->commandList->getEnd() << endl;
    for(int i = 0; i < this->commandList->getEnd(); i++){      
        cout << this->commandList->getAtIndex(i)->getCommandType() << " EFFECT : " << this->commandList->getAtIndex(i)->getEffect() <<   endl;
    }
}

//Function validate all user input Commands, and saves the effect of invalid commands with the according error message
//(passed to the function)
void CommandProcessor::validate(string message, string input, string breakCommand, bool cont, function<bool(string)> func){
    bool res = func(input);

    //This is to cover the edge case where there are two break commands that can invoke a state change in the 
    //same state.
    string breakSubOne = "";
    string breakSubTwo = "";    

    for(int i = 0; i < breakCommand.size(); i++){
        if(isspace(breakCommand[i])){           
            breakSubOne = breakCommand.substr(0, i);
            breakSubTwo = breakCommand.substr(i+1, breakCommand.size());
            break;
        }
    } 
   
    if(!res){
        this->commandList->getAtIndex(this->commandList->getEnd() - 1)->saveEffect(message + input);        
        string temp = getCommand();
        validate(message, temp, breakCommand, cont, func);    

    }else if(cont && input.compare(breakCommand) != 0 && input.compare(breakSubOne) != 0 && input.compare(breakSubTwo) != 0){        
        string temp = getCommand();
        validate(message, temp, breakCommand, cont, func);
    }
}