#include"Matrix.h"
#include <iostream>

void test()
{
	Mat4 m1;
	m1.Input();
	Mat4 m2;
	m2.Input();

	cout << "m1 + m2:" << endl;
	Mat4 m3 = m1 + m2;
	m3.Print();
	cout << "m1 - m2:" << endl;
	m3 = m1 - m2;
	m3.Print();
	cout << "m1 * m2:" << endl;
	m3 = m1 * m2;
	m3.Print();
}

int main()
{
	test();
	return 0;
}