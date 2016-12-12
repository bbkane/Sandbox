#include <iostream>
#include <string>

struct Config
{
    Config(std::string item) : item(item)
    {
        std::cout << "Config: " << item << std::endl;
    }
    std::string item;
};

struct NeedsConfigToInit
{
    NeedsConfigToInit(Config &config) : item(config.item) 
    {
        std::cout << "NeedsConfigToInit: " << item << std::endl;
    }
    std::string item;
};

struct Game
{
    Game(std::string item) : config(item), needs_config_to_init(config) {}
    Config config;
    NeedsConfigToInit needs_config_to_init;
};

int main()
{
    Game game("hi"); 

}