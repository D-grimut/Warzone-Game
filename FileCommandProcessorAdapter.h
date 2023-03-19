#pragma once
#include "CommandProcessing.h"
#include "FileLineReader.h"
#include <fstream>
#include <string>

class FileCommandProcessorAdapter : public CommandProcessor
{
private:
    FileLineReader *fileReader;

public:
    // Constructors and Destructors
    FileCommandProcessorAdapter(string fileName);
    ~FileCommandProcessorAdapter();
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter &copy);

    // insertion and assignment operator
    friend std::ostream &operator<<(std::ostream &os, const FileCommandProcessorAdapter &fcpa);
    FileCommandProcessorAdapter &operator=(const FileCommandProcessorAdapter &other);

    string readCommand() override;
};