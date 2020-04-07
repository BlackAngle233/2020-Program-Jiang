#include <iostream>
#include <numeric>

using namespace std;

bool revse(int x, int y)
{
	if (x < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getRevseOrders(int num[], int len)
{
	int revsenum = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (revse(num[i], num[j]))
			{
				revsenum++;
			}
		}
	}
	return revsenum;
}

void printPairs(int num[], int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			cout << num[i] << "," << num[j] << endl;
		}
	}
}

int main()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	int len1 = sizeof(num1) / sizeof(num1[0]);

	printPairs(num1, len1);
	cout << "Revse:" << getRevseOrders(num1, len1) << endl;

}