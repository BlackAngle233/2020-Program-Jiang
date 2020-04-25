#pragma once
struct Node {
	int value;
	Node* next;
};

struct SingleList {
	Node* head;
	SingleList();
	int Length();
	int CreateSingleList(int size);
	void EraseSingleList();
	void Insert(int value, int n);
	Node* Find(int data);
	void Remove(int value);
	void Print();
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能