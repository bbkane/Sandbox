#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::cin >> word;
    std::string command = "cowsay " + word;
    const char* cmd = command.c_str();
    system(cmd);
}
