#include "mat4.h"
#include <iostream>
using namespace std;

void Matrix4::print()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }
}

Matrix4 Matrix4::operator+(Matrix4 &rm)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] += rm.m[i][j];
        }
    }
    return *this;
}

Matrix4 Matrix4::operator-(Matrix4 &rm)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] -= rm.m[i][j];
        }
    }
    return *this;
}

Matrix4 Matrix4::operator*(Matrix4 &rm)
{
    int tm[4][4];
    Matrix4 nm;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp = 0;
            for(int k = 0; k < 4; k++)
            {
                temp += m[i][k] * rm.m[k][j];
            }
            tm[i][j] = temp;
        }
    }
    nm.set(tm);
    return nm;
}

void Matrix4::set(int m[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->m[i][j] = m[i][j];
        }
    }
}