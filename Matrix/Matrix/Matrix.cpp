#include <iostream>
#include "Matrix.h"

void test() 
{
	int a[4][4];
	int b[4][4];
	int result[4][4];
	inputMartix4x4(a);
	inputMartix4x4(b);
	add(a, b,result);
	printMartix4x4(result);
	minus1(a, b,result);
	printMartix4x4(result);
	multiple(a, b,result);
	printMartix4x4(result);
	/*Max4 max = { 1 };
	Max4 max1 = { 2 };
	Max4 max2 = { 0 };
	max2=add(max, max1);
	print(max2);*/
}


int main()
{
    std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;

}

