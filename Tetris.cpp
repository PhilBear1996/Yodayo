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
void Teris::welcome(){
	setColor(1);
	int x;
	while(1){
		ststem("cls");
		cout << "------------------------------------------" << endl;
		cout << "		俄羅斯方塊		"<< endl;
		cout << "------------------------------------------" << endl;
		cout << "               操作方式 : " << endl;
		cout << "                ↑ : 旋轉" << endl;
		cout << "                ↓ : 加速下移" << endl;
		cout << "                ← : 左移" << endl;
		cout << "                → : 右移" << endl;
		cout << "              空格 : 暫停" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "< 1到9選擇難度 >" << endl;
		setPos(20, 10);
		cin >> x;
		
		rank = x;
		break;
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

	setColor(1);
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
		setColor(1);
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
	int n = 0x0C;
	switch (color_num)
	{
		case 0: n = 0x0F; break;
		case 1: n = 0x0E; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
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
void Tetris::run(){
	int next_id;
	srand((int)time(0));

	id = rand() % 19;
	next_id = rand() % 19;

	Draw(point[0], point[1], id);
	Draw(5, 16, next_id);

	int count;
	switch (rank)
	{
		case 1:
			count = 150;
			break;
		case 2:
			count = 125;
			break;
		case 3:
			count = 100;
			break;
		case 4:
			count = 75;
			break;
		case 5:
			count = 50;
			break;
		case 6:
			count = 40;
			break;
		case 7:
			count = 25;
			break;
		case 8:
			count = 10;
			break;
		case 9:
			count = 5;
			break;
		default:
			system("cls");
			cout << "輸入錯誤，游戲結束！" << endl;
			setColor(1);
			cout << endl;
			system("pause");
			exit(1);
	}
	
	int i = 0; 
	while (1){
	
	}
	
	while(1)
	{
		if(!(i < count))				
		{
			i = 0;
			if(judge(point[0] + 1, point[1], id))			
			{
				updata();
				id = next_id;

				reDraw(5, 16, next_id);
				next_id = rand() % 19;

				point[0] = 0; point[1] = 5;
				draw(point[0], point[1], id);
				draw(5, 16, next_id);

				if(judge(point[0], point[1], id))
				{
					system("cls");
					cout << "游戲結束！" << endl;
	 				cout << endl;
					cout << "你的分數為 " << score << endl;
					cout << endl;
					system("pause");
					exit(1);
				}
			}
			else					
			{
				reDraw(point[0], point[1], id);
				point[0]++;
				draw(point[0], point[1], id);
			}
		}

		if(_kbhit())				
		{
  			int key, key2;
			key = _getch();
			if(key == 224)
			{
				key2 = _getch();

				if(key2 == 72)			
				{
					int temp = id;
					turn(id);
					if (judge(point[0], point[1], id))
						id = temp;
					reDraw(point[0], point[1], temp);
					draw(point[0], point[1], id);
				}
				if(key2 == 80)				
				{
					if(!judge(point[0] + 2, point[1], id))
					{
						reDraw(point[0], point[1], id);
						point[0] += 2;
						draw(point[0], point[1], id);
					}
				}
				else if(key2 == 75)				
				{
					if(!judge(point[0], point[1] - 1, id))
					{
						reDraw(point[0], point[1], id);
						point[1]--;
						draw(point[0], point[1], id);
					}
				}
				else if(key2 == 77)					
				{
					if(!judge(point[0], point[1] + 1, id))
					{
						reDraw(point[0], point[1], id);
						point[1]++;
						draw(point[0], point[1], id);
					}
				}
			}
			else if(key == 32)					
				pause();
		}

		Sleep(1);		
		i++;
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
void Tetris::input_score()
{
	setColor(1);
	setPos(30, 19);
	cout << "得分: " << score;
}
