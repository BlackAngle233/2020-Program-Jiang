#include <iostream>
#include "SingleList.h"
using namespace std;

SingleList::Node* createNode(int value=0) {
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
	SingleList::Node* head = list->head;
	SingleList::Node* next = head->next;
	while (next != nullptr) {
		delete(head);
		head = next;
		next = head->next;
	}
	delete(head);
	delete(list);
}

void insert(SingleList* list, int value) {
	SingleList::Node* head = list->head;
	while (head->next!=nullptr)
	{
		head = head->next;
	}
	head->value = value;
}

SingleList::Node* find(SingleList* list,int value) {
	SingleList::Node* head = list->head;
	while (head->value != value) {
		if (head->next == nullptr) {
			return nullptr;
		head = head->next;
		}
	}
	return head;
}

void remove(SingleList* list, SingleList::Node* node) {
	SingleList::Node* head = list->head;
	SingleList::Node* last = list->head;
	while (head!= nullptr) {
		if (head == node) {
			last->next = head->next;
			delete(node);
			return;
		}
		last = head;
		head = head->next;
	}
}

void remove(SingleList* list, int value) {
	SingleList::Node* head = list->head;
	SingleList::Node* last = list->head;
	remove(list, find(list, value));

}

void print(SingleList* list) {
	SingleList::Node* node = list->head;
	int i = 0;
	cout << "当前链表为:";
	while (node != nullptr) {
		cout << node->value << " ";
		node = node->next;
		i++;
	}
	cout << endl;
}