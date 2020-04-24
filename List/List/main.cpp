#include <iostream>
#include "SingleList.h"

int main()
{
	SingleList* list = SingleList_create(5, 324, 687, 498, 123, 457);
	SingleList_print(list);
	int targetIndex1 = SingleList_find_FirstIndexOf(list, 687);
	SingleList_insert_InsertAfter(list, targetIndex1, 666);
	SingleList_remove_RemoveValue(list, 123);
	SingleList_print(list);
	SingleList_erase(list);
	delete(list);
	list = NULL;
	int a[] = { 5,4,7,88,9,1,2 };
	list = SingleList_create(a, sizeof(a) / sizeof(int));
	SingleList_print(list);
	auto node = SingleList_find_FirstNodeOf(list, 88);
	SingleList_insert_InsertAfter(node, 44);
	SingleList_remove_RemoveNode(list, node);
	SingleList_print(list);
	SingleList_erase(list);
	delete(list);
}