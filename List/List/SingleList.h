#pragma once

#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

class SingleList
{
public:
	struct Node
	{
		Node* next = nullptr;
		int data;
	};

private:
	Node* head;

public:
	Node* node(int v);
	SingleList(int nums[], int len);
	void erase();
	void insert(int n);
	Node* find(int n);
	void remove(int n);
	void remove(Node* x);
	void print();
};

#endif // !_SINGLELIST_H_

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������
