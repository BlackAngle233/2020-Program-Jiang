#include <iostream>
#include "SingleList.h"
using namespace std;

SingleList::Node* createNode(int value) {
	SingleList::Node* result = new SingleList::Node();
	result->next = nullptr;
	result->value = value;
	return result;
}

SingleList* create(int num[], int len) {
	SingleList* result = new SingleList();
	result->head = createNode(num[0]);
	SingleList::Node* head = result->head;
	for (int i = 1; i < len; ++i) {
		head->next = createNode(num[i]);
		head = head->next;
	}
	return result;
}

void erase(SingleList* list) {
	SingleList::Node* now = list->head;
	SingleList::Node* next;
	while (now != nullptr) {
		next = now->next;
		delete now;
		now = next;
	}
	delete list;
}

void insert(SingleList* list, int value) {
	SingleList::Node* head = list->head;
	while (head->next!=nullptr)
	{
		head = head->next;
	}
	head->next = createNode(value);

}


SingleList::Node* find(SingleList* list, int value) {
	SingleList::Node* now = list->head;
	while (now != nullptr) {
		if (now->value == value)
			return now;

		now = now->next;
	}
	return nullptr;
}


void remove(SingleList* list, SingleList::Node* node) {
	SingleList::Node* now= list->head;	
	while (now != nullptr) {
		if (now == node) {
			list->head = now->next;
			delete now;
			break;
		}
		if (now->next == node) {
			if (now->next->next != nullptr) {
				SingleList::Node* tmp = now->next;
				now->next = now->next->next;
				delete tmp;
			}
			else
			{
				delete now->next;
				now->next = nullptr;
			}
			break;
		}	
		now = now->next;
	}
}

void remove(SingleList* list, int value) {
	SingleList::Node* head = list->head;
	SingleList::Node* last = list->head;
	remove(list, find(list, value));

}

void print(SingleList* list) {
	if (list == nullptr) {
		cout << "这是个空链表";
		return;
	}
	SingleList::Node* node = list->head;
	cout << "当前链表为:";
	while (node != nullptr) {
		cout << node->value;
		node = node->next;
		if (node != nullptr) 
			cout << "->";
	}
	cout << endl;
}