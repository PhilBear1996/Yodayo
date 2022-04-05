#ifndef Tetris_h
#define Tetris_h

class Tetris
{
	private:
		int rank;		
		int score;
		int id;	
		int point[2];
		int top;	
	public:
		Tetris();
		void welocme();
		void drawMap();
		void setColor(int);
		void draw(int, int, int);
		void run();	
		void reDraw(int, int, int);
		bool judge(int, int, int);
		void turn(int);	
		void updata();	
		void setPos(int i, int j);
		void pause();
		void input_score();
};

#endif