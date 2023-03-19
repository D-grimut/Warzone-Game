#include "FileLineReader.h"

// constructor
FileLineReader::FileLineReader(const std::string &filename)
{
    file_name = new std::string(filename);
    file = new std::ifstream(filename);
    currentLine = new std::string("");
}

// destructor
FileLineReader::~FileLineReader()
{
    if (file != nullptr && file->is_open())
    {
        file->close();
    }
    delete file;
    delete currentLine;
    delete file_name;
}

// copy constructor
FileLineReader::FileLineReader(const FileLineReader &copy)
{
    file_name = new std::string(*copy.file_name);
    file = new std::ifstream(*file_name);
    currentLine = new std::string(*copy.currentLine);
}

// reads 1 line from the file and then goes onto the next line.
std::string FileLineReader::ReadLineFromFile()
{
    if (std::getline(*file, *currentLine))
    {
        return *currentLine;
    }
    return "EOF";
}

std::ostream &operator<<(std::ostream &os, FileLineReader &flr)
{
    std::string line = flr.ReadLineFromFile();
    if (line != "EOF")
    {
        os << line;
    }
    return os;
}