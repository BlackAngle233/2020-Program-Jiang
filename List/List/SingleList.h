#pragma once
struct Node
{
	Node* next = nullptr;
	int value;
};
class SingleList
{	
	
	Node* head;
public:
	SingleList create(int *a);
	void insert(int pos, int num, SingleList list);

	int find(int num, SingleList list);
	void removepos(int pos, SingleList list);
	void removenum(int num, SingleList list);
	void print(SingleList list);
	~SingleList();
};



//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能