#include"stdafx.h"
#include"MineSweeping.h"
//#include"afxwin.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>


using namespace std;

int C;	//行数
int R;	//列数
int mNum;	//雷数


Cell** MineSweeping::create(DifficultyDegree difficulty) {
	switch (difficulty) {	//设置行列数
	case DifficultyDegree::easy:
		C = R = E;
		mNum = ENUM;
		break;
	case DifficultyDegree::medium:
		C = R = M;
		mNum = MNUM;
		break;
	case DifficultyDegree::hard:
		C = H;
		R = M;
		mNum = HNUM;
		break;
	}
	Cell** c = new Cell *[C];
	for (int i = 0; i < C; i++) {
		Cell* r = new Cell[R];
		for (int j = 0; j < R; j++) {
			r[j] = Cell(i, j);
		}
		c[i] = r;
	}
	return c;
}

void MineSweeping::setMines() {
	srand((unsigned int)(time(NULL)));
	for (int k = 0; k < mNum;) {
		int i = rand() % C;
		int j = rand() % R;
		if (cellsPtr[i][j].mines != -1) {
			cellsPtr[i][j].mines = -1;
			k++;
		}
	}
}

void MineSweeping::setCellMines() {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (cellsPtr[i][j].mines == -1) {
				if (i - 1 >= 0) {
					if (cellsPtr[i - 1][j].mines != -1)
						cellsPtr[i - 1][j].mines++;
					if (j - 1 >= 0)
						if (cellsPtr[i - 1][j - 1].mines != -1)cellsPtr[i - 1][j - 1].mines++;
					if (j + 1 < R)
						if (cellsPtr[i - 1][j + 1].mines != -1)cellsPtr[i - 1][j + 1].mines++;
				}
				if (i + 1 < C) {
					if (cellsPtr[i + 1][j].mines != -1)
						cellsPtr[i + 1][j].mines++;
					if (j - 1 >= 0)
						if (cellsPtr[i + 1][j - 1].mines != -1)cellsPtr[i + 1][j - 1].mines++;
					if (j + 1 < R)
						if (cellsPtr[i + 1][j + 1].mines != -1)cellsPtr[i + 1][j + 1].mines++;
				}
				if (j - 1 >= 0)
					if (cellsPtr[i][j - 1].mines != -1)cellsPtr[i][j - 1].mines++;
				if (j + 1 < R)
					if (cellsPtr[i][j + 1].mines != -1)cellsPtr[i][j + 1].mines++;
			}
		}
	}
}

MineSweeping::MineSweeping(DifficultyDegree d) {
	cellsPtr = create(d);
	degree = d;
	this->setMines();
	this->setCellMines();
}

void MineSweeping::show() {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			std::cout << "(" << i << "," << j << ") :";
			std::cout << "state: " << cellsPtr[i][j].state << "mines: " << cellsPtr[i][j].mines << "   ";
		}
		std::cout << std::endl;
	}
}

void MineSweeping::openCells(int i, int j) {
	if (cellsPtr[i][j].state == 1)
		return;
	if (cellsPtr[i][j].mines != 0) {
		cellsPtr[i][j].setOn();
		return;
	}
	else {
		cellsPtr[i][j].setOn();
		if (j - 1 >= 0) openCells(i, j - 1);
		if (j + 1 < R) openCells(i, j + 1);
		if (i - 1 >= 0) {
			openCells(i - 1, j);
			if (j - 1 >= 0) openCells(i - 1, j - 1);
			if (j + 1 < R) openCells(i - 1, j + 1);
		}
		if (i + 1 < C) {
			openCells(i + 1, j);
			if (j - 1 >= 0) openCells(i + 1, j - 1);
			if (j + 1 < R) openCells(i + 1, j + 1);
		}
	}
}

void MineSweeping::gameOver() {
	for(int i=0;i<C;i++)
		for (int j = 0;j < R;j++) {
			if (cellsPtr[i][j].mines == -1)
				cellsPtr[i][j].setOn();
		}
}

bool MineSweeping::win() {
	for(int i=0;i<C;i++)
		for (int j = 0;j < C;j++) {
			if (cellsPtr[i][j].mines == -1) {
				if (cellsPtr[i][j].state != -1)
					return false;
			}
			else {
				if (cellsPtr[i][j].state == -1)
					return false;
			}
		}
	return true;
}

Cell::Cell(int i, int j) {
	x = i;
	y = j;
	state = 0;
	mines = 0;
}