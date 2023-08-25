#include "func.h"

using namespace std;

char map[20][90];

struct attack
{

	int x, y;
	int dir;
	bool consist;

	attack()
	{

		x = y = 0;
		dir = 0;
		consist = 0;

	}

	void move()
	{

		if (!consist) return;

		map[y][x] = ' ';

		if (dir == 1)
			x--;
		else if (dir == 2)
			y--;
		else if (dir == 3)
			y++;
		else
			x++;

		if (x == 0) consist = 0;
		if (x == len) consist = 0;
		if (y == 0) consist = 0;
		if (y == wid) consist = 0;

		if (consist)
			map[y][x] = '%';

	}

};

player p1, p2;
attack player1[4], player2[4];

void mapInit()
{

	for (int t = 0; t <= wid; t++)
		for (int i = 0; i <= len; i++)
			map[t][i] = ' ';
	for (int t = 0; t <= len; t++)
		map[0][t] = map[wid][t] = '#';
	for (int t = 0; t <= wid; t++)
		map[t][0] = map[t][len] = '#';

	p1.x = 20, p1.y = 9;
	map[p1.y][p1.x] = '@';
	p2.x = 60, p2.y = 9;
	map[p2.y][p2.x] = '&';

}//初始化地图


int dirOfFstPlayer()
{

	if (GetAsyncKeyState(0x41))
		return 1;
	if (GetAsyncKeyState(0x57))
		return 2;
	if (GetAsyncKeyState(0x53))
		return 3;
	if (GetAsyncKeyState(0x44))
		return 4;

	return 0;

}//获取玩家1的移动操作

int dirOfSecPlayer()
{

	if (GetAsyncKeyState(VK_LEFT))
		return 1;
	if (GetAsyncKeyState(VK_UP))
		return 2;
	if (GetAsyncKeyState(VK_DOWN))
		return 3;
	if (GetAsyncKeyState(VK_RIGHT))
		return 4;

	return 0;

}//获取玩家2的移动操作

bool ifFstPlayerAtt()
{

	if (GetAsyncKeyState(VK_SPACE)) return 1;

	return false;

}//获取玩家1的攻击操作

bool ifSecPlayerAtt()
{

	if (GetAsyncKeyState(VK_NUMPAD0)) return 1;

	return false;

}//获取玩家2的攻击操作

void refresh()
{

	int dir1 = dirOfFstPlayer();
	if (dir1 != 0)
	{

		map[p1.y][p1.x] = ' ';
		if (dir1 == 1 && p1.x > 1)
			p1.x--;
		else if (dir1 == 2 && p1.y > 1)
			p1.y--;
		else if (dir1 == 3 && p1.y < wid - 1)
			p1.y++;
		else if (p1.x < len - 1)
			p1.x++;

	}
	int dir2 = dirOfSecPlayer();
	if (dir2 != 0)
	{

		map[p2.y][p2.x] = ' ';
		if (dir2 == 1 && p2.x > 1)
			p2.x--;
		else if (dir2 == 2 && p2.y > 1)
			p2.y--;
		else if (dir2 == 3 && p2.y < wid - 1)
			p2.y++;
		else if (p2.x < len - 1)
			p2.x++;

	}

	if (ifFstPlayerAtt() && (!player1[0].consist) && (!player1[1].consist) && (!player1[2].consist) && (!player1[3].consist))
	{

		player1[0].x = p1.x, player1[0].y = p1.y, player1[0].dir = 1, player1[0].consist = 1;
		player1[1].x = p1.x, player1[1].y = p1.y, player1[1].dir = 2, player1[1].consist = 1;
		player1[2].x = p1.x, player1[2].y = p1.y, player1[2].dir = 3, player1[2].consist = 1;
		player1[3].x = p1.x, player1[3].y = p1.y, player1[3].dir = 4, player1[3].consist = 1;

	}
	if (ifSecPlayerAtt() && (!player2[0].consist) && (!player2[1].consist) && (!player2[2].consist) && (!player2[3].consist))
	{

		player2[0].x = p2.x, player2[0].y = p2.y, player2[0].dir = 1, player2[0].consist = 1;
		player2[1].x = p2.x, player2[1].y = p2.y, player2[1].dir = 2, player2[1].consist = 1;
		player2[2].x = p2.x, player2[2].y = p2.y, player2[2].dir = 3, player2[2].consist = 1;
		player2[3].x = p2.x, player2[3].y = p2.y, player2[3].dir = 4, player2[3].consist = 1;

	}

	player1[0].move(), player1[1].move(), player1[2].move(), player1[3].move();
	player2[0].move(), player2[1].move(), player2[2].move(), player2[3].move();
	ifEnd();

	map[p1.y][p1.x] = '@';
	map[p2.y][p2.x] = '&';

}//更新地图

void print()
{

	for (int t = 0; t <= wid; t++)
	{

		for (int i = 0; i <= len; i++)
			printf("%c", map[t][i]);
		puts("");

	}


}//输出地图

void ifEnd()
{

	if (player1[0].x == p1.x && player1[0].y == p1.y)
		winEnd(2);
	if (player1[1].x == p1.x && player1[1].y == p1.y)
		winEnd(2);
	if (player1[2].x == p1.x && player1[2].y == p1.y)
		winEnd(2);
	if (player1[3].x == p1.x && player1[3].y == p1.y)
		winEnd(2);
	if (player2[0].x == p2.x && player2[0].y == p2.y)
		winEnd(1);
	if (player2[1].x == p2.x && player2[1].y == p2.y)
		winEnd(1);
	if (player2[2].x == p2.x && player2[2].y == p2.y)
		winEnd(1);
	if (player2[3].x == p2.x && player2[3].y == p2.y)
		winEnd(1);
	if (player1[0].x == p2.x && player1[0].y == p2.y)
		winEnd(1);
	if (player1[1].x == p2.x && player1[1].y == p2.y)
		winEnd(1);
	if (player1[2].x == p2.x && player1[2].y == p2.y)
		winEnd(1);
	if (player1[3].x == p2.x && player1[3].y == p2.y)
		winEnd(1);
	if (player2[0].x == p1.x && player2[0].y == p1.y)
		winEnd(2);
	if (player2[1].x == p1.x && player2[1].y == p1.y)
		winEnd(2);
	if (player2[2].x == p1.x && player2[2].y == p1.y)
		winEnd(2);
	if (player2[3].x == p1.x && player2[3].y == p1.y)
		winEnd(2);

}//判断游戏结束

void winEnd(int a)
{

	system("cls");
	if (a == 1)
		cout << "玩家1胜利" << endl;
	else
		cout << "玩家2胜利" << endl;
	Sleep(3000);
	exit(0);

}//输出胜利画面
