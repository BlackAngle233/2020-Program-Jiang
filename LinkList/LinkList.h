#pragma once
#include<iostream>
class LinkList{
public:
	int data;
	LinkList* next;

	LinkList(int);
	//LinkList(char);
	void release();
};

class ListHead {
public:
	LinkList* firstLink;
	LinkList* lastLink;

	ListHead();
	void list_add(LinkList);
	void list_delete(int data);
};

