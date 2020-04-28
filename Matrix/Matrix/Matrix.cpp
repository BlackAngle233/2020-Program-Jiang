#include <iostream>
#include "Matrix.h"

void test()
{
	int a[4][4]={
		{1,2,3,4},
	    {2,3,4,5},
		{3,4,5,6},
		{4,5,6,7}
	};
	//inputMartix4x4(a);
	printMartix4x4(a);
	cout << "与自身相加：" << endl;
	add(a, a);
	cout << "与自身相减：" << endl;
	substract(a, a);
	cout << "与自身相乘：" << endl;
	multiple(a, a);
}

int main()
{
	std::cout << "test:\n";
	test();

}