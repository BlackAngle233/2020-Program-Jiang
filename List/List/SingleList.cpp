#include <iostream>
#include "SingleList.h"

SingleList Create(int nums[], int len)
{
	SingleList sgl;
	sgl.head = new Node();
	Node* cur;
	cur = sgl.head;
	
	for (int i = 0; i < len; i++)
	{
		Node *newNode = new Node(nums[i]);
		cur->next = newNode;
		cur = newNode;
	}

	cur->next = NULL;
	return sgl;
}

void erase(SingleList sgl)
{
	sgl.head->next = NULL;
}

void insert(SingleList sgl, int n)
{
	Node* cur = sgl.head->next;
	Node* prev = sgl.head;
	Node* newNode = new  Node(n);
	newNode->next = cur;
	prev->next = newNode;
}

Node* find(SingleList sgl, int n)
{
	Node* cur = sgl.head->next;
	while (cur != NULL)
	{
		if (cur->value == n)
			return cur;
		cur = cur->next;
	}
}

void remove(SingleList sgl, int n)
{
	Node* cur = sgl.head->next;
	Node* prev = sgl.head;
	while (cur != NULL)
	{
		if (cur->value == n)
			prev->next = cur->next;
		else
			prev = cur;
		cur = cur->next;
	}
}

void remove(SingleList sgl, Node* x)
{
	Node* cur = sgl.head->next;
	Node* prev = sgl.head;
	while (cur != NULL)
	{
		if (cur == x)
		{
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void print(Node* head)
{
	Node* cur = head->next;
	while (cur != NULL)
	{
		std::cout << cur->value << "  " << std::ends;
		cur = cur->next;
	}
	std::cout << std::endl;
}
