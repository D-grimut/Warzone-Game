#include "FileLineReader.h"

FileLineReader::FileLineReader(const std::string &filename)
{
    file.open(filename);
}

FileLineReader::~FileLineReader()
{
    if (file.is_open())
    {
        file.close();
    }
}

std::string FileLineReader::ReadLineFromFile()
{
    std::string line;
    if (std::getline(file, line))
    {
        return line;
    }
    return "EOF";
}