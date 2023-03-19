#include "CommandProcessing.h"

/*---------Command class---------*/
Command::Command()
{
    this->commandType = new string("");
    this->effect = new string("");
}

Command::Command(string comandType)
{
    this->commandType = new string(comandType);
    this->effect = new string("");
}

Command::Command(const Command &c)
{
    this->commandType = new string(*c.commandType);
    this->effect = new string(*c.effect);
}

Command::~Command()
{
    delete this->commandType;
    this->commandType = NULL;

    delete this->effect;
    this->effect = NULL;
}

void Command::setCommandType(string commandType)
{
    *this->commandType = commandType;
}

string Command::getCommandType()
{
    return *this->commandType;
}

void Command::saveEffect(string effect)
{
    *this->effect = effect;
}

string Command::getEffect()
{
    return *this->effect;
}

Command &Command::operator=(const Command &c)
{
    *this->commandType = *c.commandType;
    *this->effect = *c.effect;
    return *this;
}

std::ostream &operator<<(std::ostream &strm, const Command &t)
{
    string res = "Command Type: " + *t.commandType + ", Command Effect: " + *t.effect;
    return strm << res << endl;
}

/*---------Command class---------*/
CommandList::CommandList()
{
    this->size = new int(50);
    this->commands = new Command *[50];
    this->end = new int(0);
}

CommandList::CommandList(int size)
{
    this->size = new int(size);
    this->commands = new Command *[size];
    this->end = new int(0);
}

CommandList::CommandList(CommandList* cl)
{
    this->size = new int(*cl->size);
    this->commands = new Command *[*this->size];
    this->end = new int(*cl->end);

    for(int i = 0; i < *this->end; i++){
        commands[i] = cl->commands[i];
    }
}


CommandList::~CommandList()
{
    delete this->size;
    this->size = NULL;

    delete[] this->commands;
    this->commands = NULL;

    delete this->end;
    this->end = NULL;
}

void CommandList::storeCommand(Command *newCommand)
{

    if (*this->end == *this->size - 1)
    {
        resize();
    }

    this->commands[*this->end] = newCommand;
    *this->end = *this->end + 1;
}

int CommandList::getSize()
{
    return *this->size;
}

int CommandList::getEnd()
{
    return *this->end;
}

void CommandList::resize()
{
    int newSize = *this->size * 2;
    Command **newList = new Command *[newSize];

    for (int i = 0; i < *this->size; i++)
    {
        newList[i] = this->commands[i];
    }

    *this->size = newSize;
    delete this->commands;
    this->commands = newList;
}

Command *CommandList::getAtIndex(int index)
{
    if (index < 0 || index >= *this->size)
    {
        return NULL;
    }
    else
    {
        return this->commands[index];
    }
}

CommandList& CommandList::operator=(const CommandList &c){
    *this->size = *c.size;
    *this->end = *c.end;

    for(int i = 0; i < *this->end; i++){
        this->storeCommand(c.commands[i]);
    }    
    return *this;
}

std::ostream &operator<<(std::ostream &strm, const CommandList &t)
{
    string s = "";
    for(int i = 0; i < *t.end; i++){
       s +=  "Command Type: " + t.commands[i]->getCommandType() + ", Command Effect: " + t.commands[i]->getEffect() + "\n";
    };

    return strm << s << endl;
}


/*---------CommandProcessor class---------*/
CommandProcessor::CommandProcessor()
{
    this->commandList = new CommandList();
    this->state = new int(0);
}

CommandProcessor::CommandProcessor(int size)
{
    this->commandList = new CommandList(size);
    this->state = new int(0);
}

CommandProcessor::CommandProcessor(CommandProcessor* cp)
{
    this->commandList = cp->commandList;
    this->state = new int(*cp->state);
}

CommandProcessor::~CommandProcessor()
{
    delete this->commandList;
    this->commandList = NULL;

    delete this->state;
    this->state =NULL;
}

string CommandProcessor::readCommand()
{
    cout << "Your move: ";
    string command;
    cin >> command;
    return command;
}

void CommandProcessor::saveCommand(string type)
{
    Command *newCommand = new Command(type);
    this->commandList->storeCommand(newCommand);
}

string CommandProcessor::getCommand()
{
    string temp = this->readCommand();
    this->saveCommand(temp);

    return temp;
}

// Function validate all user input Commands, and saves the effect of invalid commands with the according error message
//(passed to the function)
void CommandProcessor::validate(string message, string input, string breakCommand, bool cont, function<bool(string)> func)
{
    bool res = func(input);

    // This is to cover the edge case where there are two break commands that can invoke a state change in the
    // same state.
    string breakSubOne = "";
    string breakSubTwo = "";

    for (int i = 0; i < breakCommand.size(); i++)
    {
        if (isspace(breakCommand[i]))
        {
            breakSubOne = breakCommand.substr(0, i);
            breakSubTwo = breakCommand.substr(i + 1, breakCommand.size());
            break;
        }
    }

    if (!res)
    {
        this->commandList->getAtIndex(this->commandList->getEnd() - 1)->saveEffect(message + input);
        string temp = getCommand();
        validate(message, temp, breakCommand, cont, func);
    }
    else if (cont && input.compare(breakCommand) != 0 && input.compare(breakSubOne) != 0 && input.compare(breakSubTwo) != 0)
    {
        string temp = getCommand();
        validate(message, temp, breakCommand, cont, func);
    }
}

bool CommandProcessor::validate(Command &command, string effect)
{
    switch (*this->state)
    {
    case 0:
        if (command.getCommandType() == "loadmap")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Start state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 1:
        if (command.getCommandType() == "validatemap" || command.getCommandType() == "loadmap")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Map Load state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 2:
        if (command.getCommandType() == "addplayer")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Validate Map state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 3:
        if (command.getCommandType() == "assigncountries" || command.getCommandType() == "addplayer")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Add Player state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 4:
        if (command.getCommandType() == "issueorder")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Assign Reinforcements state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 5:
        if (command.getCommandType() == "endissueorders" || command.getCommandType() == "issueorder")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Issue Order state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 6:
        if (command.getCommandType() == "win" || command.getCommandType() == "execorder" || command.getCommandType() == "endexecorders")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Execute Order state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    case 7:
        if (command.getCommandType() == "end" || command.getCommandType() == "play")
        {
            return true;
        }
        else
        {
            command.saveEffect("CANNOT USE THE COMMAND. Win state does not support the command: " + command.getCommandType());
            return false;
        }
        break;

    default:
        return true;
        break;
    }
}

CommandProcessor &CommandProcessor::operator=(const CommandProcessor &c)
{
    this->commandList = c.commandList;
    *this->state = *c.state;
    return *this;
}

std::ostream &operator<<(std::ostream &strm, const CommandProcessor &cp)
{
    string s = "";
    for(int i = 0; i < cp.commandList->getEnd(); i++){
       s +=  "Command Type: " + cp.commandList->getAtIndex(i)->getCommandType() + ", Command Effect: " + cp.commandList->getAtIndex(i)->getEffect() + "\n";
    };

    return strm << s << endl;
}
