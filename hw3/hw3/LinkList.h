#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

struct LinkList
{
	struct  Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

LinkList* create(int[], int);

void erase(LinkList*);

void insert(LinkList* list, int pos, int v);

LinkList::Node* find(LinkList* list,int v);

void remove(LinkList* list,int pos);

void ShowLinkList(LinkList*);