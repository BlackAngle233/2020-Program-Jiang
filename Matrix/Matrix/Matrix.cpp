#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4], b[4][4];
	std::cout << "Input array1:" << endl;
	inputMartix4x4(a);
	std::cout << "Input array2:" << endl;
	inputMartix4x4(b);
	std::cout << "print array1:" << endl;
	printMartix4x4(a);
	std::cout << "print array2:" << endl;
	printMartix4x4(b);
	std::cout << "a+b=" << endl;
	add(a, b);
	std::cout << "a-b=" << endl;
	substract(a, b);
	std::cout << "a*b=" << endl;
	multiple(a, b);
}

int main()
{
    std::cout << "test:\n";
	test();
}