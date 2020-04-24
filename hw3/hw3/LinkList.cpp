#include "pch.h"
#include "LinkList.h"

LinkList* create(int a[], int len)
{
	LinkList* l = new LinkList{};

	if (len == 0)
		return l;

	l->head = new LinkList::Node{ nullptr,a[0] };
	LinkList::Node* now = l->head;


	for (int i = 1; i < len; i++) 
	{
		LinkList::Node* tmp = new LinkList::Node{ nullptr,a[i] };

		now->next = tmp;
		now = tmp;
	}

	return l;
}

void erase(LinkList* list) {
	if (list->head == nullptr) {
		delete list->head;
		delete list;
	}

	LinkList::Node* now = list->head;

	while (now->next != nullptr) {
		LinkList::Node* tmp = now->next;
		delete now;
		now = tmp;
	}

}

void insert(LinkList* list, int pos, int v) {
	LinkList::Node* add = new LinkList::Node{ nullptr,v };

	LinkList::Node* now = list->head;
	for (int i = 0; i < pos-1; i++) {
		now = now->next;
	}
	add->next = now->next;
	now->next = add;
}

LinkList::Node* find(LinkList* list,int v) {
	LinkList::Node* now = list->head;
	int i=0;

	while (now->value != v) {
		now = now->next;
		i = i + 1;
	}

	return now;
}

void remove(LinkList* list, int pos) {
	LinkList::Node* now = list->head;
	for (int i = 0; i < pos - 2; i++) {
		now = now->next;
	}

	LinkList::Node* tmp = now->next->next;

	delete now->next;

	now->next = tmp;

}

void ShowLinkList(LinkList* list) 
{
	LinkList::Node* now = list->head;

	while (now->next != nullptr) {
		cout << now->value << "->";
		now = now->next;
	}
	cout << now->value << endl;
}