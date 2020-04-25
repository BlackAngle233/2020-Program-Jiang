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


SingleList* create(int num[], int len);
void erase(SingleList* list);
void insert(SingleList* list, int value);
SingleList::Node* find(SingleList* list,int value);
void remove(SingleList* list, SingleList::Node* node);
void remove(SingleList* list,int value);
void print(SingleList* list);

