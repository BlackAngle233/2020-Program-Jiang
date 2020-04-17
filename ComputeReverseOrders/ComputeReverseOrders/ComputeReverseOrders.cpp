#include <iostream>
#include"Mat4.h"
using namespace std;

int getRevseOrders(int num[], int len)
{
	cout << "数组的反转是：";
	int* tem = new int[len];
	for (int i = 0; i < len; i++) {
		tem[i] = num[len - i - 1];
	}									//reverse

	for (int j = 0; j < len; j++) {
		cout << tem[j] << ' ';
	}
	cout << endl;
	return 0;
}

void printPairs(int num[], int len)
{
	cout << "所有的排列是：";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << num[i] << num[j] << ' ';
		}
	}
	cout << endl;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	getRevseOrders(num1, 5);
	printPairs(num2, 5);
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	matrix a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a.set(i, j, i);
			b.set(i, j, j);
		}
	}
	a.print();
	b.print();

	matrix sum, dif, pro;
	sum = a + b;
	dif = a - b;
	pro = a * b;

	sum.print();
	dif.print();
	pro.print();
	return 0;
}
