#include <iostream>
#include "mat4.h"
using namespace std;

template <class T>

int getArrayLen(T& num)
{
	return (sizeof(num) / sizeof(num[0]));
}

int getRevseOrders(int num[], int len)
{
    int cout = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (num[i] > num[j])
            {
                cout++;
            }
        }
    }
    return cout;
}

void printPairs(int num[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (num[i] < num[j])
            {
                int temp[] = { num[i],num[j] };
                cout << "{" << temp[0] << "," << temp[1] << "} " << ends;
            }
        }
    }
    cout << " " << endl;
}


void test()
{
    int num1[2][2] = { 1, 3, 4, 7 };
    int num2[2][2] = { 9, 8, 7, 6 };
    int rows1 = getArrayLen(num1);
    int cols1 = getArrayLen(*num1);//获取矩阵1的行、列
    int rows2 = getArrayLen(num2);
    int cols2 = getArrayLen(*num2);//获取矩阵2的行、列
    //矩阵相加、相减
    if (rows1 == rows2 && cols1 == cols2)
    {
        cout << "矩阵相加的结果为：" << endl;
        matrixAdd((int**)num1, (int**)num2, rows1, cols2);
        cout << "矩阵相减的结果为：" << endl;
        matrixSub((int**)num1, (int**)num2, rows1, cols2);
    }
    //矩阵相乘
    if (rows1 == cols2)
    {
        cout << "矩阵相乘的结果为：" << endl;
        matrixMul((int**)num1, (int**)num2, rows1, cols2, rows2);
    }
}

int main()
{
    test();

    return 0;

}
