#include "FileCommandProcessorAdapter.h"

// constructor
FileCommandProcessorAdapter::FileCommandProcessorAdapter(string fileName) : CommandProcessor()
{
    ifstream file(fileName);

    if (file.good())
    {
        fileReader = new FileLineReader(fileName);
    }
    else
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    file.close();
}

// destructor
FileCommandProcessorAdapter::~FileCommandProcessorAdapter()
{
    delete fileReader;
    fileReader = NULL;
}

// copy consturctor
FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter &copy) : CommandProcessor(copy)
{
    if (copy.fileReader != nullptr)
    {
        fileReader = new FileLineReader(*copy.fileReader);
    }
    else
    {
        fileReader = nullptr;
    }
}

// readCommand overriden to use the FileLineReader
string FileCommandProcessorAdapter::readCommand()
{
    string command = fileReader->ReadLineFromFile();
    this->saveCommand(command);
    return command;
}

// assignment operator
FileCommandProcessorAdapter &FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter &other)
{
    *this->fileReader = *other.fileReader;
    return *this;
}

// insertion operator
std::ostream &operator<<(std::ostream &os, const FileCommandProcessorAdapter &adapter)
{
    string s = "FileCommandProcessorAdapter is using File: " + adapter.fileReader->getFileName() + ".\n";
    for(int i = 0; i < adapter.commandList->getEnd(); i++){
       s +=  "Command Type: " + adapter.commandList->getAtIndex(i)->getCommandType() + ", Command Effect: " + adapter.commandList->getAtIndex(i)->getEffect() + "\n";
    };      
    return os << s << endl;;
}
