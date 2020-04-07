﻿#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len) {
	int count = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j]) {
				count++;
			}
		}
	}
	return count;
}


void printPairs(int num[],int len)
{
	cout << "该数组的所有序列对为: ";
	for (int i = 0; i < len-1; i++) {
		for (int j = i+1; j < len; j++) {
			cout << "(" << num[i] << "," <<num[j] <<")  ";
		}
	}
	cout << endl;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << "逆序数是：" << getRevseOrders(num1, 5) << endl;

	printPairs(num2, 5);
	cout << "逆序数是：" << getRevseOrders(num2, 5) << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
