#include <iostream>
#include "SingleList.h"
//#include "SingleList.cpp"

using namespace std;
int main()
{
	int a[] = { 1,2,3,4,5 };
	SingleList* MyList = new SingleList();
	*MyList = creat(a,5);
	cout << "��������1��2��3��4��5" << endl;
	print(*MyList);
	numbermove(2, *MyList);
	cout << "�Ƴ�����2" << endl;
	print(*MyList);
	cout << "�ڵڶ�λ����9" << endl;
	insert(2, 9, *MyList);
	print(*MyList);
	cout << "�Ƴ���һλ����" << endl;
	positionmove(1, *MyList);
	print(*MyList);
}