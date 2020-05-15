#pragma once
#define E 8	//10个雷
#define M 16	//40个雷
#define H 32	//90个雷
#define ENUM 10
#define MNUM 40
#define HNUM 90
#define Ox 100	//x轴起始坐标
#define Oy 100	//y轴起始坐标

//DifficultyDegree diff;
//MineSweeping mineGame;
enum DifficultyDegree {
	easy,
	medium,
	hard
};

class Cell {//state-开闭状态;x,y-在棋盘上的横纵坐标,mines为周围的地雷个数，只为-1时就是地雷
public:
	int state;//1为开状态，0为关状态,-1为插旗
	int mines;
	int x;
	int y;
	Cell(int, int);
	Cell() { state = 0; mines = 0; x = 0; y = 0; }
	//~Cell() {}
	void setOn() { state = 1; }
	void setFlag() { if (state == 0)state = -1; }
	void removeFlag() {if (state == -1)state = 0;}
};

class MineSweeping {
	DifficultyDegree degree;
	Cell** cellsPtr;
	Cell** create(DifficultyDegree);
	void setMines();//在棋盘上随机设置地雷
	void setCellMines();//在棋盘上设置每个cell的周围地雷数
public:
	MineSweeping(DifficultyDegree d);//给一个难度，随机生成一个棋盘
	MineSweeping() { cellsPtr = nullptr; }
	//~MineSweeping() { delete cellsPtr; }
	void openCells(int, int);//输入i，j，根据相应的雷数将相应格子的状态置为开状态
	void flagCell(int i, int j) { cellsPtr[i][j].setFlag(); }
	void removeFlag(int i, int j) { cellsPtr[i][j].removeFlag(); }
	void show();
	void gameOver();
	bool win();
	Cell** getCellsPtr() { return cellsPtr; }
};