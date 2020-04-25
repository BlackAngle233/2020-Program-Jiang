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


SingleList* create(int num[], int len);
void erase(SingleList* list);
void insert(SingleList* list, int value);
SingleList::Node* find(SingleList* list,int value);
void remove(SingleList* list, SingleList::Node* node);
void remove(SingleList* list,int value);
void print(SingleList* list);

