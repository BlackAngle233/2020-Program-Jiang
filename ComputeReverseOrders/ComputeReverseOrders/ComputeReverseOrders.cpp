#include <iostream>

int getRevseOrders(int num[], int len)
{
	int result = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j]) {
				result++;
			}
		}
	}
	return result;
}

void printPairs(int num[], int len)
{
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			std::cout << num[i] << " " << num[j] << "|";
		}
	}
	std::cout << std::endl;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	printPairs(num1, 5);
	std::cout << std::endl;
	printPairs(num2, 5);
	std::cout << std::endl;

	std::cout << "序列1逆序数为" << getRevseOrders(num1, 5) << std::endl;
	std::cout << "序列2逆序数为" << getRevseOrders(num2, 5) << std::endl;
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
}

int main()
{
	test();
}
