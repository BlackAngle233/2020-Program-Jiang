#pragma once

#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

struct Node
{
	Node* next = nullptr;
	int value;
	Node(int i = 0)
	{
		value = i;
	}
};
struct SingleList
{
	Node* head;
};

SingleList Create(int nums[], int len);
void erase(SingleList sgl);
void insert(SingleList sgl, int n);
Node* find(SingleList sgl, int n);
void remove(SingleList sgl, int n);
void remove(SingleList sgl, Node* x);
void print(Node* head);

#endif // !_SINGLELIST_H_

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������
