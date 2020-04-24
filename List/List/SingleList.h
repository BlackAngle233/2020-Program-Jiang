#pragma once
#include<iostream>
using namespace std;

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};
SingleList* create(int a[],int len) {
	SingleList* newlist = new SingleList;
	SingleList::Node* p;
	newlist->head = new SingleList::Node;
	p = newlist->head;
	for (int i = 0; i < len; i++) {
		p->next->value = a[i];
		p = p->next;
	}
	p->next = nullptr;
	return newlist;
}
void erase(SingleList* list) {
	SingleList::Node* p;
	p = list->head;
	while (p != nullptr) {
		p = list->head;
		list->head = list->head->next;
		delete p;
	}
}
void insert(SingleList* list,SingleList::Node* n,int x) {
	SingleList::Node* p;
	SingleList::Node* q;
	p = list->head;
	q = list->head->next;
	if (n!=nullptr) {
		while (q != nullptr) {
			if (q == n) break;
			p = q;
			q = q->next;
		}
	}
	p->next = new SingleList::Node;
	p->next->value = x;
	p->next->next = q;
}
SingleList::Node* find(SingleList* list, int x) {
	SingleList::Node* p;
	p = list->head->next;
	while (p!= nullptr) {
		if (p->value == x) {
			return p;
		}
		p = p->next;
	}
	return p;
}
void remove(SingleList* list,int x) {
	SingleList::Node* p;
	p = list->head;
	while (p->next != nullptr) {
		if (p->value == x) 
			p->next=p->next->next;
		else p = p->next;
	}
}
void remove(SingleList* list, SingleList::Node* n) {
	SingleList::Node* p;
	p = list->head;
	while (p->next != nullptr) {
		if (p == n)
			p->next = p->next->next;
		else p = p->next;
	}
}
void print(SingleList* list) {
	SingleList::Node* p;
	p = list->head->next;
	while(p!=nullptr)
	{
		std::cout<< p->value << "->" << "";
		p = p -> next;
	}
	std::cout <<""<< endl;
}
//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能