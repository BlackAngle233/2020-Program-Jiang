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

#ifndef SingleList_cpp
#define	SingleList_cpp
//SingleList* create(int[], int len);
void erase(SingleList* list);
void insert(SingleList* list, int v);
//SingleList::Node* find(int v);
void remove(SingleList::Node* node);
void remove(SingleList* list,int v);
void print(SingleList* list);



#endif // !SingleList
