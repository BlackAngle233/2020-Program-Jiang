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
	int x[4][4];
	add(a, b, x);
	cout << "减法结果如下：" << endl;
	int y[4][4];
	Minus(a, b, y);
	cout << "乘法结果如下：" << endl;
	int z[4][4];
	multiple(a, b, z);
}

int main()
{
    std::cout << "test:\n";
	test();
}