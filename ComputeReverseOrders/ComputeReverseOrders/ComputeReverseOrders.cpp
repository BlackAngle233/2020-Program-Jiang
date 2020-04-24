#include <iostream>
#include"Mat4.h"
#include"linklist.h"
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
	int a[] = { 1,2,3,4,5,4 };
	LinkList* list = create(a, 6);
	print(list);


	return 0;
}
