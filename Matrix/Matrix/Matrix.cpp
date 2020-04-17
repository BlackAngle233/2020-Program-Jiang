#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4]; int b[4][4];

    std::cout << "-------------------------------" << endl;
	std::cout << "请输入矩阵A:" << endl;
	inputMartix4x4(a);

    std::cout << "-------------------------------" << endl;
	std::cout << "请输入矩阵B:" << endl;
	inputMartix4x4(b);

	std::cout << "-------------------------------" << endl;
	std::cout << "A+B:" << endl;
	Add(a, b);

	std::cout << "-------------------------------" << endl;
	std::cout << "A-B:" << endl;
	Minus(a, b);

	std::cout << "-------------------------------" << endl;
	std::cout << "A*B:" << endl;
	Multiple(a, b);

}

int main()
{
    std::cout << "test:\n";
	test();
}