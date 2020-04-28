#include <iostream>
#pragma once
using namespace std;

void printMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

//void inputMartix4x4(int m[4][4]) {
//	for (int i = 0; i < 4; ++i) {
//		for (int j = 0; j < 4; ++j) {
//			cin >> m[i][j];
//			cout << " ";
//		}
//		cout << endl;
//	}
//}

void add(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printMartix4x4(result);
}

void substract(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
	printMartix4x4(result);
}

void multiple(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = 0;
			for (int k = 0; k < 4; ++k)
			{
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printMartix4x4(result);
}
struct Mat4 {
	int m[4][4];
};
void print(Mat4& a)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << a.m[i][j] << " ";
		}
		cout << endl;
	}
}

Mat4 add(const Mat4& a, const Mat4& b)
{
	int result[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = a.m[i][j] + b.m[i][j];
		}
	}
};