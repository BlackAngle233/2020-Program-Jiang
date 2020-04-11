#include <iostream>
#include "Matrix.h"
using namespace std;

void test()
{
	int a[4][4];
	int b[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> b[i][j];
		}
	}
	int c[4][4];
	Add(a, b, c);
	Print(c);
	int d[4][4];
	Minus(a, b, d);
	Print(d);
	int e[4][4];
	Multiple(a, b, e);
	Print(e);
}

int main()
{
	test();
	return 0;
}