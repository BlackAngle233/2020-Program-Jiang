#pragma once

class LinkList
{
public:
	LinkList(int&,int);
	~LinkList();
	void insert(int);
	void remove(int);
	Node find(int);
	void show();
private:
	Node* head;
	int listNum;
	void create();
};

class Node {
public:
	Node(int) {};
	~Node() {};
	int val;
	Node* next;
};
