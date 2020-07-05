#pragma once

class SingleList
{	
public:
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
private:
	Node* head;

public:
	Node* createNode(int v);

	SingleList(int num[], int size);

	void erase();

	void insert(int v);

	SingleList::Node* find(int v);

	void remove(SingleList::Node* n);

	void remove(int v);

	void print();
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能
