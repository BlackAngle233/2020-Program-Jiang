#include <iostream>
#include "Matrix4.h"

void test() 
{
	std::cout << "m1:\n";
	Mat m1;
	inputMartix4x4(m1);
	std::cout << "m2:\n";
	Mat m2;
	inputMartix4x4(m2);
	std::cout << "multiple:\n";
	Mat m3 = multiple(m1, m2);
	printMartix4x4(m3);
}

int main()
{
    std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}