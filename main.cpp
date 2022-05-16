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
	game.Welocme();
	system("cls");				
	game.DrawMap();
	game.Run();
	system("pause");
}

/*
void blockT
class Tetris
{
  private:
    
}
class Move
{
  private:
    
}
class Eliminate
{
  private:
    
}
using namespace std;
int main{
  
  return 0;
}
*/







