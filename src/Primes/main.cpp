#include <iostream>
#include <cstring>
#include <memory>

size_t get_number()
{
    size_t number = 0;
    std::cout << "Enter positive number: ";
    std::cin >> number;
    std::cout << std::endl;

    return number;
}

int main()
{
    // Sieve of Erosthenes approach
    // int number = get_number();
    size_t number = 5;

    std::cout << number << std::flush << std::endl;

    // std::unique_ptr<bool[]> primes_array(new bool[number]{0});
    std::unique_ptr<int[]> primes_array(new int[number]);

    // everything is prime at first
    std::memset(primes_array.get(), 1, number * sizeof(int));

    // start with 2
    // go through the rest of them and init all multiple of 2 to 0
    // start wtih two again and find the next known prime
    // loop through the others again and do the same thing
    primes_array[2] = 1;
    for(size_t i = 0; i < number; ++i)
    {

    }

}
