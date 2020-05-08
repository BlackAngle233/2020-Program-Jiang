#pragma once

#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

class SingleList
{
public:
	struct Node
	{
		Node* next = nullptr;
		int data;
	};

private:
	Node* head;

public:
	Node* node(int v);
	SingleList(int nums[], int len);
	void erase();
	void insert(int n);
	Node* find(int n);
	void remove(int n);
	void remove(Node* x);
	void print();
};

#endif // !_SINGLELIST_H_

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能
