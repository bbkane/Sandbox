#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

size_t get_number()
{
    size_t number = 0;
    std::cout << "Enter positive number: ";
    std::cin >> number;
    std::cout << std::endl;

    return number;
}

void print_numbers(const std::vector<bool>& numbers)
{
    // for (size_t i = 0; i < numbers.size(); i++)
    // {
    //     std::cout << "(" << i << " " << numbers[i] << ")" << " ";
    // }
    // std::cout << "\n";

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i]) { std::cout << i << " "; }
    }
    std::cout << "\n";
}

void print_to_file(const std::vector<bool>& numbers)
{
    FILE* fp = fopen("out_file.txt", "w");

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i]) { fprintf(fp, "%lu\n", static_cast<unsigned long>(i)); }
    }

    fclose(fp);
}


int main(int argc, char** argv)
{
    // ditch the warning
    (void)argc;

    char * end = nullptr;
    // max number is 18446744073709551615
    size_t number = static_cast<size_t>(strtoul(argv[1], &end, 10));
    size_t size = number + 1;

    if (number < 2)
    {
        std::cout << "No primes less than 2" << std::endl;
        return 0;
    }

    std::vector<bool> numbers(size, true);

    if (number > numbers.max_size())
    {
        std::cout << "std::vector only has a max size of " << number << std::endl;
        return 1;
    }

    numbers[0] = false;
    numbers[1] = false;

    size_t prime = 2;
    while (prime < size)
    {
        for(size_t i = 2 * prime; i < size; i = i + prime)
        {
            numbers[i] = false;
        }
        ++prime;
        // TODO: if I increment by 2 here, I skip numbers like 25. Why?
        while(!numbers[prime] && prime < size) { prime += 1; }
    }
    // print_numbers(numbers);
    print_to_file(numbers);
}
