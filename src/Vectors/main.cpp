#include <iostream>

template <typename T>
struct Vec2
{
    T x;
    T y;
};

using Point = Vec2<float>;

int main()
{
    Point x{1.0f, 1.0f};
    Point y{2.0f, 2.0f};
}
