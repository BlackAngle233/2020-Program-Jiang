#pragma once
using namespace std;
#include<ostream>


class Mat4
{
public:
	int mat[4][4]{};

	Mat4();

	Mat4(int[][4]);
	void Input();

	Mat4 operator+(const Mat4& m);

	Mat4 operator-(const Mat4& m);

	Mat4 operator*(const Mat4& m);

	void Print();

};

ostream& operator<< (ostream& os, const Mat4&);