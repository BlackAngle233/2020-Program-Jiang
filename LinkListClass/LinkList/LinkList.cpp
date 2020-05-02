#include<iostream>
#include"LinkList.h"
using namespace std;
LinkList:: LinkList(const int nums[], int len)
{
	Node* pEnd = head = new Node();

	for (int i = 0; i < len; ++i)
	{
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->value = nums[i];
		pEnd->next = newNode;
		pEnd = newNode;
	}
}
LinkList::~LinkList()
{
	Node* p = NULL;

	while (head != NULL)
	{
		p = head->next;
		delete head;
		head = p;
	}

	delete head;
}

LinkList::Node* LinkList::getHead() const{ return head; }

void LinkList::insert(int v)//insert at the head
{
	Node* newNode = new Node();
	newNode->value = v;
	newNode->next = head->next;
	head->next = newNode;
}

void LinkList::insert(Node* node)
{
	node->next = head->next;
	head->next = node;
}
LinkList::Node* LinkList::find(int v) const
{
	Node* p = head;
	while (p->next)
	{
		if (p->next->value == v)
			return p->next;
		p = p->next;
	}
	return nullptr;

}
LinkList::Node* LinkList::findBefore(int v) const
{
	Node* p = head;
	while (p->next)
	{
		if (p->next->value == v)
			return p;
		p = p->next;
	}
	return nullptr;

}
void LinkList::remove(Node* node)
{
	Node* p = head;
	while (p->next)
	{
		if (p->next == node)
		{
			p->next = node->next;
			return;
		}
		p = p->next;
	}
}
void LinkList::remove(int v)
{
	Node* p = head;
	while (p && findBefore(v))
	{
		p = findBefore(v);
		p->next = p->next->next;
	}
}
void LinkList::print() const
{
	Node* p = head;
	while (p->next)
	{
		cout << p->next->value;
		p = p->next;
		if (p->next)
		{
			cout << "->";
		}
	}
	cout << endl;
}
size_t LinkList::size() const
{
	int len{};
	Node* p = head;
	while (p->next)
	{
		++len;
		p = p->next;
	}
	return len;
}



ostream& operator<<(ostream& os, const LinkList& list) 
{
	LinkList::Node* p = list.getHead();
	while (p->next)
	{
		os << p->next->value;
		p = p->next;
		if (p->next)
		{
			os << "->";
		}
	}
	os << endl;
	return os;
}
