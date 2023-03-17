#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileLineReader
{
public:
    FileLineReader(const std::string &filename);
    ~FileLineReader();
    FileLineReader(const FileLineReader &copy);

    std::string ReadLineFromFile();

private:
    std::ifstream file;
    std::string currentLine;
    std::string file_name;
};