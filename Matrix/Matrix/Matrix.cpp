#include <iostream>
#include "Matrix.h"

void test() 
{
	int l_number[4][4];
	int r_number[4][4];
	cout << "输入第一个矩阵(16个数字)" << endl;
	input_number(l_number);
	print_number(l_number);
	cout << "输入第二个矩阵(16个数字)" << endl;
	input_number(r_number);
	print_number(r_number);
    cout << "两者相加：" << endl;
	add(l_number, r_number);
	cout << "两者相减：" << endl;
	substract(l_number, r_number);
	cout << "两者相乘：" << endl;
	multiple(l_number, r_number);
}

int main()
{
    std::cout << "test:\n";
	test();
}