#include <iostream>
#include <fstream>
#include <algorithm>

#ifdef _WIN32
#include <Windows.h>

void save_bmp_to_clipboard(int x1 = -1, int y1 = -1, int x2 = -1, int y2 = -1)
{
	int w = 0, h = 0;

	// get screen dimensions
	if (x1 == -1) { x1 = GetSystemMetrics(SM_XVIRTUALSCREEN); }
	if (y1 == -1) { y1 = GetSystemMetrics(SM_YVIRTUALSCREEN); }
	if (x2 == -1) { x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN); }
	if (y2 == -1) { y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN); }
	w = x2 - x1;
	h = y2 - y1;

	// copy screen to bitmap
	HDC     hScreen = GetDC(NULL);
	HDC     hDC = CreateCompatibleDC(hScreen);
	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
	HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
	BOOL    bRet = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

	// save bitmap to clipboard
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hBitmap);
	CloseClipboard();

	// clean up
	SelectObject(hDC, old_obj);
	DeleteDC(hDC);
	ReleaseDC(NULL, hScreen);
	DeleteObject(hBitmap);
}
#elif __APPLE__
#import <OpenGL/gl.h>

void save_bmp_to_clipboard(int x1, int y1, int x2, int y2)
{
}

#elif __linux

#endif

int main(int argc, char** argv)
{
	//by default, just screenshot the entire thing
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

	//handle args
	if (argc == 1)
	{
		//optionally, look for a file in the current working directory
		std::ifstream fin("dimensions.txt");
		if (fin.is_open())
		{
			fin >> x1 >> y1 >> x2 >> y2;
		}

	}
	else if (argc == 2)
	{
		std::ifstream fin(argv[1]);
		if (fin.is_open())
		{
			fin >> x1 >> y1 >> x2 >> y2;
		}
		else
		{
			std::cerr << "Could not open file: " << argv[1] << std::endl;;
			return 1;
		}
	}
	else if (argc == 5)
	{
		x1 = atoi(argv[1]);
		y1 = atoi(argv[2]);
		x2 = atoi(argv[3]);
		y2 = atoi(argv[4]);
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " [x1 y1 x2 y2 | file_name]" << std::endl;
		std::cerr << "If there are no arguments passed and a file named 'dimensions.txt'" << std::endl;
		std::cerr << "is in the current working directory, it will be used" << std::endl;
		return 1;
	}

	//error checking
	if (x2 < x1){ std::swap(x2, x1); }
	if (y2 < y1) { std::swap(y2, y1); }

	save_bmp_to_clipboard(x1, y1, x2, y2);
}
