#include <fstream>
#include <iostream>
#include <string>

#define STR(x)   #x
#define TO_STR(x) STR(x)

int main()
{
    std::string data_dir = TO_STR(DATA_DIR);
    std::cout << "Hello world" << std::endl;
    std::cout << TO_STR(DATA_DIR) << std::endl;
    std::cout << data_dir << std::endl;
    std::ifstream fin(data_dir + "/data.txt");
    std::string data;
    while(fin >> data)
    {
        std::cout << data << std::endl;
    }
}
