#pragma once

#include "pch.h"
#include <iostream>
//#include <stdio.h>
//#include<windows.h>
//#include <ctime>
using namespace std;

enum Type { easy, middle, hard ,sellfsetting};
class mine1 {
public:
	int  block[32][32] = { 0 };
	bool  mine[32][32] = { false };
	bool  isClick[32][32] = { false };
	void Search(int x, int y, int maxx, int maxy);


	void showall(int maxx, int maxy);
	void Getnum(int maxx, int maxy);


	void Spawnmine(int maxx, int maxy, int minenum);
	void Born(int maxx, int maxy);
	
};