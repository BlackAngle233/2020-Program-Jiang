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
	cout <<"a��b֮��Ϊ��"<< d << endl;
	Complex e;
	e = d * c;
	cout << "d��c֮��Ϊ��" << e << endl;
	e /= a;
	cout << "e����a���ڣ�" << e << endl;
	d++;
	cout << "d����ʵ��1Ϊ��" << d << endl;
}

int main()
{
	test();
	return 0;
}