#include <iostream>

int getRevseOrders(int num[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i < j && num[i] > num[j])
			{
				count++;
			}
		}
	}
	return count;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i != j)
			{
				cout << "(" << num[i] << "," << num[j] << ")" << " ";
			}
		}
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << endl << "num1逆序数是：" << getRevseOrders(num1, 5) << endl;
	printPairs(num2, 5);
	cout << endl << "num2逆序数是：" << getRevseOrders(num2, 5) << endl;
}

int main()
{
	/*int a[65536];
	int len;
	int count = 0;
	cout << "请输入数字的总数:";
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i < j && a[i] > a[j])
			{
				count++;
			}
			if (i != j)
			{
				cout << "(" << a[i] << "," << a[j] << ")" << " ";
			}
		}
	}
	cout << endl << "逆序数是：" << count << endl;*/
	test();
	return 0;
}
