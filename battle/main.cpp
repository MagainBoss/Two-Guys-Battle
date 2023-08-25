#include "func.h"

using namespace std;

int main()
{

	mapInit();

	while (1)
	{

		refresh();
		HANDLE hOut;
		COORD pos;
		pos = { 0,0 };
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		print();
		Sleep(30);

	}

	return 0;

}