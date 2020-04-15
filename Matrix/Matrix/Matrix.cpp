#include <iostream>
#include "Matrix.h"
using namespace std;
void test() 
{
	int a[4][4],b[4][4];
	cout << "输入矩阵a" << endl;
	inputMartix4x4(a);
	printMartix4x4(a);
	cout << "输入矩阵b" << endl;
	inputMartix4x4(b);
	printMartix4x4(b);
	cout << "a+b:" << endl;
	add(a, b);
	cout << "a-b:" << endl;
	minuss(a, b);
	cout << "a*b:" << endl;
	multiple(a, b);
	
}

int main()
{
   cout << "test:\n";
	test();
}