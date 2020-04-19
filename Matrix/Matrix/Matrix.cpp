#include <iostream>
#include "Matrix.h"
using namespace std;

void Matrix::printMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::inputMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> m[i][j];
		}
	}
}

void Matrix::add(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void Matrix::substract(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
}

void Matrix::multiple(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m1[i][k] * m2[k][j]; 
			}
			result[i][j] = sum;
		}
	}
}

void test()
{
	int a[4][4], b[4][4],answer[4][4];
	Matrix test;
	cout << "Input array1:" << endl;
	test.inputMartix4x4(a);
	cout << "Input array2:" << endl;
	test.inputMartix4x4(b);
	cout << "print array1:" << endl;
	test.printMartix4x4(a);
	cout << "print array2:" << endl;
	test.printMartix4x4(b);

	cout << "a+b=" << endl;
	test.add(a, b, answer);
	test.printMartix4x4(answer);

	cout << "a-b=" << endl;
	test.substract(a, b, answer);
	test.printMartix4x4(answer);

	cout << "a*b=" << endl;
	test.multiple(a, b, answer);
	test.printMartix4x4(answer);
}

int main()
{
	cout << "test:\n";
	test();
}