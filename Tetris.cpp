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

#define a1 0
#define a2 1

#define b 2

#define c1 3
#define c2 4
#define c3 5
#define c4 6

const int sharp [19][8]=
{
	{0,0,1,0,2,0,3,0},
	{0,0,0,1,0,2,0,3},
	{0,0,1,0,0,1,1,1},
	{0,0,1,0,1,1,1,2},
	{0,1,1,1,2,0,2,1},	
	{0,0,0,1,0,2,1,2},		
	{0,0,0,1,1,0,2,0},		
	
}
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
void Tetris::draw(int x, int y, int num)
{
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + sharp[num][2 * i];
		ny = y + sharp[num][2 * i + 1];
		setPos((ny + 1) * 2, nx + 1);
		setColor(i + 1);
		cout << "■";
	}
}
void Tetris::turn(int num)
{
	switch(num)
	{
		case a1: id = a2;break;		
	}
}
