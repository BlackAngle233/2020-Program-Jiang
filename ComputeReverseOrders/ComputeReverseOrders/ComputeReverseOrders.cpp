#include"pch.h"
#include <iostream>

using namespace std;

int n1 = 0;
int n2 = 0;
int num1[] = { 1, 3 , 4 , 7,  2 };//求逆序对
int num2[] = { 9, 8, 7, 6, 5 };// 求全部排列
int getrevseorders(int num2[], int len)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= len; j++) {
		for (i = 0; i <= len; i++) {
			if (num1[j] > num1[i] && i > j) {
				n1 += 1;
				cout << num1[j] << num1[i] << endl;
			}

		}
	}
	return n1;
}

int printpairs(int num2[], int len)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= len; j++)
	{
		for (i = 0; i <= len; i++)
		{
			if (i != j)
			{
				n2 += 1;
				cout << num2[j] << num2[i] << endl;
			}
		}
	}
	return n2;
}

int main()
{
	cout << "reverse orders :" << endl;
	getrevseorders(num1, 4);
	cout << "all pairs:" << endl;
	printpairs(num2, 4);
	cout << "reverse orders number:" << n1 << "     all pairs:" << n2 << endl;
}
