#include "FileCommandProcessorAdapter.h"

int main()
{

    FileCommandProcessorAdapter *test = new FileCommandProcessorAdapter("test.txt", 8);
    for (int i = 0; i < 8; i++)
    {
        std::string str = test->readCommand();
        std::cout << str << std::endl;
    }
    return 0;
}