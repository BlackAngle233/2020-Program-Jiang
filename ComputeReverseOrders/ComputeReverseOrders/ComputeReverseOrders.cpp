#include "pch.h"
#include <iostream>
using namespace std;

//void getRevseOrders(int num[], int len)
//{
//	int j = 1;
//	int flag = 0;
//	do
//	{
//		if (num[j]<num[j - 1])
//		{
//			j++;
//			flag++;
//		}
//		else
//			continue;
//	} while (j < len);
//	cout << flag;
//}

void printPairs(int num[], int len)
{
	int i = 1;
	int flag = 0;
	while (i<len)
	{
		cout << '(' << num[i - 1] << ',' << num[i] << ')';
		if (num[i] < num[i - 1])
			flag++;
		i++;
	}
	cout << endl << "Reverse Orders:"<< flag;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << endl;
	printPairs(num2, 5);
	cout << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main() {
	test();
	return 0;
}
