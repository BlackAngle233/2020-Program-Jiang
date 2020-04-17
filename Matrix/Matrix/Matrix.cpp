#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4];
	int b[4][4];
	cout << "inputMartix4x4 A:" << endl;
	inputMartix4x4(a);
	cout << "inputMartix4x4 B:" << endl;
	inputMartix4x4(b);
	int r1[4][4];
	Add(a, b, r1);
	int r2[4][4];
	Minus(a, b, r2);
	int r3[4][4];
	Multiple(a, b, r3);
}

int main()
{
    std::cout << "test2:\n";
	test();
	return 0;
}