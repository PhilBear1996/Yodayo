#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdio>
#include "Tetris.h"
using namespace std;

const int high[15] = { 4,1,2,2,3,2,3,2,3,2,3,2,3,2,3 };
int map[28][16];

Tetris::Tetris()
{
	point[0] = 0;
	point[1] = 5;
	score = 0;
	top = 25;
}

void Tetris::setPos(int i, int j)
{
	COORD pos = { i, j };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
