#pragma once
struct Node
{
	Node* next = nullptr;
	int value;
};
class SingleList
{	
	
	Node* head;
public:
	SingleList create(int *a);
	void insert(int pos, int num, SingleList list);

	int find(int num, SingleList list);
	void removepos(int pos, SingleList list);
	void removenum(int num, SingleList list);
	void print(SingleList list);
	~SingleList();
};



//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������