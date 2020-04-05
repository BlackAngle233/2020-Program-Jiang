#include <iostream>

using namespace std;

int getRevseOrders(int num1[], int len)
{
	int i = 0;
	int j = 0;
	int len = 5;
	for (j = 1; j <= len; j++) {
		for (i = 1; i <= len; i++) {
			if (num1[j] < num1[i]) {
				n1 += 1；
					cout << num1[j]num1[i] << endl;
			}
				
		}
	}
	return n1;
}

void printPairs(int num[], int len)
{

}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	int n1 = 0;
	int n2 = 0;
	getRevseOrders(int num[], int len)
    printPairs(int num[], int len)
	cout << "reverse orders:"<<n1<<"     all pairs:" <<n2<< endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	cout << "Hello World!" << endl;
}
