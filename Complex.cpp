#include "pch.h"
#include <iostream>
#include"Complex.h"
using namespace std;

void test()
{
	Complex a(1, 5);
	cout <<"a:" <<a << endl;
	Complex b(2, 0);
	cout << "b:" <<b << endl;
	Complex c(3, -1);
	cout <<"c:" << c << endl;
	Complex d;
	d = a + b;
	cout <<"a、b之和为："<< d << endl;
	Complex e;
	e = d * c;
	cout << "d、c之积为：" << e << endl;
	e /= a;
	cout << "e除以a等于：" << e << endl;
	d++;
	cout << "d加上实数1为：" << d << endl;
}

int main()
{
	test();
	return 0;
}