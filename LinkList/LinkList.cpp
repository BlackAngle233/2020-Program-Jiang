#include<iostream>
#include"LinkList.h"

LinkList::LinkList(int data1) {
	data = data1;
	next = nullptr;
}

void LinkList::release() {
	delete(next);
}
ListHead::ListHead() {
	firstLink = nullptr;
	lastLink = firstLink;
}
void ListHead::list_add(LinkList newLink) {
	if (firstLink==nullptr) {
		firstLink = new LinkList(newLink.data);
		lastLink = firstLink;
		//std::cout << (*lastLink).data << std::endl;
	}
	else {
		(*lastLink).next = new LinkList(newLink.data);
		lastLink = (*lastLink).next;
		//std::cout << (*(*lastLink).next).data << std::endl;
	}
}
void ListHead::list_delete(int data) {
	if (firstLink == lastLink) {
		return;
	}
	LinkList& item = (*firstLink);
	if (item.data == data) {
		firstLink = item.next;
		item.release();
	}
	else {
		while (item.next) {
			//std::cout << item.data << "a" << std::endl;
			if ((*item.next).data == data) {
				LinkList& temp = (*item.next);
				item.next = (*item.next).next;
				//std::cout << (*item.next).data << "b" << std::endl;
				//temp.release();
				return;
			}
			item = (*item.next);
		}
	}
}