#include <iostream>
#include "SingleList.h"
using namespace std;

SingleList::Node* SingleList::node(int v)
{
	SingleList::Node* node = new SingleList::Node();
	node->data = v;
	node->next = nullptr;
	return node;
}

SingleList::SingleList(int nums[], int len)
{
	head = node(0);
	Node* cur = head;
	for (int i = 0; i< len; i++)
	{
		cur->next = node(nums[i]);
		cur = cur->next;
	}
}

void SingleList::erase()
{
	Node* cur = head;
	Node* next = cur->next;
	while (next != nullptr)
	{
		delete cur;
		cur = next;
		next = cur->next;
	}
	delete cur;
	delete this;
}

void SingleList::insert(int n)
{
	Node* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node(n);
}

SingleList::Node* SingleList::find(int n)
{
	Node* cur = head;
	while (cur->next != nullptr)
	{
		if (cur->data == n)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}

void SingleList::remove(int n)
{
	Node* cur = head;
	Node* next = cur->next;
	while (next != nullptr)
	{
		if (next->data == n)
		{
			cur->next = next->next;
			delete(next);
			next = cur->next;
		}
		else
		{
			cur = next;
		}
		next = cur->next;
	}
}

void SingleList::remove(Node* x)
{
	Node* cur = head;
	Node* next = cur->next;
	while (next != nullptr)
	{
		if (next == x)
		{
			cur->next = next->next;
			delete(x);
			return;
		}
		cur = next;
		next = next->next;
	}
}

void SingleList::print()
{
	Node* cur = head;
	while (cur->next != nullptr)
	{
		cur = cur->next;
		cout << cur->data;
		if (cur->next != nullptr)
			cout << "->";
	}
	cout << endl;
}
