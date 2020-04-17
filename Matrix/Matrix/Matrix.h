#include <iostream>
#pragma once
using namespace std;

void printM(int m[4][4])
{
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void inputM(int m[4][4]) 
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void plusM(int m[4][4], int n[4][4])
{
	int result[4][4] {0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m[i][j] + n[i][j];
		}
	}
	printM(result);
}

void subM(int m[4][4], int n[4][4])
{
	int result[4][4] {0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m[i][j] - n[i][j];
		}
	}
	printM(result);
}

void multM(int m[4][4], int n[4][4])
{
	int result[4][4] {0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				result[i][j] = m[i][k] * n[k][j] + result[i][j];
			}
		}
	}
	printM(result);
}