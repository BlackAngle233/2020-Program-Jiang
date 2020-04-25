#pragma once
struct Node {
	int value;
	Node* next;
};

struct SingleList {
	Node* head;
	SingleList();
	int Length();
	int CreateSingleList(int size);
	void EraseSingleList();
	void Insert(int value, int n);
	Node* Find(int data);
	void Remove(int value);
	void Print();
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������