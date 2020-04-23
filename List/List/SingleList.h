#pragma once

struct Node
{
	Node* next = nullptr;
	int value;
};

class SingleList
{	
public:
	Node* head;
	SingleList();
	void create();
	void erase();
	void insert(int index,int value);
	bool find(int value);
	void remove(int index);
	void remove(Node* n);
	void print();
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能