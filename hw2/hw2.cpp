// hw2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

template <class T>
void Show(T a[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}

template <class T>
void Metrix_Add(T a[4][4],T b[4][4]) {
	int c[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	Show(c);
}

template <class T>
void Metrix_Subtract(T a[4][4], T b[4][4]) {
	int c[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	Show(c);
}

template <class T>
void Metrix_Multiply(T a[4][4], T b[4][4]) {
	int c[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
		}
	}
	Show(c);
}




int main()
{
    std::cout << "Hello World!\n"; 
	int a[4][4], b[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = i > j ? i : j;
			b[i][j] = i > j ? j : i;
		}
	}
	cout << "矩阵a为：" << endl;
	Show(a);

	cout << "矩阵b为：" << endl;
	Show(b);

	cout << "a+b为：" << endl;
	Metrix_Add(a, b);

	cout << "a-b为：" << endl;
	Metrix_Subtract(a, b);

	cout << "a*b为：" << endl;
	Metrix_Multiply(a, b);
}

