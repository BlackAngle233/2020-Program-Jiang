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
	SingleList sglist = Create(nums, len);
	print(sglist.head);
	cout << "向单向链表中插入数字10：" << endl;
	insert(sglist, 10);
	print(sglist.head);
	cout << "寻找单向链表中数字为3的节点，并将其删除：" << endl;
	Node* x = find(sglist, 3);
	remove(sglist, x);
	print(sglist.head);
	cout << "删除单向链表中所有数字为10的节点：" << endl;
	remove(sglist, 10);
	print(sglist.head);
	cout << "删除单向链表：" << endl;
	erase(sglist);
	print(sglist.head);

	return 0;
}