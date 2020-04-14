#include <iostream>
#include "Matrix.h"
using namespace std;

void test() 
{
	int a[4][4];
	int b[4][4];
	
	cout << "请输入第一个矩阵："<<endl;
	inputMartix4x4(a);
	cout << "请输入第二个矩阵：" << endl;
	inputMartix4x4(b);
	cout << "a：" << endl;
	printMartix4x4(a);
	cout << "b：" << endl;
	printMartix4x4(b);

	cout << "\n和为：" << endl;
	add4x4(a, b);
	cout << "\n差为：" << endl;
	minus4x4(a, b);
	cout << "\n积为："<<endl;
	multiple4x4(a, b);



}

int main()
{
    std::cout << "test:\n";
	test();
	int t = 0;
	std::cin >> t;
}