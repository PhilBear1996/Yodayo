#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<cstdio>
#include "Tetris.h"
using namespace std;
int main()
{
	Tetris game;
	game.welcome();
	system("cls");				
	game.drawMap();
	game.run();
	system("pause");
}

