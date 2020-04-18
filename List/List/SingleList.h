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

#ifndef SingleList_cpp
#define	SingleList_cpp
//SingleList* create(int[], int len);
void erase(SingleList* list);
void insert(SingleList* list, int v);
//SingleList::Node* find(int v);
void remove(SingleList::Node* node);
void remove(SingleList* list,int v);
void print(SingleList* list);



#endif // !SingleList
