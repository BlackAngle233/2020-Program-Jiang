#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int count=0;
	for (int i = 0;i < len;i++)
	{
		for (int j = i + 1;j < len;j++)
		{
			if (num[i] > num[j])
			{
				count++;
			}
		}
	}
	return count;
}

void printPairs(int num[], int len)
{
	for (int i = 0;i < len;i++)
	{
		for (int j = i + 1;j < len;j++)
		{
			cout << '{' << num[i] << ',' << num[j] << '}' << ' ';
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
	cout << "The pairs of num1 is:";
	printPairs(num1, 5);
	cout << endl;
	cout << "The pairs of num2 is:";
	printPairs(num2, 5);
	cout << endl;
	cout << "The number of reverse pairs for num1 is " << getRevseOrders(num1, 5) << endl;
	cout << "The number of reverse pairs for num2 is " << getRevseOrders(num2, 5) << endl;
	return 0;
}
