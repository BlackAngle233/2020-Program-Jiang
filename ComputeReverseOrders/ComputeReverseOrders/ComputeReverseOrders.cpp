#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (num[i] > num[j])
			{
				result++;
			}
		}
	}
	return result;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (num[i]>num[j])
			{
				cout << num[i] << " " << num[j] << ", ";
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
	cout << "Pairs 1:" << endl;
	printPairs(num1,size(num1));
	// 2 . compute reverse orders
	cout << endl;
	cout << "ReveseOrders 1:\n" << getRevseOrders(num1, size(num1)) << endl;

	cout << endl;


	// 1. print out all pairs
	cout << "Pairs 2:" << endl;
	printPairs(num2, size(num2));
	// 2 . compute reverse orders
	cout << endl;
	cout << "ReveseOrders 2:\n" << getRevseOrders(num2, size(num2)) << endl;
}

int main()
{
	test();
}
