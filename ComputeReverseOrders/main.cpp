#include <iostream>

using namespace std;

int getRevseOrders(int num[], int len)
{
    int count = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            cout << "(" << num[i] << "," << num[j] << ") ";
            if (num[i] > num[j])
                count++;
        }
        cout << endl;
    }
    return count;
}

void test()
{
    int num1[] = {1, 3, 4, 7, 2};
    int num2[] = {9, 8, 7, 6, 5};

    int res1 = getRevseOrders(num1, 5);
    int res2 = getRevseOrders(num2, 5);

    cout << "res1 = :" << res1 << endl;
    cout << "res2 = :" << res2;
    // task
    // 1. print out all pairs
    // 2 . compute reverse orders
}

int main()
{
    test();
    getchar();
    return 0;
}