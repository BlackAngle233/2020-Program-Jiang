#include <iostream>

int getRevseOrders(int num[], int len)
{

}

-﻿#include <iostream>

int getRevseOrders(int num[], int len)
{

}

void printPairs(int num[], int len)
{

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
	std::cout << "Hello World!\n";
}
#include <cstdio>


using namespace std;

int getReverseOrders(int a[], int len)
{
	int ans = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] > a[j]) ans++;
			printf("%d %d\n", a[i], a[j]);
		}
	}

	return ans;
}


int main()
{
	int a[4]{ 4,3,2,1 };
	printf("%s %d", "The number of ReverseOrder numbers of given array is:", getReverseOrders(a, 4));
	return 0;
}