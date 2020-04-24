#include <iostream>
#include "SingleList.h"
using namespace std;
template <class T>

int getArrayLen(T& num)
{
	return (sizeof(num) / sizeof(num[0]));
}

int main()
{
	int nums[] = { 1, 3, 2, 4, 6, 10};
	int len = getArrayLen(nums);
	cout << "������������" << endl;
	SingleList sglist = Create(nums, len);
	print(sglist.head);
	cout << "���������в�������10��" << endl;
	insert(sglist, 10);
	print(sglist.head);
	cout << "Ѱ�ҵ�������������Ϊ3�Ľڵ㣬������ɾ����" << endl;
	Node* x = find(sglist, 3);
	remove(sglist, x);
	print(sglist.head);
	cout << "ɾ��������������������Ϊ10�Ľڵ㣺" << endl;
	remove(sglist, 10);
	print(sglist.head);
	cout << "ɾ����������" << endl;
	erase(sglist);
	print(sglist.head);

	return 0;
}