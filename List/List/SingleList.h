#pragma once

struct Node
{
	int data;
	Node * next;
};

class MyList
{
public:
	MyList(void);
	void CreatList();
	void InsertList(int nodedata);
	Node* SearchList(int finddata);
	void RemoveList(Node * pfind);
	void PrintList(Node *head);
	~MyList(void);
private:
	Node* m_phead;   
	Node* m_ptemp;   
};


//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能