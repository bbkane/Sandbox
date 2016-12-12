#include <iostream>
#include <chrono>
#include <cstdint>

class Timer
{
    using milliseconds_t = std::chrono::duration < int, std::milli >;
public:
    Timer() { reset(); }
    void reset()
    {
        start = std::chrono::steady_clock::now();
    }
    int get_ticks()
    {
        end = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<milliseconds_t>(end - start);
        return duration.count();
    }
private:
    std::chrono::steady_clock::time_point start{ std::chrono::steady_clock::now() };
    std::chrono::steady_clock::time_point end;
    milliseconds_t duration;
};

int main()
{
    using int_type = int16_t;

    constexpr int NUM_TIMES = 1000;
    constexpr int WIDTH = 900;
    constexpr int HEIGHT = 400;

    int_type my_array[WIDTH][HEIGHT];
    Timer timer;

    timer.reset();
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            my_array[i][j] = static_cast<int_type>(i * j);
        }
    }
    std::cout << timer.get_ticks() << std::endl;

    timer.reset();
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            my_array[j][i] = static_cast<int_type>(i * j);
        }
    }
    std::cout << timer.get_ticks() << std::endl;
}