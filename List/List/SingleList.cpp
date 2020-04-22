#include <iostream>
#include "SingleList.h"
/*void insert(singleList*& list, int v)
{
	if (list == NULL)
	{
		list = new singleList;
		list->head = new Node;
	}
	Node* s = new Node;
	s->value = v;
	s->next = list->head->next;
	list->head->next = s;
}
singleList* create(int m[], int len)
{
	singleList* p = NULL;
	for (int i = 0;i < len;i++)
	{
		insert(p, m[i]);
	}
	return p;
}
Node* find(int v, singleList*& list)
{
	if (list == NULL || list->head == NULL)return NULL;
	Node* a = list->head->next;
	while (a)
	{
		if (a->value == v)
		{
			return a;
		}
		a = a->next;
	}
	return NULL;
}
void print(singleList*& list)
{
	if (list == NULL || list->head == NULL)return;
	Node* a = list->head->next;
	while (a)
	{
		std::cout << a->value << ' ';
		a = a->next;
	}
}
void erase(singleList*& list)
{
	if (list == NULL)return;
	else if (list->head == NULL)
	{
		delete list;
		list = NULL;
	}
	Node* a = list->head->next;
	Node* b = a->next;
	while (a)
	{
		delete a;
		a = b;
		if (a)b = a->next;
	}
	delete list->head;
	delete list;
	list = NULL;
}
void remove(singleList*& list, Node*& node)
{
	if (list == NULL || list->head == NULL)return;
	if (node == NULL)return;
	Node* a = list->head->next;
	Node* b = list->head;
	while (a)
	{
		if (a == node)
		{
			b->next = a->next;
			delete a;
			break;
		}
		b = b->next;
		if (b != NULL)a = b->next;
		else break;
	}
}
void remove(singleList*& list, int v)
{
	if (list == NULL || list->head == NULL)return;
	Node* a = find(v, list);
	remove(list, a);
}*/