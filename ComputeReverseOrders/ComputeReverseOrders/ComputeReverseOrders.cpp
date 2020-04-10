#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int i = 0,count = 0;
	while (i <= len - 1)
	{
		for (int j = i+1; j <= len - 1; j = j + 1)
		{
			if (num[i] > num[j])
			{
				count = count + 1;
			}
		}
		i = i + 1;
	}
	return count;
}

void printPairs(int num[], int len)
{
	int i = 0;
	while (i <= len - 1)
	{
		for (int j=i+1; j <= len - 1; j = j + 1)
		{
				cout << '(' << num[i] << ',' << num[j] << ')' << endl;
		}
		i = i + 1;
	}
}

void test()
{
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
    cout << "Hello World!\n";
	int num1[] = { 1, 3, 4 ,7, 2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout <<"逆序数为："<<getRevseOrders(num1, 5) << endl;
	printPairs(num2, 5);
	cout <<"逆序数为："<<getRevseOrders(num2, 5) << endl;
}
