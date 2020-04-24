﻿#include <iostream>
#include "Matrix.h"

void test()
{
	int a[4][4];
	int b[4][4];
	cout << "请输入四阶矩阵a：" << endl;
	inputMartix4x4(a);
	cout << "请输入四阶矩阵b：" << endl;
	inputMartix4x4(b);
	cout << "整理如下：" << endl;
	printMartix4x4(a);
	printMartix4x4(b);
	cout << "加法结果如下：" << endl;
	int c[4][4];
	add(a, b, c);
	cout << "减法结果如下：" << endl;
	int d[4][4];
	Minus(a, b, d);
	cout << "乘法结果如下：" << endl;
	int e[4][4];
	multiple(a, b, e);
}

int main()
{
	std::cout << "test:\n";
	test();

	int t = 0;
	std::cin >> t;
}
