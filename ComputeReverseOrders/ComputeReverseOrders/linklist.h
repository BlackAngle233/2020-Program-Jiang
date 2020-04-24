#pragma once
using namespace std;
struct LinkList
{
	struct Node {
		int value;
		Node* next = nullptr;
	};

	Node* head;
};

	LinkList* create(int a[], int len);

	void erase(LinkList* list);

	void insert(LinkList* list, int v);

	LinkList::Node* find(LinkList* list,int v);

	void remove(LinkList* list,LinkList::Node* node);

	void remove(LinkList* list, int v);

	void print(LinkList* list);
