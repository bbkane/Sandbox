#include <iostream>
#include <iomanip>
#include <bitset>

//unsigned is 8 bits on my system.
//Endianness also seems to work out
using unsigned_type = char;

// make sure it's one byte
static_assert(sizeof(unsigned_type) == 1, "Wrong size!");

void print()
{
	std::cout << std::endl;
}

//Only C++14 compatible. Compile errors otherwise
template<typename... tail>
void print(const unsigned_type & head, tail &&... rest)
{
	//and with 0b00001111 to discard 4 bits
	std::cout << std::hex << (head & 0xf) << " (" << std::bitset<4>(head) << ") ";
	//print rest of arguments or a newline
	print(std::forward<unsigned_type>(rest)...);
}

#define SHOW(line) line; std::cout << #line << std::endl; print(x, y, z)

int main()
{
	unsigned_type x = 0x4;
	unsigned_type y = 0x1;
	unsigned_type z = 0x7;
	print(x, y, z);
	SHOW(x = x + y);
	SHOW(y = x - y);
	SHOW(x = x & y);
	SHOW(z = x);
	SHOW(x = y);
	SHOW(x = ~z);
}

// prints:
// b 4 4
// 1011 0100 0100
// Press any key to continue . . .
