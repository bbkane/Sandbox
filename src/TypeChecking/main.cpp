#include <type_traits>

template <typename NumericType>
struct S
{
    static_assert(std::is_arithmetic<NumericType>::value, "NumericType must be numeric");
};

template <typename NumericType>
NumericType add_one(NumericType n)
{
    static_assert(std::is_arithmetic<NumericType>::value, "NumericType must be numeric");
    return n + 1;
}
    
int main()
{
    S<int> i;
    // S<char*> s; //doesn't compile

    add_one(1.f);
    // add_one("hi there"); //doesn't compile
}
