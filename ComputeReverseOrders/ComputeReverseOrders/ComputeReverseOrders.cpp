#include <iostream>
using namespace std;
int getRevseOrders(int num[], int len)
{
    int a = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i<j && num[i]>num[j])
            {
                a++;
            }
        }
    }
    return a;
}

void printPairs(int num[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i != j)
                cout << "(" << num[i] << "," << num[j] << ")" << "";
        }
    }
}

void test()
{
    int num1[] = { 1, 3 , 4 , 7,  2 };
    int num2[] = { 9, 8, 7, 6, 5 };
    printPairs(num1, 5);
    cout << endl << "num1的逆序数为：" << getRevseOrders(num1, 5) << endl;
    printPairs(num2, 5);
    cout << endl << "num2的逆序数为：" << getRevseOrders(num2, 5) << endl;
    // task  
    // 1. print out all pairs 
    // 2 . compute reverse orders 
}

int main()
{
    std::cout << "Hello World!\n";
    test();
}
