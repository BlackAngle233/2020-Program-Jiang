#include <iostream>

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

//β�巨
SingleList* create(int numList[], int len) 
{
	SingleList* singleList = new SingleList;
	singleList->head = new SingleList::Node;
	SingleList::Node* tempTail = singleList->head;
	for (int i = 0;i < len;i++) 
	{
		SingleList::Node* newNode = new SingleList::Node;
		newNode->value = numList[i];
		newNode->next = nullptr;
		tempTail->next = newNode;
		tempTail = newNode;
	}
	return singleList;
}

//����������
void erase(SingleList* list) 
{
	SingleList::Node* tempTail = list->head;
	while (tempTail != nullptr)
	{
		SingleList::Node* temp = tempTail;
		tempTail = tempTail->next;
		delete temp;
	}
}

// ���뵽�����
void insert(SingleList* list, int v) 
{
	SingleList::Node* tempTail = list->head;
	while (tempTail->next != nullptr)
	{
		tempTail = tempTail->next;
	}

	SingleList::Node* newNode = new SingleList::Node;
	newNode->value = v;
	newNode->next = nullptr;
	tempTail->next = newNode;
}

//���ҳ��ֵĵĵ�һ������������Node
SingleList::Node* find(SingleList* list,int v)
{
	SingleList::Node* tempTail = list->head;
	while (tempTail->next != nullptr)
	{
		if (tempTail->value == v) {
			return tempTail;
		}
		tempTail = tempTail->next;
	}
}

//�Ƴ���ǰNode
void remove(SingleList* list,SingleList::Node* node)
{
	SingleList::Node* tempTail = list->head;
	while (tempTail->next != nullptr)
	{
		if (tempTail->next == node) 
		{
			SingleList::Node* temp = tempTail->next;
			tempTail->next = temp->next;
			delete temp;
		}
		else 
		{
			tempTail = tempTail->next;
		}
	}
}

//�Ƴ� ��v һ�ӵ�����Node 
void remove(SingleList* list, int v)
{
	SingleList::Node* tempTail = list->head;
	while (tempTail->next != nullptr)
	{
		if (tempTail->next->value == v) 
		{
			SingleList::Node* temp = tempTail->next;
			tempTail->next = temp->next;
			delete temp;
		}
		else 
		{
			tempTail = tempTail->next;
		}
	}
}

//�����ǰ�����������ֵ
void print(SingleList* list) 
{
	SingleList::Node* tempTail = list->head->next;
	while (tempTail != nullptr) 
	{
		std::cout << tempTail->value;
		tempTail = tempTail->next;
		if (tempTail != nullptr) 
		{
			std::cout << "->";
		}
	}
	std::cout << std::endl;
}