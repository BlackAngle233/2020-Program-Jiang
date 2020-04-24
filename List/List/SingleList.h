#pragma once
#include <iostream>
using namespace std;

struct SingleList
{
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
	int length;
};
void Erase(SingleList *&singleList)
{
	SingleList::Node* cur = singleList->head;
	SingleList::Node* temp;
	while (cur != nullptr)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	delete singleList;
	singleList = nullptr;
}
SingleList* Create(int m[],int len)
	{
		SingleList* singleList = new SingleList;
		singleList->length = len;
		singleList->head = new SingleList::Node;
		SingleList::Node* p;
		p = singleList->head;
		for (int i = 0; i < len; i++)
		{
			p->next = new SingleList::Node;
			p->next->value = m[i];
			p = p->next;
		}
		return singleList;
	}
void Remove(SingleList* singleList, int v)
{
	SingleList::Node* cur = singleList->head->next;
	SingleList::Node* pre = singleList->head;
	while (cur != nullptr)
	{
		if (cur->value != v)
		{
			cur = cur->next;
			pre = pre->next;
			continue;
		}
		else
		{
			if (cur->next != nullptr)
				pre->next = cur->next;
			else
			{
				pre->next = nullptr;
			}
			delete cur;
			cur = pre->next;
		}
	}
}
void Insert(SingleList* singleList, int v, int index)
{
	if (((*singleList).length + 1) < index || index < 0)
	{
		cout << "invalid index" << endl;
	}
	else
	{
		SingleList::Node* cur = new SingleList::Node;
		cur = singleList->head;
		SingleList::Node* next = new SingleList::Node;
		SingleList::Node* newNode = new SingleList::Node;
		(*newNode).value = v;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		next = cur->next;
		cur->next = newNode;
		newNode->next = next;
		singleList->length += 1;
	}
}
void Print(SingleList* singleList)
	{
	SingleList::Node* p = singleList->head->next;
		if (singleList != nullptr)
			while (p != nullptr)
			{
				cout << p->value;
				p = p->next;
				if (p != nullptr)
					cout << "->";
			}
		else
			cout << "链表为空";
	}
SingleList::Node* Find(SingleList* singleList, int v)
{
	SingleList::Node* cur = singleList->head->next;
	while (cur != nullptr)
	{
		if (cur != nullptr)
		{
			if (cur->value == v)
			{
				cout << cur->value << endl;
				return cur;
			}
		}
		cur = cur->next;
	}
	return cur;
}



//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能