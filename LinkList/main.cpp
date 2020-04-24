#include<iostream>
#include"LinkList.h"

int main() {
	ListHead linklist_1 = ListHead();
	int arry[] = { 1,2,3,4,3,5 };
	for (int i : arry) {
		LinkList item = LinkList(i);
		linklist_1.list_add(item);
	}

	std::cout << "插入后的链表：" << std::endl;
	LinkList* item=new LinkList(5);
	(*item).next = linklist_1.firstLink;
	while ((*item).next) {
		std::cout << (*(*item).next).data<<" ";
		(*item).next = (*(*item).next).next;
	}
	
	return 0;
}