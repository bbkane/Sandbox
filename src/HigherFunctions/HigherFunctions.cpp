#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>

template<class Fun>
int result_of(const Fun &fun, int a, int b)
{
	return fun(a, b);
}

double suma(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<int(int)> f) {
	double sum = 0;
	for (; begin != end; ++begin) {
		sum += f(*begin);
	}
	return sum;
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 4 };
	std::cout << suma(std::begin(v), std::end(v), [](int i) {return i + 1; }) << std::endl;
	std::cout << result_of([](int a, int b) {return a * b; }, 1, 2) << std::endl;
}