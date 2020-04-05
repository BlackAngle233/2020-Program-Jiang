#include <iostream>
using namespace std;
int getReverseOrders(int num[], int len)
{
	int i, j, k = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (num[j] < num[i])
			{
				k++;
			}
		}
	}
	return k;
}

void printPairs(int num[], int len)
{
	int i, j;
	cout << "All pairs:" << endl;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			cout << "(" << num[i] << "," << num[j] << ") ";
		}
		cout << endl;
	}
}
void test()
{
	int num1[] = { 1,3,4,7,2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	cout << "The Number of ReverseOrder is:" << getReverseOrders(num1, 5) << endl;
	printPairs(num1, 5);
	cout << "The Number of ReverseOrder is:" << getReverseOrders(num2, 5) << endl;
	printPairs(num2, 5);

	// task:
	//1.print out all pairs
	//2.compute reverse orders
}
int main()
{
	test();
}