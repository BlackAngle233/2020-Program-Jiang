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
    //std::cout << "test:\n";
	//test();
	int t = 0;
	std::cin >> t;
	int a[4][4];
	int b[4][4];
	while (t > 0) {
		std::cout << "输入m1:" << endl;
		inputMartix4x4(a);
		std::cout << "输入m2:" << endl;
		inputMartix4x4(b);std::cout << endl;
		printMartix4x4(a);std::cout << endl;
		printMartix4x4(b);std::cout << endl;
		add(a, b);std::cout << endl;
		//minus(a, b);
		::minus(a, b);std::cout << endl;
		multiple(a, b);
		t--;
	}
}