#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

long fibonacci(unsigned n)
{
	if (n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

tm safe_localtime(const std::time_t& time)
{
	std::tm tm_snapshot;
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
	localtime_s(&tm_snapshot, &time);
#else
	localtime_r(&time, &tm_snapshot); // POSIX  
#endif
	return tm_snapshot;
}

int main()
{
	struct tm timeinfo = safe_localtime(std::time(nullptr));
        // Not on gcc
	// std::cout << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S") << std::endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "f(42) = " << fibonacci(42) << '\n';
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
