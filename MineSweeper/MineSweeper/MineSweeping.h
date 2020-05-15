#pragma once
#define E 8	//10����
#define M 16	//40����
#define H 32	//90����
#define ENUM 10
#define MNUM 40
#define HNUM 90
#define Ox 100	//x����ʼ����
#define Oy 100	//y����ʼ����

//DifficultyDegree diff;
//MineSweeping mineGame;
enum DifficultyDegree {
	easy,
	medium,
	hard
};

class Cell {//state-����״̬;x,y-�������ϵĺ�������,minesΪ��Χ�ĵ��׸�����ֻΪ-1ʱ���ǵ���
public:
	int state;//1Ϊ��״̬��0Ϊ��״̬,-1Ϊ����
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
	void setMines();//��������������õ���
	void setCellMines();//������������ÿ��cell����Χ������
public:
	MineSweeping(DifficultyDegree d);//��һ���Ѷȣ��������һ������
	MineSweeping() { cellsPtr = nullptr; }
	//~MineSweeping() { delete cellsPtr; }
	void openCells(int, int);//����i��j��������Ӧ����������Ӧ���ӵ�״̬��Ϊ��״̬
	void flagCell(int i, int j) { cellsPtr[i][j].setFlag(); }
	void removeFlag(int i, int j) { cellsPtr[i][j].removeFlag(); }
	void show();
	void gameOver();
	bool win();
	Cell** getCellsPtr() { return cellsPtr; }
};