#pragma once

struct Node
{
	Node* next = nullptr;
	int value;
};
Node* head, *ptr,*d, a, b, c;


void create();
void erase();
void insert(int i,int n);
int find(int i);
void remove(int i);
void print();


//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������