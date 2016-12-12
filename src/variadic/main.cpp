#include <iostream>

// base case (no arguments)
void variadic_print()
{
    std::cout << std::endl;
}

// regular case (arguments)
template <typename First, typename... Rest>
void variadic_print(First first, Rest... rest)
{
    std::cout << first << " ";
    variadic_print(rest...);
}

auto variadic_add()
{
    return 0;
}

template <typename First, typename... Rest>
auto variadic_add(First first, Rest... rest)
{
    return (first + variadic_add(rest...));
}

int main()
{
    variadic_print(1, 3, 'c', "word");
    variadic_print(5);
    std::cout << variadic_add(4, 5, 3) << std::endl;
    std::cout << variadic_add(4.4, 5.3, 3) << std::endl;
}
