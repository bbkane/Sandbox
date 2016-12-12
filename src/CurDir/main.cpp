#ifdef _WIN32
#include <Windows.h>

int main()
{
	TCHAR pwd[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pwd);
	MessageBox(NULL, pwd, pwd, 0);
}

#else
int main(){}
#endif