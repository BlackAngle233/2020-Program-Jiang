#include <iostream>
#include "linklist.h"
using namespace std;

LinkList::LinkList()
{
	head = NULL;
}


void LinkList::Create(int val[5]) {
	Node *temp = head;
	Node *node = new Node(0);
	for (int i = 0; i < 5; i++) {
		
		temp = new Node(val[i]);
		if (i == 0) {
			node = head = temp;
		}
		else
		{
			node->next = temp;
		}
		temp->next = NULL;
		node = temp;
	}
}

void LinkList::Insert(int val, int pos)
{
	if (pos == 0) {
		Insert(val, 0);
		return;
	}
	if (pos < 0)
	{
		cout << "error" << endl;
		return;
	}
	int index = 1;
	Node *temp = head;
	Node *node = new Node(val);
	if (pos == 0)
	{
		node->next = temp;
		head = node;
		return;
	}
	while (temp != NULL && index < pos)
	{
		temp = temp->next;
		index++;
	}
	if (temp == NULL)
	{
		cout << "error" << endl;
		return;
	}
	node->next = temp->next;
	temp->next = node;
}

void LinkList::Remove(int val)
{
	int pos = val;
	if (pos == -1)
	{
		cout << "error" << endl;
		return;
	}
	if (pos == 1)
	{
		head = head->next;
		return;
	}
	//int index = 2;
	Node *temp = head;
	//Node *res = new Node(0);
	//while (index < pos)
	//temp->next = temp->next->next;
	if (pos>1) {

		for (int i = 2; temp!=NULL;i++) {
			if (i==pos) {
				temp->next = temp->next->next;
			}
			temp = temp->next;
			//res->next = temp;
		}
	}
}

void LinkList::erase(int val) 
{
	Node *temp = head;
	if (head->val==val) {
		head = head->next;
	}

	for (int i = 0;temp->next!=NULL;i++) {
		if (temp->next->val==val) {
			temp->next = temp->next->next;
			for (int i = 0; ; i++)
			{
				if (temp->next->val==val) {
					temp->next = temp->next->next;
				}
				if (temp->next->val!=val) {
					break;
				}
			}
		}
		temp = temp->next;
	}
	if (temp->val==val) {
		delete temp;
	}
}

void LinkList::Find(int val)
{
	Node *temp = head;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->val == val)
			cout << index<<" ";
		temp = temp->next;
		index++;
	}
}


void LinkList::Print()
{
	if (head == NULL)
	{
		cout << "error" << endl;
		return;
	}
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << endl;
}