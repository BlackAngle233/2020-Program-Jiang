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
	int r[4][4];
	Add(a, b, r);
	printMartix4x4(r);	cout << endl;
	Minus(a, b, r);
	printMartix4x4(r);	cout << endl;
	Multiple(a, b, r);
	printMartix4x4(r);	cout << endl;
}

int main()
{
    std::cout << "test2:\n";
	test();
	return 0;
}