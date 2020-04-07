#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int count = 0;
	for (int a = 0; a < len - 1; a++)
	{
		for (int b = a; b < len; b++)
		{
			if (num[a] > num[b])
				count++;
		}
	}
	return count;
}

void printPairs(int num[], int len)
{
	for (int a = 0; a < len - 1; a++) 
	{
		for (int b = a; b < len; b++) 
		{
			cout << num[a] << "," << num[b] << endl;
		}
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << "the num of reversepairs : " << getRevseOrders(num1, 5) << endl;
	printPairs(num2, 5);
	cout << "the num of reversepairs : " << getRevseOrders(num2, 5) << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
