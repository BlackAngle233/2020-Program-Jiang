#include <iostream>
#include "SingleList.h"
//#include "SingleList.cpp"

using namespace std;
int main()
{
	int a[] = { 1,2,3,4,5 };
	SingleList* MyList = new SingleList();
	*MyList = creat(a,5);
	cout << "创建链表1、2、3、4、5" << endl;
	print(*MyList);
	numbermove(2, *MyList);
	cout << "移除数字2" << endl;
	print(*MyList);
	cout << "在第二位插入9" << endl;
	insert(2, 9, *MyList);
	print(*MyList);
	cout << "移除第一位数字" << endl;
	positionmove(1, *MyList);
	print(*MyList);
}