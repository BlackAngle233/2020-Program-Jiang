#include"Complex.h"
using namespace std;
#include<iostream>
int main()
{
	Complex c1(2,2);
	Complex c2(-2,3);
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	Complex c3 = c1 + 1;
	cout <<"c1 + 1=" <<c3<<endl;

	c3 = c1 + c2;
	cout << "c1+c2=" << c3 << endl;

	c3-= c1;
	cout << "c3 -= c1 , c3 = " << ++c3 << endl;

	c3 += c1;
	cout << "c3 += c1 , c3 = " << ++c3 << endl;

	c3 = -c1 + c2;
	cout << "c2-c1=" << c3 << endl;


	c3 = c1 * c2;
	cout << "c1 * c2=" << c3 << endl;

	c3 /= c1;
	cout << "c3 /= c1, c3 = " << c3 << endl;

	c3 *= c1;
	cout << "c3 *= c1, c3 = " << c3 << endl;

	c3 = c1 / c2;
	cout << "c1 / c2 = " << c3 << endl;
	

	c3 = Complex(1, 1);
	cout <<"++c3="<< ++c3<<endl;
	cout << "after ++c3 , c3 ="<<c3<<endl;
	cout << "c3-- = "<<c3--<<endl;
	cout << "after c3--, c3 = "<<c3<<endl;
	if (c3 == Complex(1, 1))
		cout << "c3 == 1+1i" << endl;

	c3 -= c3;
	cout << "c3-=c3, c3 = " << c3 << endl;
	return 0;
}