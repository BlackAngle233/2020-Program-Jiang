#pragma once

struct Node
{
	Node* next = nullptr;
	int value;
};

class SingleList
{	
public:
	Node* head;
	SingleList();
	void create();
	void erase();
	void insert(int index,int value);
	bool find(int value);
	void remove(int index);
	void remove(Node* n);
	void print();
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������