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
}

int main()
{
	test();
}