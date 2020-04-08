#include <iostream>

int getRevseOrders(int num[], int len)
{
	int count = 0;
	for (int i = 0;i < len;i++) {
		for (int j = i + 1;j < len;j++) {
			if (num[i] > num[j]) {
				count++;
			}
		}
	}
	return count;
}

void printPairs(int num[], int len)
{
	for (int i = 0;i < len;i++) {
		for (int j = i + 1;j < len;j++) {
			if (num[i] > num[j]) {
				std::cout << "(" << num[i] << "," << num[j] << ")" << std::endl;
			}
		}
	}
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	std::cout << "num1逆序数个数为" << getRevseOrders(num1, 5) << "个" << std::endl;
	std::cout << "num1逆序对有: " << std::endl;
	printPairs(num1, 5);

	std::cout << "num2逆序数个数为" << getRevseOrders(num2, 5) << "个" << std::endl;
	std::cout << "num2逆序对有: " << std::endl;
	printPairs(num2, 5);

}

int main()
{
	test();
}
