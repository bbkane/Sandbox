#include "Timer.h"
#include <iostream>

int main()
{
	Timer t;
	int i;
	std::cin >> i;
	std::cout << t.get_ticks() << std::endl;

	t.reset();

	std::cin >> i;
	std::cout << t.get_ticks() << std::endl;
}
