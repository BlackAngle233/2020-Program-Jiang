#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4];
	inputMartix4x4(a);
	printMartix4x4(a);
}

int main()
{
    std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}