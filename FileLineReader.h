#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileLineReader
{
public:
    // Constructors and Destructors
    FileLineReader(const std::string &filename);
    ~FileLineReader();
    FileLineReader(const FileLineReader &copy);

    std::string ReadLineFromFile();

    // Assignment and insertion operators - TODO
    FileLineReader &operator=(const FileLineReader &);
    friend std::ostream &operator<<(std::ostream &strm, const FileLineReader &fl);

private:
    std::ifstream *file;
    std::string *currentLine;
    std::string *file_name;
};