// hw2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
using namespace std;

void test()
{
	int a[4][4];
	inputMartix4x4(a);
	printMartix4x4(a);
	add(a, a);
	m_minus(a, a);
	multiple(a, a);
}

int main()
{
	std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}