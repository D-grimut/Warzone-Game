#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileLineReader
{
public:
    FileLineReader(const std::string &filename);
    ~FileLineReader();

    std::string ReadLineFromFile();

private:
    std::ifstream file;
    std::string currentLine;
};