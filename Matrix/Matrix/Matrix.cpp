#include <iostream>
#include "Matrix.h"
#include "mat4.cpp"

void test() 
{
	int a[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	inputMartix4x4();
	printMartix4x4();
	cout << "相加：" << endl;
	add(a, a);
	cout << "相减：" << endl;
	substract(a, a);
	cout << "相乘：" << endl;
	multiple(a, a);
}

int main()
{
    std::cout << "test:\n";
	test();
}