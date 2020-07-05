#include <iostream>
#include "Matrix.h"

void test()
{
	int row = 0, col = 0, row2 = 0, col2 = 0;
	int tmp = 0;
	vector<double> values;
	vector<double> values2;
	cout << "print row and col:";
	cin >> row >> col;
	for (int i = 0; i < row * col; ++i)
	{
		cin >> tmp;
		values.push_back(tmp);
	}

	cout << "print row and col:";
	cin >> row2 >> col2;
	cout << "print values:";
	for (int i = 0; i < row2 * col2; ++i)
	{
		cin >> tmp;
		values2.push_back(tmp);
	}
	try
	{
		Matrix m1(row, col, values);
		Matrix m2(row, col, values);
		Matrix m3 = m1 + m2;
		m3.print();
		m3 = m1 - m2;
		m3.print();
		m3 = m1 * m2;
		m3.print();
	}
	catch (const char* e)
	{
		cerr << e << endl;
	}


	/*while (1)
	{
		cout << "print values:";
		for (int i = 0; i < row * col; ++i)
		{
			cin >> tmp;
			values.push_back(tmp);
		}
		try
		{
			Matrix m1(row, col, values);
			Matrix m2(row, col, values);
			cout << m1.det() << endl;
			m2 = m2 * m1.inverse();
			m2.print();
		}
		catch (const char* e)
		{
			cerr << e << endl;
		}
		values.clear();
	}*/
	int test;
	cin >> test;
	return;
}

int main()
{
	std::cout << "test:\n";
	test();
}