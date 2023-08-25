#ifndef FUNC
#define FUNC

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

struct player
{

	int x, y;

	player()
	{

		x = y = 0;

	}

};

const int len = 88, wid = 19;

void mapInit();

int dirOfFstPlayer();
int dirOfSecPlayer();
bool ifFstPlayerAtt();
bool ifSecPlayerAtt();

void winEnd(int a);
void refresh();
void print();
void ifEnd();

#endif