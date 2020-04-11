#include <iostream>
#include "mat4.h"

using namespace std;

int getValue()
{
    static int i = 0;
    return ++i;
}

bool isPalindrome(const char *p)
{
    int i = 0;
    const char *temp = p;
    while (*temp != 0)
    {
        temp++;
        i++;
    }
    for (int j = 0; j < i / 2; j++)
    {
        if (p[j] == p[i - j - 1])
        {
            continue;
        }
        else
            return false;
    }
    return true;
}

void print4M(int m[4][4])
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

int main()
{
    Matrix4 m1, m2, m3;
    int p1[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    int p2[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    m1.set(p1);
    m2.set(p2);
    m3 = m1*m2;
    m3.print();
    getchar();
    return 0;
}