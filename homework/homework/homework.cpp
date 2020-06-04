// homework.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"Employee.h"
using namespace std;
int main()
{
	Manager *a1 = new Manager("0");
	Manager*a2 = new Manager("1");
	Manager*a3 = new Manager("2");
	Manager*a4 = new Manager("3");
	Manager*a5 = new Manager("4");
	Manager*a6 = new Manager("5");
	a1->addemployee(a2);
	a2->addemployee(a3);
	a2->addemployee(a4);
	a4->addemployee(a5);
	a5->addemployee(a6);
	cout<<findlastManager(a1, "4", "5")->name_;
	/*a1->printreportline();*/
	//a1->printreportline();
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
