#pragma once

#include <chrono>

class Timer
{
	using milliseconds_t = std::chrono::duration < int, std::milli > ;
public:
	Timer() = default;
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