#ifdef _WIN32

#include <windows.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{

	bool done = false;
	char current_char;
	while (!done)
	{
		for (char i = 'A'; i <= 'Z'; ++i)
		{
			if (GetAsyncKeyState(i) < 0)
			{
				if (i != current_char)
				{
					std::cout << i;
					current_char = i;
				}
			}
		}

	}
}

#else
int main(){}
#endif