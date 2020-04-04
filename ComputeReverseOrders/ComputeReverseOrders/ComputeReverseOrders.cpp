#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int count=0;//计数器
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
		{
			if (num[j] < num[i])
			{
				count++;
			}
		}
	return (count);
}

void printPairs(int num[], int len)
{

	for(int i=0;i<len-1;i++)
		for (int j = i+1; j < len ; j++)
		{
			cout << "(" << num[i] << "," << num[j] << ")";
		}
}

void test()
{
	int count;//计数器
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	cout << "num1:" << endl;
	printPairs(num1, 5);
	count = getRevseOrders(num1, 5);
	cout << endl<<"逆序数:"<<count<<endl;
	cout << "num2:" << endl;
	printPairs(num2, 5);
	count = getRevseOrders(num2, 5);
	cout << endl << "逆序数:" << count << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}
int main()
{
	test();
}