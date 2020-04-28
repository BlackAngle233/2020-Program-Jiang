#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
	int i;
	int j;
	int a;
	int n = 0;
	int b;
	for (i = 0; i < 5; i++)
	{
		a = num[i];
		for (j = i + 1; j < 5; j++)
		{
			b = num[j];
			if (b < a)
			{
				n++;
			}
		}
	}
	return n;
}

void printPairs(int num[], int len)
{
	int a;
	int b;
	int i;
	int j;
	for (i = 0; i < 5; i++)
	{
		a = num[i];
		for (j = i + 1; j < 5; j++)
		{
			b = num[j];
			cout << "{" << a << "," << b << "}" << endl;;
		}
	}
}
//void test()
//{
//	int num1[] = { 1, 3 , 4 , 7,  2 };
//	int num2[] = { 9, 8, 7, 6, 5 };
//
//	// task  
//	// 1. print out all pairs 先打印出来所有序列
//	// 2 . compute reverse orders 输出逆序数的数量
//}

int main()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	printPairs(num1, 2);
	cout << getRevseOrders(num2, 5);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


