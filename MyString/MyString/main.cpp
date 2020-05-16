#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	MyString A("THIS IS WORLD");
	MyString C(A);
	MyString B("THIS IS HEAVEN");

	cout << A.empty() << ", " << A.length() << endl;
	A.print();
	cout << B.empty() << ", " << B.length() << endl;
	B.print();
	cout << C.empty() << ", " << C.length() << endl;
	C.print();
	
	C = B;
	B = A + B;

	cout << A.empty() << ", " << A.length() << endl;
	A.print();
	cout << B.empty() << ", " << B.length() << endl;
	B.print();
	cout << C.empty() << ", " << C.length() << endl;
	C.print();

	C = "";

	cout << C.empty() << ", " << C.length() << endl;
	C.print();
	return 0;
}
