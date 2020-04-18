#include<iostream>
#include"LinkList.h"
using namespace std;
LinkList* create(int nums[], int len)
{
	LinkList* list = new LinkList();
	LinkList::Node* pEnd = list->head = new LinkList::Node();

	for (int i = 0; i < len; ++i)
	{
		LinkList::Node* newNode = new LinkList::Node();
		newNode->next = nullptr;
		newNode->vlaue = nums[i];
		pEnd->next = newNode;
		pEnd = newNode;
	}


	return list;
}
void erase(LinkList* list)
{
	LinkList::Node* p = nullptr;
	if (list->head == nullptr)
		return;
	
	while (list->head->next)
	{
		p = list->head->next;
		delete list->head;
		list->head = p;
	}

	if (list->head)
	{
		delete list->head;
		list->head = nullptr;
	}
	delete list;
	list = nullptr;

}
void insert(LinkList* list , int v)//insert at the head
{
	LinkList::Node* newNode = new LinkList::Node();
	newNode->vlaue = v;
	newNode->next = list->head->next;
	list->head->next = newNode;
}

void insert(LinkList* list, LinkList::Node* node)
{
	node->next = list->head->next;
	list->head->next = node;
}
LinkList::Node* find(LinkList::Node* head,int v)
{
	LinkList::Node* p = head;
	while (p->next)
	{
		if (p->next->vlaue == v)
			return p;
		p = p->next;
	}
	return nullptr;

}
void remove(LinkList* list,LinkList::Node* node)
{
	LinkList::Node* p = list->head;
	while (p->next)
	{
		if (p->next == node)
		{
			p->next = node->next;
			return;
		}
		p = p->next;
	}
}
void remove(LinkList* list, int v)
{
	LinkList::Node* p = list->head;
	while (p && find(p,v))
	{
		p = find(p,v);
		p->next = p->next->next;
	}
}
void print(LinkList* list)
{
	LinkList::Node* p = list->head;
	while (p->next)
	{
		cout << p->next->vlaue;
		p = p->next;
		if (p->next)
		{
			cout << "->";
		}
	}
	cout << endl;
}


