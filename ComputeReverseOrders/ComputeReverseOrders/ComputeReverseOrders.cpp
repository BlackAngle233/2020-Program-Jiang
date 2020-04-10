#include <iostream>


int getRevseOrders(int num[])
{
	int count = 0;
	int length = sizeof(num);
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (num[i] > num[j]) {
				count++;
			}
		}
	}
	return count;
}

void printPairs(int num[])
{
	int len = sizeof(num);
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			std::cout << num[i], num[j];
			std::cout << "\n";
		}
	}
}

void test()
{
	
	int num2[] = { 9, 8, 7, 6, 5 };

	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	int num1[] = {1,3,4,7,2};
	printPairs(num1);
    std::cout << "Hello World!\n";
	std::cout << getRevseOrders(num1);
}
