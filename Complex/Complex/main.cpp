#include <iostream>
#include "Complex.h"

int main()
{
	Complex a;

	Complex b(2, 4);

	Complex c(b);

	Complex d = b + c;

	Complex e(3, -3);

	Complex f = { 1, 2 };
	cout << a << "\n" << b << "\n" << c << endl;
	cout << d << "\n" << e << "\n" << f << endl;

	a = b + e;
	c = b - e;
	d = b * e;

	cout << a << "\n" << c << "\n" << d << endl;
}

