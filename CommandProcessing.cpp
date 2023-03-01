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

void CommandProcessor::toString(){    
    cout << this->commandList->getEnd() << endl;
    for(int i = 0; i < this->commandList->getEnd(); i++){      
        cout << this->commandList->getAtIndex(i)->getCommandType() << " index : " << i <<   endl;
    }
}

void CommandProcessor::validate(Command* command, string status){

}