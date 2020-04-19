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

//尾插法
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

//消除单链表
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

// 插入到最后面
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

//查找出现的的第一个符合条件的Node
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

//移除当前Node
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

//移除 和v 一樣的所有Node 
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

//输出当前当链表的所有值
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