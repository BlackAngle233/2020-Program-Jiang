#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
    for(int i=len-1;i>=0;--i){
        cout<<num[i];
    }
    return 0;
}

void printPairs(int num[], int len)
{
    for(int i=0;i<len;++i)
        for(int j=0;j<len;++j)
            {
                if(j==i) continue;
                else cout<<"{ "<<num[i]<<", "<<num[j]<<" }"<<'\t';
            }
    cout<<endl;
}

void test()
{
	int num1[5] = { 1, 3 , 4 , 7,  2 };
	int num2[5] = { 9, 8, 7, 6, 5 };
    cout<<"This is the first group of numbers: \n";
    getRevseOrders(num1,5);
    printPairs(num1,5);
    cout<<"This is the second group of numbers: \n";
    getRevseOrders(num2,5);
    printPairs(num2,5);
}

int main()
{
    test();
}