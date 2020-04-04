#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len) {
	int revseOrders = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j]) {
				revseOrders++;
			}
		}
	}
	return revseOrders;
}


void printPairs(int num[],int len)
{
	
	for (int i = 0; i < len-1; i++) {
		for (int j = i+1; j < len; j++) {
			cout << "(" << num[i] << "," <<num[j] <<")  ";
		}
	}
	cout << endl;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 5);
	cout << getRevseOrders(num1, 5) << endl;

	printPairs(num2, 5);
	cout << getRevseOrders(num2, 5) << endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
