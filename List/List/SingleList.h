#pragma once

struct SingleList{
	private:
		Node* head;
    public:
		int Len();
		int CreateSingleList(int size);
		void EraseSingleList();
		void Insert(int value, int n);
		Node* Find(int data);
		void Remove(int value);
		void Print();
};

struct Node{
	public:
		int value;
		Node* next;
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������