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

#define d1 7
#define d2 8
#define d3 9
#define d4 10

#define e1 11
#define e2 12

#define f1 13
#define f2 14


#define g1 15			
#define g2 16
#define g3 17
#define g4 18

const int sharp [19][8]=
{
	{0,0,1,0,2,0,3,0},
	{0,0,0,1,0,2,0,3},
	{0,0,1,0,0,1,1,1},
	{0,0,1,0,1,1,1,2},
	{0,1,1,1,2,0,2,1},	
	{0,0,0,1,0,2,1,2},		
	{0,0,0,1,1,0,2,0},
	{1,0,1,1,1,2,0,2},	
	{0,0,0,1,1,1,2,1},	
	{0,0,0,1,0,2,1,0},		
	{0,0,1,0,2,0,2,1},		
	{0,0,0,1,1,1,1,2},		
	{0,1,1,0,1,1,2,0},	
	{0,1,0,2,1,0,1,1},	
	{0,0,1,0,1,1,2,1},     
	{1,0,0,1,1,1,1,2},		
	{1,0,0,1,1,1,2,1},		
	{0,1,1,1,2,1,1,2},		
	{0,0,0,1,1,1,0,2}		
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
		case a2: id = a1;break;
		
		case b : id = b; break;
		
		case c1: id = c2;break;
		case c2: id = c3;break;
		case c3: id = c4;break;
		case c4: id = c1;break;
		
		case d1: id = d2;break;
		case d2: id = d3;break;
		case d3: id = d4;break;
		case d4: id = d1;break;
			
		case e1: id = e2;break;
		case e2: id = e1;break;
			
		case f1: id = f2; break;
		case f2: id = f1; break;
		
		case g1: id = g2; break;				
		case g2: id = g3; break;
		case g3: id = g4; break;
		case g4: id = g1; break;
	}
}
void Teris::welcome{
	char x;
	while(1){
		ststem("cls");
		cout << "----------------------" << endl;
		cout <<".  俄羅斯方塊" << endl;
		cout << "-----------------------" << endl;
		cout << " 操作方式：" << endl;
		cout << "  ↑ : 旋轉" << endl;
		cout << "  ↓ : 加速下移" << endl;
		cout << "  ← : 左移" << endl;
		cout << "  → : 右移" << endl;
		cout << "空格 : 暫停" << endl;
		cout << "-----------------------" << endl;
		cout << "< 1到9選擇難度 >" << endl;
		setPos(20, 10);
		x = getchar();
		if (x <= '9' && x >= '0')
		{
			rank = x - '0';
			break;
		}

	}
}	
void Tetris::SetColor(int color_num)		
{
	int n=0x0f;
	switch (color_num)
	{
	case 0: n = 0x08; breeak;
	
	case 1: n = 0x0E; break;
	case 2: n = 0x0D; break;
	case 3: n = 0x0E; break;
	case 4: n = 0x0A; break;
	}
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}
