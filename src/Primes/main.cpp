#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

//http://stackoverflow.com/a/14966637/2958070
FILE* open_file()
{
    FILE* fp;
    const char* file_name = "out_file.txt";
#ifdef _WIN32
    errno_t err;
    if ((err = fopen_s(&fp, file_name, "w")) != 0)
    {
#else
    if ((fp = fopen(file_name, "w")) == NULL)
    {
#endif
        fprintf(stderr, "cannot open file %s!\n", file_name);
        exit(1);
    }
    return fp;
}

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
    FILE* fp = open_file();

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
    // size_t number = static_cast<size_t>(strtoul(argv[1], &end, 10));
    size_t number = get_number();
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

    // TODO: special case for 2 and 3, then increment by 6 and test for 6k +- 1
    size_t prime = 2;
    while (prime < size)
    {
        for(size_t i = 2 * prime; i < size; i = i + prime)
        {
            numbers[i] = false;
        }
        ++prime;
        // TODO: if I increment by 2 here, I skip numbers like 25. Why?
        while(prime < size && !numbers[prime]) { prime += 1; }
    }
    print_numbers(numbers);
    //print_to_file(numbers);
}
