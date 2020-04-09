#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int h=0;  //将h作为计数器，最后return回测试函数
	int i = 0, j = 0;
	for (i; i < len; i++)
	{
		j = 0;
		for (j; j < len; j++)
		{
			if ((i < j) && (num[i] > num[j]))
			{
				h++;
			}
		}
	}
	return h;
}

void printPairs(int num[], int len)
{
	int i = 0, j = 0;
	for (i; i < len; i++)
	{
		j = 0;
		for (j; j < len; j++)
		{
			if (i != j)
			{
				cout << "(" << num[i] << "," << num[j] << ")  ";
			}			
		}
		cout << endl;
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	cout << "数组1：" << endl;
	printPairs(num1, 5);
	cout<<"number of reverse orders:"<<getRevseOrders(num1, 5)<<endl;
	cout << endl;
	cout << "数组2：" << endl;
	printPairs(num2, 5);
	cout << "number of reverse orders:" << getRevseOrders(num2, 5) << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
