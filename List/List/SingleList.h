#pragma once

struct Node
{
	int data;
	Node * next;
};

class MyList
{
public:
	MyList(void);
	void CreatList();
	void InsertList(int nodedata);
	Node* SearchList(int finddata);
	void RemoveList(Node * pfind);
	void PrintList(Node *head);
	~MyList(void);
private:
	Node* m_phead;   
	Node* m_ptemp;   
};


//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������