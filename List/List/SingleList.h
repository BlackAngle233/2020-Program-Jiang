#pragma once
#include<iostream>
using namespace std;


class Node
{
public:
	friend class LinkList;
	Node(int v, Node* n)
	{
		value = v;
		next = n;
	}
	int value;
	Node* next = nullptr;
};

class LinkList
{
private:
	Node* head;
public:
	LinkList()
	{
		head = nullptr;
	}
	LinkList(int a[], int len)
	{
		Node* p;
		head = new Node(-1, nullptr);
		p = head;
		for (int i = 0; i < len; i++)
		{
			p->next = new Node(a[i], nullptr);
			p = p->next;
		}
	}
	virtual ~LinkList()
	{
		Node* p;
		while (this->head != NULL)
		{
			p = this->head;
			this->head = this->head->next;
			delete p;
		}
	}
	void insert(int v)//����ʵ����ǰ��
	{
		Node* p;
		Node* q;
		p = this->head;
		q = this->head->next;
		p->next = new Node(v, q);
	}
	Node* find(int v)
	{
		Node* p;
		p = this->head->next;
		while (p != nullptr)
		{
			if (p->value == v)
			{
				return p;
			}
			else
			{
				p = p->next;
			}
		}
		return p;
	}
	void remove(Node* node)//���ڵ�ɾ
	{
		Node* p;
		p = this->head;
		while (p->next != nullptr)
		{
			if (p->next == node)
			{
				Node* q = p->next->next;
				delete p->next;
				p->next = q;
			}
			else
			{
				p = p->next;
			}
		}
	}
	void remove(int v)//������ɾ
	{
		Node* p;
		p = this->head;
		while (p->next != nullptr)
		{
			if (p->next->value == v)
			{
				Node* q = p->next->next;
				delete p->next;
				p->next = q;
			}
			else
			{
				p = p->next;
			}
		}
	}
	void Print()
	{
		if (this->head != NULL)
		{
			Node* p;
			p = this->head->next;
			while (p != nullptr)
			{
				if (p->next != nullptr)
				{
					cout << p->value << "��>";
				}
				else
				{
					cout << p->value << endl;
				}
				p = p->next;
			}
		}
		else
		{
			cout << "��������ǿ������" << endl;
		}
	}
};

//
//struct LinkList
//{
//	struct Node
//	{
//		Node* next = nullptr;
//		int value;
//	};
//	Node* head;
//};
//
//LinkList* creat(int a[], int len)
//{
//	LinkList* newlist = new LinkList;
//	LinkList::Node* p;
//	newlist->head = new LinkList::Node;
//	p = newlist->head;
//	for (int i = 0; i < len; i++)
//	{
//		p->next = new LinkList::Node;
//		p->next->value = a[i];
//		p = p->next;
//	}
//	p->next = nullptr;
//	return newlist;
//}
//
//void erase(LinkList* list)
//{
//	LinkList::Node* p;
//	while (list->head != NULL)
//	{
//		p = list->head;
//		list->head = list->head->next;
//		delete p;
//	}
//}
//
//void insert(LinkList* list, int v)//����ʵ����ǰ��
//{
//	LinkList::Node* p;
//	LinkList::Node* q;
//	p = list->head;
//	q = list->head->next;
//	p->next = new LinkList::Node;
//	p->next->value = v;
//	p->next->next = q;
//}
//
//LinkList::Node* find(LinkList* list, int v)
//{
//	LinkList::Node* p;
//	p = list->head->next;
//	while (p != nullptr)
//	{
//		if (p->value == v)
//		{
//			return p;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//	return p;
//}
//
//void remove(LinkList* list, LinkList::Node* node)//���ڵ�ɾ
//{
//	LinkList::Node* p;
//	p = list->head;
//	while (p->next != nullptr)
//	{
//		if (p->next == node)
//		{
//			LinkList::Node* q = p->next->next;
//			delete p->next;
//			p->next = q;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//}
//
//void remove(LinkList* list, int v)//������ɾ
//{
//	LinkList::Node* p;
//	p = list->head;
//	while (p->next != nullptr)
//	{
//		if (p->next->value == v)
//		{
//			LinkList::Node* q = p->next->next;
//			delete p->next;
//			p->next = q;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//}
//
//void Print(LinkList* list)
//{
//	if (list->head != NULL)
//	{
//		LinkList::Node* p;
//		p = list->head->next;
//		while (p != nullptr)
//		{
//			if (p->next != nullptr)
//			{
//				cout << p->value << "��>";
//			}
//			else
//			{
//				cout << p->value << endl;
//			}
//			p = p->next;
//		}
//	}
//	else
//	{
//		cout << "��������ǿ������" << endl;
//	}
//	
//
//}
//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������
