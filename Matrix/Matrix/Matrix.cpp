#include <iostream>
#include "Matrix.h"

void test() 
{
	std::cout << "m1:\n";
	int m1[4][4];
	inputMartix4x4(m1);
	std::cout << "m2:\n";
	int m2[4][4];
	inputMartix4x4(m2);
	std::cout << "multiple:\n";
	multiple(m1, m2);
}

int main()
{
    std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}