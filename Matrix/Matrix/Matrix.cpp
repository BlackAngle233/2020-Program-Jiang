#include "Matrix.h"
#include <iostream>
#pragma once
using namespace std;

void printMartix4x4(int m1[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m1[i][j] << " ";
		}
		cout << endl;
	}

}

void inputMartix4x4(int m1[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> m1[i][j];
			cout << " ";
		}
		cout << endl;
	}

}

void add(int m1[4][4], int m2[4][4]) 
{
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

void substract(int m1[4][4], int m2[4][4]) 
{
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
			result[i][j] = m1[i][j] * m2[j][i];
		}
	}
	printMartix4x4(result);
}

void test()
{
	int a[4][4];
	int b[4][4];
	inputMartix4x4(a);
	inputMartix4x4(b);
	printMartix4x4(a);
	printMartix4x4(b);
	cout << "sum" << endl;
	add(a, b);
	cout << "minus" << endl;
	substract(a, b);
	cout << "mulpitle" << endl;
	multiple(a, b);
}

int main()
{
	cout << "test:" << endl;
	test();
	int t = 0;
	std::cin >> t;
}