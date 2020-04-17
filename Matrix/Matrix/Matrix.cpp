#include <iostream>
#include "Matrix.h"

void test()
{
	int a[4][4];
	int b[4][4];
	cout << "请输入第一个4x4矩阵：" << endl;
	inputM(a);
	cout << "请输入第二个4x4矩阵：" << endl;
	inputM(b);
	cout << "矩阵的和：" << endl;
	plusM(a, b);
	cout << "矩阵的差：" << endl;
	subM(a, b);
	cout << "矩阵的积：" << endl;
	multM(a, b);
}

int main()
{
	test();
}