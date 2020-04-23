#pragma once
#include <iostream>
struct SingleList
{	
	struct Node
	{
		Node* next ;
		int value;
		Node()
		{
			next = nullptr;
		}
	};
	Node *head;
	int length;
};
SingleList creat(int a[],int len)			//尾插法建立链表
{
	SingleList s;
	s.head = new SingleList::Node();
	SingleList::Node *p;
	s.head->next = new SingleList::Node();
	p = s.head->next;
	for (int i = 0; i < len-1;i++)
	{
		p->value = a[i];
		p->next = new SingleList::Node();
		p = p->next;
	}
	p->value = a[len - 1];
	s.length = len;
	return s;
}

void erase(SingleList* a)				//删除所有节点
{
	SingleList::Node *p = a->head->next;
	while (p!=nullptr)
	{
		p = p->next;
		delete a->head->next;
		a->head->next = p;
	}
	delete a->head;
	a->head = nullptr;
	a->length = 0;
}

void insert(SingleList *list, int v)			//尾插
{
	SingleList::Node *p = list->head->next;
	while(p->next!=nullptr)
		p = p->next;
	p->next = new SingleList::Node();
	p->next->value = v;
	p->next->next = nullptr;
	list->length += 1;
}

SingleList::Node* find(SingleList* list, int v)
{
	SingleList::Node *p = list->head->next;
	while(p!=nullptr )
		if(p->value!=v)p=p->next;
		else
			break;
	if(!(p->value==v))
		std::cout << "Not found!" << std::endl;
	return p;
} 

void remove(SingleList* list, SingleList::Node* node)
{
	SingleList::Node *p = list->head;
	SingleList::Node *p2 = p->next;
	while(p2!=nullptr )
	{
		if(p2!=node)
		{
			p = p->next;
			p2 = p2->next;
		}
		else
			break;
	}
	if(p2==node)
	{
		p->next = p2->next;
		delete p2;
		list->length -= 1;
		if(list->length == 0)
			list->head->next = nullptr;
	}
}

void remove(SingleList* list,int v)
{
	SingleList::Node *p = list->head;
	SingleList::Node *p2 = p->next;
	while(p2!=nullptr )
	{
		if(p2->value!=v)
		{
			p = p->next;
			p2 = p2->next;
		}
		else
			break;
	}
	if(p2->value == v)
	{
		p->next = p2->next;
		delete p2;
		list->length -= 1;
		if(list->length == 0)
			list->head->next = nullptr;
	}
}

void print(SingleList* list)
{
	if(list->length==0)
	{
		std::cout << "It has 0 node!" << std::endl;
		return;
	}
	SingleList::Node *p = list->head->next;
	std::cout << p->value;
	p = p->next;
	while(p!=nullptr)
	{
		std::cout << "->" << p->value;
		p = p->next;
	}
	std::cout << '\n'<< "It has " << list->length << " nodes" << std::endl;
}
//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能