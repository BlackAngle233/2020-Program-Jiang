#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
    int i;
    int j;
    int k=0;
    for (i = 0; i < len - 1; i++)
        for (j = i + 1; j < len; j++)
            if (num[i] > num[j])
            {
                k++;
            }
    cout << "该数组的逆序数为："<< k << endl;
    return 0;
}

void printPairs(int num[], int len)
{
    cout << "该数组的所有序列对为：" << endl;
    int i;
    int j;
    for (i = 0; i < len-1; i++)
        for (j = i + 1; j < len; j++)
            cout << "("<<num[i] << ","<< num[j]<<")"<<endl;
}

void test()
{
    int num1[] = { 1, 3 , 4 , 7,  2 };
    int num2[] = { 9, 8, 7, 6, 5 };
    cout << "数组1：";
    for (int i = 0; i < size(num1); i++)
        cout << num1[i] << " ";
    cout << endl;
    printPairs(num1, 5);
    getRevseOrders(num1, 5);

    cout << endl;

    cout << "数组2：";
    for (int i = 0; i < size(num2); i++)
        cout << num2[i] << " ";
    cout << endl;
    printPairs(num2, 5);
    getRevseOrders(num2, 5);
    // task  
    // 1. print out all pairs 
    // 2 . compute reverse orders 
}

int main()
{

    test();
    
}

