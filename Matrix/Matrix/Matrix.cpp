#include <iostream>
#include "Matrix.h"

void test() 
{
	int m1[4][4];
	int m2[4][4];
	std::cout << "请输入第一个矩阵:\n";
	inputMartix4x4(m1);
	std::cout << "请输入第二个矩阵:\n";
	inputMartix4x4(m2);

	std::cout << "M1+M2结果为:\n";
	add(m1, m2);
	std::cout << "M1-M2结果为:\n";
	substract(m1, m2);
	std::cout << "M1*M2结果为:\n";
	multiple(m1, m2);

}

int main()
{
    std::cout << "test:\n";
	test();
	system("pause");
}