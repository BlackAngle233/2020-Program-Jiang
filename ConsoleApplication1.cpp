// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int number = 0;
	for (int i = 0; i < len; i++) {
		for (int n = i - 1; n>=0 ; n--) {
			if (num[n] > num[i]) {
				number++;
			}
		}
	}
	return number;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++) {
		for (int n = 0; n != len; n++) {
			if (n != len) {
				cout<<"(" << num[i] <<","<< num[n]<<")" << endl;
			}
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
	int wait;
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	cout << getRevseOrders(num1, 5) << endl;
	printPairs(num1, 5);
	cin >> wait;
	return 0;
}

