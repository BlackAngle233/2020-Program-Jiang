#pragma once
#include <iostream>
using namespace std;

struct LinkList
{
	struct Node
	{
		Node* next;
		int value;
	};
	Node* head;
};

LinkList* creat(int number[], int len)
{
	LinkList list;
	LinkList* result = &list;
	LinkList::Node* p;
	list.head->next = p;
	for (int i = 0; i < len; i++)
	{
		LinkList::Node* add = new LinkList::Node;
		add->value = number[i];
		add->next = nullptr;
		p->next = add;
		p = add;
	}	
}

LinkList::Node* Last(LinkList* Linklist)
{
	LinkList::Node* p;
	p=Linklist->head;
	while (p->next != nullptr) {
		p = p->next;
  }
	return p;
}

void erase(LinkList* Linklist)
{
	LinkList::Node* p=Linklist->head;
	LinkList::Node* p1;
	while (p->next != nullptr) {
		p1 = p->next;
		p->next = nullptr;
		p->value = 0;
		p = p1;
	}
}

void inset(LinkList* list, int v)
{
	LinkList::Node* p0;
	LinkList::Node* p;
	p = list->head;
	for (int i = 0; i < v-1; i++)
	{
		p0 = p;
		p = p->next;
	}
	p->next = p0->next;
	p0->next = p;
	p->value = v;
}

LinkList::Node* find(LinkList* list,int v)
{
	LinkList::Node* p=list->head;
	while(p->value!=v&&p->next!=nullptr)
	{
		p = p->next;
	}
	return p;
}

void remove(LinkList* list,LinkList::Node* node)
{
	LinkList::Node*p = list->head;
	while (p->next != node&&p->next!=nullptr) {
		p = p->next;
	}
	if (p->next != nullptr)
	{
		p->next = p->next->next;
	}
}

void remove(LinkList* list, int v)
{
	LinkList::Node*p = list->head;
	while (p->value!=v&&p->next!=nullptr) {
		p = p->next;
	}
	if (p->next != nullptr) {
		p->next = p->next->next;
	}
}

void print(LinkList* list)
{
	LinkList::Node* p = list->head;
	while (p->next->next != nullptr) {
		cout << p->value << "->";
	}
	cout << p->next->value;
}