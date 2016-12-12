#ifdef _WIN32

#include <windows.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::cout << "Use the letters 'd' and 'f' to mark the corners of a rectangle you want to capture with 'ScreenShot.exe'" << std::endl;
	std::cout << "Press 'q' to write to a file and quit." << std::endl;
	POINT pos1{ 0, 0 }, pos2{ 0, 0 };
	POINT old_pos1{ 0, 0 }, old_pos2{ 0, 0 };
	bool done{ false };
	while (!done)
	{
		if (GetAsyncKeyState('D') < 0)
		{
			GetCursorPos(&pos1);

		}
		if (pos1.x != old_pos1.x || pos1.y != old_pos1.y)
		{
			std::cout << pos1.x << ' ' << pos1.y << " and " << pos2.x << ' ' << pos2.y << std::endl;
			old_pos1.x = pos1.x;
			old_pos1.y = pos1.y;
		}
		if (GetAsyncKeyState('F') < 0)
		{
			GetCursorPos(&pos2);

		}
		if (pos2.x != old_pos2.x || pos2.y != old_pos2.y)
		{
			std::cout << pos1.x << ' ' << pos1.y << " and " << pos2.x << ' ' << pos2.y << std::endl;
			old_pos2.x = pos2.x;
			old_pos2.y = pos2.y;
		}
		if (GetAsyncKeyState('Q') < 0)
		{
			std::ofstream fout("dimensions.txt");
			fout << pos1.x << ' ' << pos1.y << ' ' << pos2.x << ' ' << pos2.y << std::endl;
			done = true;
		}

	}
}

#else
int main(){}
#endif