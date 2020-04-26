#pragma once
#include<iostream>
struct LinkList{
	struct Node {
		int val;
		Node* next=nullptr;
	};
	Node* head;
};

LinkList::Node* createNode(int);
LinkList* create(int[],int);
void insert(LinkList*,int);
void remove(LinkList*,LinkList::Node*);
void remove(LinkList*,int);
void erase(LinkList*);
LinkList::Node* find(LinkList*,int);
void print(LinkList*);