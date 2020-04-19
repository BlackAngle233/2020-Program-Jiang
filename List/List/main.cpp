#include <iostream>
#include "SingleList.h"

int main()
{
	int numList[] = { 1,2,3,4,5,4 };
	SingleList* list = create(numList,6);
	print(list);

	//在最后插入一个值为3的结点
	insert(list, 3);
	print(list);

	// 找到第一个值为4的结点并且删除它
	remove(list, find(list, 4)) ;
	print(list);

	// 删除所有值为3的结点
	remove(list, 3);
	print(list);

	// 删除单链表
	erase(list);
}