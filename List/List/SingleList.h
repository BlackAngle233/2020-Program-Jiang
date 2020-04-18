#pragma once

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能
SingleList::Node* createNode(int v);

SingleList* create(int num[], int size);

void erase(SingleList* s);

void insert(SingleList* s, int v);

SingleList::Node* find(SingleList* s, int v);

void remove(SingleList* s, SingleList::Node* n);

void remove(SingleList* s, int v);

void print(SingleList* s);