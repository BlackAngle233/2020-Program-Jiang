#include<iostream>
#include"LinkList.h"

LinkList::Node* createNode(int val) {
	LinkList::Node* n = new LinkList::Node;
	n->val = val;
	n->next = nullptr;
	return n;
}
LinkList* create(int list[],int size) {
	LinkList* res = new LinkList;
	res->head = createNode(0);
	LinkList::Node* item = res->head;
	for (int i = 0;i < size;i++) {
		item->next = createNode(list[i]);
		item = item->next;
	}
	return res;
}
void insert(LinkList* list,int val) {
	LinkList::Node* item = list->head;
	while (item->next) {
		item = item->next;
	}
	item->next = createNode(val);
}
void remove(LinkList* list, LinkList::Node* n) {
	LinkList::Node* item = list->head;
	while (item->next) {
		if (item->next == n) {
			item->next = item->next->next;
			return;
		}
		item = item->next;
	}
}
void remove(LinkList* list, int v) {
	LinkList::Node* item = list->head;
	while (item->next) {
		if (item->next->val == v) {
			item->next = item->next->next;
			return;
		}
		item = item->next;
	}
}
void erase(LinkList* list) {
	LinkList::Node* item = list->head;
	LinkList::Node* next = item->next;
	while (next) {
		delete(item);
		item = next;
		next = item->next;
	}
}
LinkList::Node* find(LinkList* list, int v) {
	LinkList::Node* item = list->head;
	LinkList::Node* res = nullptr;
	while (item->next) {
		if (item->next->val == v) {
			res = item->next;
			break;
		}
		item = item->next;
	}
	return res;
}
void print(LinkList* list) {
	LinkList::Node* item = list->head;
	while (item->next) {
		std::cout << item->next->val << " ";
	}
	std::cout << std::endl;
}