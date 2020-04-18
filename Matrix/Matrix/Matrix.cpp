
#include <iostream>
#include "Matrix.h"

Mat4::Mat4()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			this->mat[i][j] = 0;
	}
}

void Mat4::Input()
{
	cout << "please input the 4 by 4 matrix:" << endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cin >> mat[i][j];
	}
}

Mat4 Mat4::operator+(const Mat4& m)
{
	Mat4 temp;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			temp.mat[i][j] = this->mat[i][j] + m.mat[i][j];
	}
	return temp;
}


Mat4 Mat4::operator-(const Mat4& m)
{
	Mat4 temp;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			temp.mat[i][j] = this->mat[i][j] - m.mat[i][j];
	}
	return temp;
}

Mat4 Mat4::operator*(const Mat4& m)
{
	Mat4 temp;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				temp.mat[i][j] += this->mat[i][k] * m.mat[k][j];
	}
	return temp;
}

void Mat4::Print()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;

}
