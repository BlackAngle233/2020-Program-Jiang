#pragma once

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������
SingleList::Node* createNode(int v);

SingleList* create(int num[], int size);

void erase(SingleList* s);

void insert(SingleList* s, int v);

SingleList::Node* find(SingleList* s, int v);

void remove(SingleList* s, SingleList::Node* n);

void remove(SingleList* s, int v);

void print(SingleList* s);