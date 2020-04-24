#include <iostream>
#include "SingleList.h"
using namespace std;


void create()
{
	head = NULL;
	head = new Node;
	ptr = head;
	int i = 0;
	while (ptr->next)
	{
		cout<< "请输入值:" << endl;
		cin >> ptr->value;
		ptr->next = new Node;
		ptr = ptr->next;
		i++;
		if (i = 4) 
		{
			return;
		}
	}
}

void erase()
{
	ptr = head;
	while (ptr->next != NULL)
	{
		d = ptr;
		ptr = ptr->next;
		delete d;
	}
}

void print()
{
	ptr = head;
	do 
	{
		cout << ptr->value << '/t' << endl;
		ptr = ptr->next;
	} while (ptr != NULL);
}

void insert(int i,int n)//将值n放在第i位
{
	Node *q = new Node;
	q->value = n;
	ptr = head;
	int m = 1;
	while (m < i-1)
		ptr = ptr->next;
	q->next = ptr->next;
	ptr->next = q->next;
}

int find(int i)//找出第几位的值
{
	ptr = head;
	int m = 1;
	while (m < i )
	{
		ptr = ptr->next;
	}
	return ptr->value;
}

void remove(int i)
{
	int m = 1;
	while (m < i)
	{
		ptr = ptr->next;
	}
	d = ptr;
	ptr = ptr->next;
	delete d;
}


