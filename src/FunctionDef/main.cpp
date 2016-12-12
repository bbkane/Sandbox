#include <iostream>


using namespace std;

int fib(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		int fm1 = fib(n - 1);
		int fm2 = fib(n - 2);
		return fm1 + fm2;
	}
}

int main()
{
	int f5 = fib(5);
	std::cout << f5 << std::endl;
	return 0;
}