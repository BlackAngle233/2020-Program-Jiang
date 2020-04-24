#pragma once

struct Node
{
	Node* next = nullptr;
	int value;
};
Node* head, *ptr,*d, a, b, c;


void create();
void erase();
void insert(int i,int n);
int find(int i);
void remove(int i);
void print();


//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能