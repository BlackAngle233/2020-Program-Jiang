#include <iostream>
#include"pch.h"
#include "Matrix.h"
using namespace std;

void test()
{
	int a[4][4];
	int b[4][4];
	inputMartix4x4(a);
	inputMartix4x4(b);
	printMartix4x4(a);
	cout<<endl;
	printMartix4x4(b);

	add(a, b);
	minus1(a, b);
	multiple(a, b);
}

int main()
{
	std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}
