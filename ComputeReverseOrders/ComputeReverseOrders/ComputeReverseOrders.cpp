#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int n = 0;
	cout << "此数组的逆序数为：";
	for (int i = 0; i < len; i++)
	{
		for (int a = i; a < len; a++)
		{
			if (num[i] > num[a])
			{
				n++;
			}
		}
	}
	cout << n;
	cout << endl;
	return 0;
}

void printPairs(int num[], int len)
{
	cout << "此数组为：";
	for (int i = 0; i < len; i++)
	{
		cout << num[i];
		cout << " ";
	}
	cout << endl;
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
	getRevseOrders(num1, 5);
	printPairs(num2, 5);
	getRevseOrders(num2, 5);
}