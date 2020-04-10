#include<iostream>
using namespace std;


int getRevseOrders(int num[], int len)
{
	int b = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (num[j] < num[i])b++;


		}
	}
	return b;
}
int GetLen(int num[])
{
	return sizeof(num) + 1;
}
void printPairs(int num[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			cout << "[" << num[i] << "," << num[j] << "]" << endl;
		}
	}
}
void test()
{
	int num1[] = { 1, 3, 4 ,7 ,2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, GetLen(num1));
	printPairs(num2, GetLen(num2));
	cout << getRevseOrders(num1, GetLen(num1)) << endl;;
	cout << getRevseOrders(num2, GetLen(num2)) << endl;

	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}
int main()
{
	test();
	system("PAUSE ");
}