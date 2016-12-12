#include <memory>
#include <iostream>

class MyClass
{
public:
    MyClass(int i)
        : i(i)
    {}
    int i{3};
};

int main()
{
    auto uptr = std::make_unique<MyClass>(5);
    std::cout << uptr->i << std::endl;
    uptr = nullptr;
    

    // auto other = uptr.get();
}
