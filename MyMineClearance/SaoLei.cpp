// SaoLei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"SaoLei1.h"
#include"SaoLei2.h"
#include"SaoLei3.h"
using namespace std;

int main()
{
    cout << "************欢迎来到数字扫雷*************" << endl;
    cout <<endl;
    cout <<endl;
    cout << "************请选择难度：*************" << endl;
    cout << "************1：难度1*************" << endl;
    cout << "************2：难度2*************" << endl;
    cout << "************3：难度3*************" << endl;
    int i;
    cin >> i;
    switch(i)
    {   
        case 1:
        {
            SaoLei1 s;
            s.Start();
            s.Play();
            cout << endl;
            s.~SaoLei1();
            break;
        }
        case 2:
        {
            SaoLei2 s2;
            s2.Start();
            s2.Play();
            cout << endl;
            s2.~SaoLei2();
            break;
        }
        case 3:
            SaoLei3 s3;
            s3.Start();
            s3.Play();
            cout << endl;
            s3.~SaoLei3();
            break;
    }
    
    
}

