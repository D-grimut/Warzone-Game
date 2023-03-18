#include "FileLineReader.h"

// constructor
FileLineReader::FileLineReader(const std::string &filename)
{
    file_name = filename;
    file.open(filename);
}

// destructor
FileLineReader::~FileLineReader()
{
    if (file.is_open())
    {
        file.close();
    }
}

// copy constructor
FileLineReader::FileLineReader(const FileLineReader &copy)
{
    if (copy.file.is_open())
    {
        file.open(copy.file_name);
    }
}

// reads 1 line from the file and then goes onto the next line.
std::string FileLineReader::ReadLineFromFile()
{
    std::string line;
    if (std::getline(file, line))
    {
        return line;
    }
    return "EOF";
}

