#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4];
	int b[4][4];
	cout << "请输入四阶矩阵m1：" << endl;
	inputMartix4x4(a);
	cout << "请输入四阶矩阵m2：" << endl;
	inputMartix4x4(b);
	printMartix4x4(a);
	printMartix4x4(b);
	cout << "加法结果如下：" << endl;
	add(a, b);
	cout << "减法结果如下：" << endl;
	Minus(a, b);
	cout << "乘法结果如下：" << endl;
	multiple(a, b);
}

int main()
{
    std::cout << "test:\n";
	test();

	int t = 0;
	std::cin >> t;
}