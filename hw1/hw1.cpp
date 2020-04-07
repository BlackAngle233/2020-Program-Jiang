// hw1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

void printReverseOrders(int nums[], int len) {
	int num = 0;
	int i, j;
	cout << "所有序列对为：" << "\t";
	for (i = 0; i < 5; ++i)
	{
		for (j = i + 1; j < 6; ++j)
		{
			cout << "(" << nums[i] << "," << nums[j] << ")" << "\t";
			if (nums[i] > nums[j])
			{
				num++;
			}
		}
	}
	cout << endl;
	cout << "逆序数总数为：" << num << endl;
}

int main()
{
	int nums[]{ 1,4,5,7,9,2 };
	int len = sizeof(nums) / sizeof(nums[0]);

	cout << "数组为:[";
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ",";
	}
	cout << "]" << endl;
	printReverseOrders(nums, len);
	system("pause");
}
