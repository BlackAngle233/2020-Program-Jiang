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
	cout << "创建单向链表：" << endl;
	SingleList *listc =new SingleList(nums, len);
	listc->print();
	cout << "向单向链表中插入数字10：" << endl;
	listc->insert(10);
	listc->print();
	cout << "寻找单向链表中数字为3的节点，并将其删除：" << endl;
	SingleList::Node* x = listc->find(3);
	listc->remove(x);
	listc->print();
	cout << "删除单向链表中所有数字为10的节点：" << endl;
	listc->remove(10);
	listc->print();
	cout << "删除单向链表" << endl;
	listc->erase();

}