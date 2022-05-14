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

const int sharp [19][8]={
{0,0,1,0,2,0,3,0},		//直的直條
{0,0,0,1,0,2,0,3},		//橫的直條
{0,0,1,0,0,1,1,1},		//田字
{0,0,1,0,1,1,1,2},		//反L形 向右轉90度
{0,1,1,1,2,0,2,1},		//反L形
{0,0,0,1,0,2,1,2},		//反L形 向左轉90度
{0,0,0,1,1,0,2,0},		//反L形 轉180度
{1,0,1,1,1,2,0,2},		//L形 向左轉90度
{0,0,0,1,1,1,2,1},		//L形 轉180度
{0,0,0,1,0,2,1,0},		//L形 向右轉90度
{0,0,1,0,2,0,2,1},		//L形
{0,0,0,1,1,1,1,2},		//反S形
{0,1,1,0,1,1,2,0},		//反S形 轉90度
{0,1,0,2,1,0,1,1},		//S形
{0,0,1,0,1,1,2,1},     		//S形 轉90度
{1,0,0,1,1,1,1,2},		//T形 轉180度
{1,0,0,1,1,1,2,1},		//T形 向左轉90度
{0,1,1,1,2,1,1,2},		//T形 向右轉90度
{0,0,0,1,1,1,0,2}		//T形
};
Tetris::Tetris(){
	point[0] = 0;
	point[1] = 5;
	score = 0;
	top = 25;
}
void Tetris::setPos(int i, int j){
	COORD pos = { i, j };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Tetris::Input_score(){
	
}
void Teris::welcome(){
	setColor(1);
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
void Tetris::drawMap(){
	int i;
	setColor(0);

	for (i = 0; i < 24; i++)
	{
		setPos(i * 2, 0);
		cout << "■";
		setPos(i * 2, 26);
		cout << "■";
	}

	for (i = 0; i < 26; i++)
	{
		setPos(0, i);
		cout << "■";
		setPos(28, i);
		cout << "■";
		setPos(46, i);
		cout << "■";
	}

	for (i = 14; i < 24; i++)
	{
		setPos(i * 2, 16);
		cout << "■";
	}

	setColor(3);
	input_score();
	setPos(30, 21);
	cout << "難度等級: " << rank;
	setPos(32, 2);
	cout << "下一圖形";
}
void Tetris::turn(int num){
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
void Tetris::draw(int x, int y, int num){
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
void Tetris::reDraw(int x, int y, int num){
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + sharp[num][2 * i];
		ny = y + sharp[num][2 * i + 1];
		setPos((ny + 1) * 2, nx + 1);
		cout << "  ";
	}
}
void Tetris::setColor(int color_num){
	int n=0x0f;
	switch (color_num){
	case 0: n = 0x08; break;
	case 1: n = 0x0E; break;
	case 2: n = 0x0D; break;
	case 3: n = 0x0E; break;
	case 4: n = 0x0A; break;
	}
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}
bool Tetris::judge(int x, int y, int num){
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + sharp[num][2 * i];
		ny = y + sharp[num][2 * i + 1];
		if (!(nx < 25 && nx >= 0 && ny < 13 && ny >= 0 && !map[nx][ny]))
			return true;
	}
	return false;
}
void Tetris::Run(){
	int next-id;
	srand(time(0));

	id = rand() % 15;
	next_id = rand() % 15;

	Draw(point[0], point[1], id);
	Draw(5, 16, next_id);

	int count;
	if (rank == 1) {
		count = 150;
	}
	else if (rank == 2) {
		count = 100;
	}
	else if (rank ==3) {
		count = 50;
	}
	else
	    count = 5;
	int i = 0; 
	while (1){
	
	}
	
	
}	
void Tetris::updata(){
	int i, flag;
	int nx, ny;
	for (i = 0; i < 4; i++)
	{
		nx = point[0] + sharp[id][i * 2];
		ny = point[1] + sharp[id][i * 2 + 1];
		setPos((ny + 1) * 2, nx + 1);
		setColor(0);
		cout << "■";
		map[nx][ny] = 1;
	}

	if (point[0] < top)
		top = point[0];

	for (i = point[0]; i < point[0] + high[id]; i++)
	{
		flag = 1;
		for (int j = 0; j < 13; j++)
			if (map[i][j] == 0)
				flag = 0;
		if (flag == 1)
		{
			for (int k = i; k >= top; k--)
			{
				for (int p = 0; p < 13; p++)//gai
				{
					map[k][p] = map[k - 1][p];
					setPos((p + 1) * 2, k + 1);
					if (map[k][p] == 1)
						cout << "■";
					else cout << "  ";
				}
			}
			if (flag == 1) score += 100;
			else if (flag == 2) score += 300;
			else if (flag == 3) score += 500;
			else if (flag == 4) score += 800;
			input_score();
		}
	}
}
void Tetris::pause(){
	setPos(32, 10);
	cout << "游戲暫停!" << endl;
	setPos(30, 11);
	cout << "你的分數為 " << score;
	char temp;
	while (1)
	{
		while (1)
		{
			if (_kbhit())
			{
				temp = _getch();
				break;
			}
		}
		if (temp == 32)
			break;
	}
	setPos(32, 10);
	cout << "         ";
	setPos(30, 11);
	cout << "              ";
}
void Tetris::input_score(){
	setColor(3);
	setPos(30, 19);
	cout << "得分: " << score;
}
