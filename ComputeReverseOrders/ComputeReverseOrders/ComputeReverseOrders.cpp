#include <iostream>

using namespace std;

int getRevseOrders(int num[], int len)
{
	int i, j, ans = 0;
	for (j = 0; j < len; j++)
		for (i = j; i < len; i++)
		{
			if (num[j] > num[i])
				ans++;
		}
	return ans;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			cout << "(" << num[i] << "," << num[j] << ")" << endl;
		}
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	cout << "num1 pair:" << endl;
	printPairs(num1, 5);
	cout << "num1 reverse:";
	getRevseOrders(num1, 5);

	cout << "num2 pair:" << endl;
	printPairs(num2, 5);
	cout << "num1 reverse:";
	getRevseOrders(num2, 5);
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
