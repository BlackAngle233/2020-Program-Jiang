#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int RevseOrders{ 0 };
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (num[i] > num[j])
				RevseOrders++;
		}
	}
	return RevseOrders;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j<len; j++)
		{
			cout << "(" << num[i] << "," << num[j] << ") ";
		}
	}
	cout << "\n";
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };


	printPairs(num1,5);
	cout<<"reverse orders:"<<getRevseOrders(num1, 5)<<"\n";
	printPairs(num2, 5);
	cout<<"reverse orders:"<<getRevseOrders(num2, 5)<<"\n";
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
