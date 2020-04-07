#include <iostream>

int getRevseOrders(int num[], int len)
{
	int res{ 0 };
	if (len < 2) {
		return 0;
	}

	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j]) {
				res++;
			}
		}
	}
	return res;
}

void printPairs(int num[], int len)
{
	if (len < 2) {
		return;
	}
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (num[i] > num[j]) {
				std::cout << num[i] << "    " << num[j] << std::endl;
			}
		}
	}
	//std::cout << "------------------------" << std::endl;
}

void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
	int r1 = getRevseOrders(num1, 5);
	std::cout << r1 << std::endl;
	printPairs(num1, 5);



	int r2 = getRevseOrders(num2, 5);
	std::cout << r2 << std::endl;
	printPairs(num2, 5);
}

int main()
{
	test();
	system("pause");
}
