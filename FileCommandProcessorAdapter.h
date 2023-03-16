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
    FileCommandProcessorAdapter(string fileName);
    ~FileCommandProcessorAdapter();

    string readCommand() override;
};