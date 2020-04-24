#pragma once

#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

struct Node
{
	Node* next = nullptr;
	int value;
	Node(int i = 0)
	{
		value = i;
	}
};
struct SingleList
{
	Node* head;
};

SingleList Create(int nums[], int len);
void erase(SingleList sgl);
void insert(SingleList sgl, int n);
Node* find(SingleList sgl, int n);
void remove(SingleList sgl, int n);
void remove(SingleList sgl, Node* x);
void print(Node* head);

#endif // !_SINGLELIST_H_

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能
