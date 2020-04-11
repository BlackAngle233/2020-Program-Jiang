#include <iostream>
#pragma once
using namespace std;

class Mat4
{
public:
	int mat[4][4]{};

	Mat4();

	void Input();

	Mat4 operator+(Mat4& m);

	Mat4 operator-(Mat4& m);

	Mat4 operator*(Mat4& m);

	void Print();

};