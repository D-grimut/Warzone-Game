#include "FileCommandProcessorAdapter.h"

FileCommandProcessorAdapter::FileCommandProcessorAdapter(string fileName, int size) : CommandProcessor(size)
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

FileCommandProcessorAdapter::~FileCommandProcessorAdapter()
{
    delete fileReader;
    fileReader = NULL;
}

string FileCommandProcessorAdapter::readCommand()
{
    string command = fileReader->ReadLineFromFile();
    return command;
}