#include <iostream>
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
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };

    cout << "数组1的对有： " << ends;
    printPairs(num1, getArrayLen(num1));
    cout << "数组2的对有： " << ends;
    printPairs(num2, getArrayLen(num2));
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
    cout << "数组1的逆序数为： " << getRevseOrders(num1, getArrayLen(num1)) << endl;
    cout << "数组2的逆序数为： " << getRevseOrders(num2, getArrayLen(num2)) << endl;
}

int main()
{
    test();
}
