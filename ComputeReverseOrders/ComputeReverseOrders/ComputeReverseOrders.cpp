#include <iostream>
using namespace std;

int getRevseOrders(int num[], int len)
{
	int sum{0};
	for(int i = 0;i<len;i++)
	{
		for(int j =i+1;j<len;j++)
		{
			cout<<'('<<num[i]<<','<<num[j]<<')'<<' ';
			if(num[i]>num[j])sum++;
		}
	}
	cout<<endl;
		return sum;
}


void test()
{
	int num1[] = { 1, 3 , 4 , 7,  2 };
	int num2[] = { 9, 8, 7, 6, 5 };
	// task  
	// 1. print out all pairs 
	// 2 . compute reverse orders 
	cout<<getRevseOrders(num1,5)<<'\n'<<getRevseOrders(num2,5)<<endl;
}

int main()
{
    test();
	return 0;
}
