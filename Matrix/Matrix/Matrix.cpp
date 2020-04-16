#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4];
	int b[4][4];
	cout << "input first martix:" << endl;
	inputMartix4x4(a);
	printMartix4x4(a);
	cout << "input second martix:" << endl;
	inputMartix4x4(b);
	printMartix4x4(b);
	cout << "add martixs:" << endl;
	addMartix(a, b);
	cout << "minus martixs:" << endl;
	minusMartix(a, b);
	cout << "multiple martixs:" << endl;
	multipleMartix(a, b);
}

int main()
{
    std::cout << "test:\n";
	test();
	cout << "press any number to countinue..." << endl;
	int t = 0;
	std::cin >> t;
}