﻿// homework1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>

using namespace std;


int len = 5;
int num1[] = { 1, 3 , 4 , 7,  2 };
int num2[] = { 9, 8, 7, 6, 5 };

void getRevseOrders(int num[], int len)
{
	int p = 0;

	for (int i = len - 1; i > -1; i--)
	{
		len--;
		for (int j = len - 1; j > -1; j--)
		{
			if (num[len] < num[j])
				p++;
		}
	}
	cout << p << endl;
}

void printPairs(int num[], int len)
{
	/*for (int i = 0; i < len-1; i++)
	{
		cout << num[i]<<num[i+1];
	}
	cout << endl;*/
	for (int i = len - 1; i > -1; i--)
	{
		len--;
		for (int j = len - 1; j > -1; j--)
		{
			cout << num[len] << num[j] << endl;
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
	printPairs(num1, len);
	printPairs(num2, len);
	getRevseOrders(num1, len);
	getRevseOrders(num2, len);
}