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
FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter &copy) : CommandProcessor()
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