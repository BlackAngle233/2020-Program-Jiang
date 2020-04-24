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

SingleList* SingleList_create();
SingleList* SingleList_create(int origin[],int length);
SingleList* SingleList_create(int length, ...);

int SingleList_getLength(SingleList* list);

void SingleList_erase(SingleList* list);

void SingleList_insert_InsertAfter(SingleList* list, int index, int value);
void SingleList_insert_InsertBefore(SingleList* list, int index, int value);
void SingleList_insert_InsertAfter(SingleList::Node* node, int value);

int SingleList_find_FirstIndexOf(SingleList* list, int value);
int SingleList_find_LastIndexOf(SingleList* list, int value);
SingleList::Node* SingleList_find_FirstNodeOf(SingleList* list, int value);
SingleList::Node* SingleList_find_GetNode(SingleList* list, int index);
int SingleList_find_GetValue(SingleList* list, int index);

void SingleList_remove_RemoveAtIndex(SingleList* list, int index);
void SingleList_remove_RemoveValue(SingleList* list, int value);
void SingleList_remove_RemoveNode(SingleList* list, SingleList::Node* node);

void SingleList_print(SingleList* list);