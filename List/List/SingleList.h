#pragma once
#include<iostream>
struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	}node;
	Node* head;
	Node* end; 
	Node* pnew;
	int length;
}singlelist;

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能
