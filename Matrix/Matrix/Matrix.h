#pragma once
#include <iostream>
using namespace std;

class Matrix {
public:
	void printMartix4x4(int m[4][4]);
	void inputMartix4x4(int m[4][4]);
	void add(int m1[4][4], int m2[4][4], int result[4][4]);
	void substract(int m1[4][4], int m2[4][4], int result[4][4]);
	void multiple(int m1[4][4], int m2[4][4], int result[4][4]);
};
