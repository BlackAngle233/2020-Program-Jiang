#include<iostream>
#include "Matrix.h"
using namespace std;

void test()
{
	int a[4][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7} };
	int b[4][4] = { {2,3,4,5},{3,4,5,6},{4,5,6,7},{5,6,7,8} };
	int result[4][4];

	cout << "\n��Ϊ��" << endl;
	add4x4(a, b, result);
	print(result);
	cout << "\n��Ϊ��" << endl;
	minus4x4(a, b, result);
	print(result);
	cout << "\n��Ϊ��" << endl;
	multiple4x4(a, b, result);
	print(result);



}

int main()
{
	std::cout << "test:\n";
	test();
}