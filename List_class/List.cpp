#include "List.h"
LinkList::LinkList(int a[], int len)
{
	head = new Node();
	Node *p;
	head->next = new Node();
	p = head->next;
	for (int i = 0; i < len - 1; i++)
	{
		p->value = a[i];
		p->next = new Node();
		p = p->next;
	}
	p->value = a[len - 1];
	length = len;
}

LinkList::~LinkList()
{
	Node *p = head->next;
	while (p != nullptr)
	{
		p = p->next;
		delete head->next;
		head->next = p;
	}
	delete head;
	head = nullptr;
	length = 0;
}

void LinkList::deleteList()
{
	Node *p = head->next;
	while (p != nullptr)
	{
		p = p->next;
		delete head->next;
		head->next = p;
	}
	delete head;
	head = nullptr;
	length = 0;
}

void LinkList::insert(int v) //尾插
{
	Node *p = head->next;
	while (p->next != nullptr)
		p = p->next;
	p->next = new Node();
	p->next->value = v;
	p->next->next = nullptr;
	length += 1;
}

Node* LinkList::find(int v)
{
	Node *p = head->next;
	while (p != nullptr)
		if (p->value != v)
			p = p->next;
		else
			break;
	if (!(p->value == v))
		std::cout << "Not found!" << std::endl;
	return p;
}

void LinkList::remove(Node *node)
{
	Node *p = head;
	Node *p2 = p->next;
	while (p2 != nullptr)
	{
		if (p2 != node)
		{
			p = p->next;
			p2 = p2->next;
		}
		else
			break;
	}
	if (p2 == node)
	{
		p->next = p2->next;
		delete p2;
		length -= 1;
		if (length == 0)
			head->next = nullptr;
	}
}

void LinkList::remove(int v)
{
	Node *p = head;
	Node *p2 = p->next;
	while (p2 != nullptr)
	{
		if (p2->value != v)
		{
			p = p->next;
			p2 = p2->next;
		}
		else
			break;
	}
	if (p2->value == v)
	{
		p->next = p2->next;
		delete p2;
		length -= 1;
		if (length == 0)
			head->next = nullptr;
	}
}

void LinkList::print()
{
	if (length == 0)
	{
		std::cout << "It has 0 node!" << std::endl;
		return;
	}
	Node *p = head->next;
	std::cout << p->value;
	p = p->next;
	while (p != nullptr)
	{
		std::cout << "->" << p->value;
		p = p->next;
	}
	std::cout << '\n'
			  << "It has " << length << " nodes" << std::endl;
}