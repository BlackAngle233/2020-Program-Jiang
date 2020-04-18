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

void lesson() {
	Mat4 a;
	Mat4 b;
	initMat4(a);
	initMat4(b);

	Mat4 c = add(a, b);
	print(c);
}

int main()
{
    std::cout << "test:\n";
	//test();
	lesson();
}