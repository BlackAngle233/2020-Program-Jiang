#include <iostream>
#include "SingleList.h"

using namespace std;

LinkList* create(int nums[], int len)
{
	LinkList* list = new LinkList;

	LinkList::Node* current = new LinkList::Node;

	list->head = current;

	for (int i = 0; i < len; i++) {
		LinkList::Node* node = new LinkList::Node;
		node->next = nullptr;
		node->value = nums[i];
		current->next = node;
		current = node;
	}

	return list;
}

void erase(LinkList* list)
{
	LinkList::Node* current = list->head;
	if (current->next == nullptr) {
		cout << "List is empty!!!" << endl;
		return;
	}
	while (current->next->next != nullptr) {
		LinkList::Node* temp;
		temp = current->next;
		current->next = current->next->next;
		delete temp;
	}
	LinkList::Node* temp = current->next;
	current->next = nullptr;
	delete temp;
}

void insert(LinkList* list, int v)
{
	LinkList::Node* current = list->head->next;
	if (current == nullptr) {
		LinkList::Node* node = new LinkList::Node;
		node->value = v;
		node->next = nullptr;
		list->head->next = node;
		return;
	}
	while (current->next != nullptr) {
		current = current->next;
	}
	LinkList::Node* node = new LinkList::Node;
	node->value = v;
	node->next = nullptr;
	current->next = node;
}

LinkList::Node* find(LinkList* list, int v)
{
	LinkList::Node* current = list->head->next;
	if (current == nullptr) {
		return nullptr;
	}
	while (current->next != nullptr) {
		if (current->value == v) {
			return current;
		}
		current = current->next;
	}
	if (current->value == v) {
		return current;
	}
	return nullptr;
}

void remove(LinkList* list, LinkList::Node* node)
{
	LinkList::Node* current = list->head;
	if (current->next == nullptr) {
		cout << "List is empty!!!" << endl;
		return;
	}
	while (current->next->next != nullptr) {
		if (current->next == node) {
			current->next = current->next->next;
			delete node;
			return;
		}
		current = current->next;
	}
	if (current->next == node) {
		current->next = nullptr;
		delete node;
	}
}

void remove(LinkList* list, int v)
{
	LinkList::Node* current = list->head;
	if (current->next == nullptr) {
		cout << "List is empty!!!" << endl;
		return;
	}

	while (current->next->next != nullptr) {
		LinkList::Node* temp;
		if (current->next->value == v) {
			temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		current = current->next;
	}
	if (current->next->value == v) {
		LinkList::Node* temp = current->next;
		current->next = nullptr;
		delete temp;
	}
}

void print(LinkList* list)
{
	LinkList::Node* current = list->head->next;
	if (current == nullptr) {
		cout << "List is empty!!!" << endl;
		return;
	}
	while (current->next != nullptr) {
		cout << current->value << "->";
		current = current->next;
	}
	cout << current->value << endl;
}