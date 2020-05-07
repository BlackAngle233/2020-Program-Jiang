#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

enum class Difficulty
{
	Easy,    //0.13
	Medium,  //0.16
	Difficult,   //0.21
	Custom,
};

struct ShowMap
{
	bool isRecur = false;
	bool isFlagInsert = false;
	string showValue;
	string Sign = "P";
};
class MinesWeeper
{
public:
	MinesWeeper(int n, int &rows, int &cols);
	bool IsLose;
	bool IsWin;
	//Difficulty SelectMode(int n, int& rows, int& cols);
	void EnumPrint(string** map, int rows, int cols);
	void EnumInitMap(string** map, int rows, int cols);
	void EnumMsCreate(string** map, int rows, int cols);
	void OpenMap(string** map, int row, int col);
	void UpdateMap(string **map, int rows, int cols);
	void SignMs(int row, int col);
	void SignMsVoke(int row, int col);
	void MsJudge(string **map, int row, int col);
private:
	Difficulty mode;
	ShowMap **Show;
	int MS_num;
	int MS_coordinate;
	int Sign_num;
	int maxRow;
	int maxCol;
	bool flag;
	bool flag2;
	bool flag3;
	bool flag4;
	bool isFirst;
	int* MS_coordinate_List;
};

