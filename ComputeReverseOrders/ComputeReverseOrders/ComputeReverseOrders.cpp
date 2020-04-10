#include <iostream>
#include <cstring>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int n = 0;
	int i, j, f;
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (num[i] > num[j])n++;
		}
	}
	return n;
}

void printPairs(int num[], int len)
{
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			cout << '(' << num[i] << ',' << num[j] << ')' << endl;
		}
	}

}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 

	cout << "num1数组配对：" << endl;
	int numlen1 = sizeof(num1) / sizeof(num1[0]);
	//cout <<numlen1 << endl;
	int numlen2 = sizeof(num2) / sizeof(num2[0]);
	printPairs(num1, numlen1);
	cout << "num2数组配对：" << endl;
	printPairs(num2, numlen2);
	int s1 = getRevseOrders(num1, numlen1);
	int s2 = getRevseOrders(num2, numlen2);
	cout << "num1数组逆序列个数为：" << s1 << endl;
	cout << "num2数组逆序列个数为：" << s2 << endl;
}

int main()
{
	test();
}
