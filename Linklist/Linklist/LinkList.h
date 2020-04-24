#pragma once
class Node {
public:
	int data;
	Node *next;
};

class Linklist {
public:
	Linklist();
	~Linklist();
	int createList(int s);
	int insertNode(Node *data,int n);
	int deleteNode(int n);
	void printList();

	int size;
	Node *head;
};