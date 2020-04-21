// hw2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "mat4.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	Mat4 a = { 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4 };
	Mat4 b = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4 };


	cout << "Matrix a:" << endl;
	ShowMat4(a);
	cout << "Matrix b:" << endl;
	ShowMat4(b);

	Mat4 c = AddMat4(a, b);
	cout << "Matrix a+b:" << endl;
	ShowMat4(c);

	Mat4 d = SubMat4(a, b);
	cout << "Matrix a-b:" << endl;
	ShowMat4(d);

	Mat4 e = MulMat4(a, b);
	cout << "Matrix a*b:" << endl;
	ShowMat4(e);
}
