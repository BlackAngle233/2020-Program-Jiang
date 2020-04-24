#pragma once

struct LinkList {
	struct Node {
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

LinkList* create(int[], int len);

void erase(LinkList*);

void insert(LinkList*, int v);

LinkList::Node* find(LinkList* list, int v);

void remove(LinkList* list, LinkList::Node* node);

void remove(LinkList* list, int v);

void print(LinkList* list);