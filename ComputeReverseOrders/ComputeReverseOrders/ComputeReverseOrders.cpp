#include <iostream>

using namespace std;

const int MAX = 999;
int getRevseOrders(int num[], int len)
{
	int i = 0, j = 0;
	int k = 0, sum = 0;
	int a[MAX]{0};

	cout << "All pairs: ";
	for (i = 0; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			a[k] = num[i];
			a[k + 1] = num[j];

			k += 2;
			if (num[i] > num[j]) {
				sum++;
			}
		}
	}

	int m = 0;
	while (a[m] != 0) {
		cout << "(" << a[m] << "," << a[m + 1] << ")";
		m += 2;
	}

	cout << endl;
	return sum;
}

void test()
{
	int num1[] = { 1, 3 ,4 ,7, 2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	int p;
	int q;

	p = getRevseOrders(num1, 5);
	cout << "The number of reverse orders:" << p;
	cout << endl;

	q = getRevseOrders(num2, 5);
	cout << "The number of reverse orders:" << q;
	cout << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}