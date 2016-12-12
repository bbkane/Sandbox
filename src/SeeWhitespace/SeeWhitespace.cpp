#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char** argv)
{

    const char space_replacer{'.'};
    const char tab_replacer{'>'};

    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " file-name" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);

    std::string line;

    while(getline(fin, line))
    {
        std::replace(std::begin(line), std::end(line), ' ', space_replacer);
        std::replace(std::begin(line), std::end(line), '\t', tab_replacer);

        std::cout << line << std::endl;

    }
}
