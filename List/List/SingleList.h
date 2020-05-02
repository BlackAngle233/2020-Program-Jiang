#pragma once

class SingleList
{	
public:
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
private:
	Node* head;

public:
	Node* createNode(int v);

	SingleList(int num[], int size);

	void erase();

	void insert(int v);

	SingleList::Node* find(int v);

	void remove(SingleList::Node* n);

	void remove(int v);

	void print();
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������
