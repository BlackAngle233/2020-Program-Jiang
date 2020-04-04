#include<iostream>

using namespace std;

int getRevseOrders(int num[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			cout << "(" << num[i] << "," << num[j] << ") ";
			if (num[i] > num[j])
			{
				count++;
			}
		}
		cout << endl;
	}
	return count;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	cout << "逆序对数量：" << getRevseOrders(num1, 5) << endl;
	cout << "逆序对数量：" << getRevseOrders(num2, 5) << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
	system("pause");
	return 0;
}