#include <iostream>
#pragma once
#include <variable.h>
using namespace std;

void printMartix4x4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j];
		}
	}
}

void inputMartix4x4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
}

void add(int m1[4][4], int m2[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void minus(int m1[4][4], int m2[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = m1[i][j] - m2[i][j];
		}
	}
}

void multiple(int m1[4][4], int m2[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = m1[i][j] * m2[i][j];
		}
	}
}
