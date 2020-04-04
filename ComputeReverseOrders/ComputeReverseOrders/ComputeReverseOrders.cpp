#include<iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int number = 0;
	for (int i = 0; i < len; i++)
	{
		int j = i + 1;
		for (; j < len; j++)
		{
			if (num[i] > num[j])
			{
				number++;
				cout << num[i] << " " << num[j] << endl;
			}
		}
	}
	cout << "count of reverse:" << endl << number << endl;
	return number;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int j = i + 1;
		for (; j < len; j++)
		{
			cout << num[i] << " " << num[j] << endl;
		}
	}
}

void test()
{
	int num1[] = { 1, 3, 4, 7 ,2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	cout << "num1:" << endl;
	cout << "pairs:" << endl;
	printPairs(num1, 5);
	cout << "reverse pairs:" << endl;
	getRevseOrders(num1, 5);

	cout << endl;

	cout << "num2:" << endl;
	cout << "pairs:" << endl;
	printPairs(num2, 5);
	cout << "reverse pairs:" << endl;
	getRevseOrders(num2, 5);
}

int main()
{
	test();
}