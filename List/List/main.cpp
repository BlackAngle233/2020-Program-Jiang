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
	SingleList *listc =new SingleList(nums, len);
	listc->print();
	cout << "���������в�������10��" << endl;
	listc->insert(10);
	listc->print();
	cout << "Ѱ�ҵ�������������Ϊ3�Ľڵ㣬������ɾ����" << endl;
	SingleList::Node* x = listc->find(3);
	listc->remove(x);
	listc->print();
	cout << "ɾ��������������������Ϊ10�Ľڵ㣺" << endl;
	listc->remove(10);
	listc->print();
	cout << "ɾ����������" << endl;
	listc->erase();

}