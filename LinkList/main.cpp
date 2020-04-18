#include <iostream>
#include "LinkList.h"
void test()
{
	int nums[5]{ 1,2,2,2,2 };
	LinkList* list = create(nums, 5);
	print(list);
	insert(list, 2);
	print(list);
	remove(list, 2);
	print(list);
	LinkList::Node* node = new LinkList::Node();
	node->vlaue = 3;
	insert(list, node);
	print(list);
	erase(list);
}

int main()
{
	test();
}