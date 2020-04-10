// ComputeReverseOrders.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;
int getRevseOrders(int num[], int len)
{
	int r = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j])
				r++;
		}
	}
	return r;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			cout << "<" << num[i] << "," << num[j] << ">" << endl;
		}
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << getRevseOrders(num2, 5) << endl;
	return 0;
}
