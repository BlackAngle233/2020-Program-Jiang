#include <iostream>
#pragma once
#ifndef MATRIX
#define MATRIX
using namespace std;

void Print(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void Add(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void Minus(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void Multiple(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
		}
	}
}
#endif //MAT4_H
