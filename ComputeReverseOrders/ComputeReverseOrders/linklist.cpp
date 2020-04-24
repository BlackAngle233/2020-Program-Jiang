#include"linklist.h"
#include <iostream>

using namespace std;

LinkList* create(int a[], int len) {
	LinkList* list=new LinkList;
	list->head = new LinkList::Node;
	list->head->value = a[0];

	LinkList::Node* tem = list->head->next;

	if(len>1)
		for (int i = 1; i < len; i++) {
			tem = new LinkList::Node;
			tem->value = a[i];
			tem = tem->next;
	}

	return list;
}

void erase(LinkList* list) {
	LinkList::Node* tem1 = list->head;
	LinkList::Node* tem2 = list->head->next;

	while (tem2 != nullptr) {
		delete tem1;
		tem1 = tem2;
		tem2 = tem2->next;
	}

	delete tem1;
	delete tem2;
	list->head = nullptr;
}

void insert(LinkList* list, int v) {
	LinkList::Node* tem1 = list->head;
	LinkList::Node* tem2 = list->head->next;

	while (tem2 != nullptr) {
		tem1 = tem2;
		tem2 = tem2->next;
	}

	tem2 = new LinkList::Node;
	tem2->value = v;
}

LinkList::Node* find(LinkList* list, int v) {
	LinkList::Node* tem1 = list->head;
	LinkList::Node* tem2 = list->head->next;

	while (tem1->value != v && tem2 != nullptr) {
		tem1 = tem2;
		tem2 = tem2->next;
	}
	if (tem2 != nullptr)
		return tem1;
	else return nullptr;
}

void remove(LinkList* list, LinkList::Node* node) {
	LinkList::Node* tem1 = list->head;
	LinkList::Node* tem2 = list->head->next;

	while (tem2!= node && tem2 != nullptr) {
		tem1 = tem2;
		tem2 = tem2->next;
	}

	if (tem2 == node) {
		tem1->next = tem2->next;
		delete tem2;
	}
}

void remove(LinkList* list, int v) {
	remove(list, find(list, v));
}

void print(LinkList* list) {
	LinkList::Node* tem1 = list->head;
	LinkList::Node* tem2 = list->head->next;
	cout << endl;
	while (tem2 != nullptr) {
		cout << tem1->value << '->';
		tem1 = tem2;
		tem2 = tem2->next;
	}
	cout << endl;
}