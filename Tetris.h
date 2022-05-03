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
		void setPos(int i, int j);
		void welocme();
		void drawMap();
		void turn(int);	
		void draw(int, int, int);
		void reDraw(int, int, int);
		void setColor(int);
		bool judge(int, int, int);
		void updata();	
		void pause();
		void input_score();
		void run();
};

#endif
