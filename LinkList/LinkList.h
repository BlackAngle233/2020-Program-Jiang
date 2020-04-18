#pragma once
struct LinkList
{
	struct Node
	{
		int vlaue{};
		Node* next{};
	};
	Node* head{};
};

LinkList* create(int [], int );
void erase(LinkList*);
void insert(LinkList*, int);
LinkList::Node* find(LinkList::Node*,int);
void remove(LinkList::Node*);
void remove(LinkList*, int);
void print(LinkList*);