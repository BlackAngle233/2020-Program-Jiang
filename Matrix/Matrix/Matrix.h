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

void inputMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

int Sum4x4(int a[4][4], int b[4][4])
{
	int sum[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
	cout << "矩阵之和为：" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int Minus4x4(int a[4][4], int b[4][4])
{
	int minus[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			minus[i][j] = a[i][j] - b[i][j];
		}
	}
	cout << "矩阵之差为：" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << minus[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int Multiply4x4(int a[4][4], int b[4][4])
{
	int x = 0;
	int multiply[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int z = 0; z < 4; z++)
			{
				x += a[i][z] * b[z][j];
			}
			multiply[i][j] = x;
			x = 0;
		}
	}
	cout << "矩阵之积为：" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << multiply[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}