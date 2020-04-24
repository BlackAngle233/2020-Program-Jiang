#include <iostream>
#include <cstdarg>
#include "SingleList.h"
using namespace std;

SingleList* SingleList_create()
{
	return new SingleList();
}

SingleList* SingleList_create(int origin[],int length)
{
	SingleList* result = new SingleList();
	SingleList::Node* LastNode = nullptr;
	for (int i = 0; i < length; i++) {
		SingleList::Node* node =new SingleList::Node();
		if (LastNode != nullptr)LastNode->next = node;
		else {
			result->head = node;
		}
		node->value = origin[i];
		LastNode = node;
	}
	return result;
}

SingleList* SingleList_create(int length, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, length);

	SingleList* result = new SingleList();
	SingleList::Node* LastNode = nullptr;
	for (int i = 0; i < length; i++) {
		SingleList::Node* node = new SingleList::Node();
		if (LastNode != nullptr)LastNode->next = node;
		else {
			result->head = node;
		}
		node->value = va_arg(arg_ptr, int);
		LastNode = node;
	}
	return result;
}

int SingleList_getLength(SingleList* list)
{
	SingleList::Node* node = list->head;
	int length = 0;
	while (node != nullptr) {
		length++;
		node = node->next;
	}
	return length;
}

void SingleList_erase(SingleList* list)
{
	SingleList::Node* node = list->head;
	while (node != nullptr) {
		SingleList::Node* needDelete = node;
		node = node->next;
		delete needDelete;
	}
}

void SingleList_insert_InsertAfter(SingleList* list, int index, int value)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (index == i) {
			SingleList::Node* nextnode = node->next;
			node->next = new SingleList::Node();
			node->next->next = nextnode;
			node->next->value = value;
			break;
		}
		node = node->next;
		i++;
	}
}

void SingleList_insert_InsertBefore(SingleList* list, int index, int value)
{
	SingleList::Node* node = list->head;
	if (index == 0) {
		SingleList::Node* nextNode = list->head;
		list->head = new SingleList::Node();
		list->head->next = nextNode;
		list->head->value = value;
		return;
	}
	int i = 0;
	while (node != nullptr) {
		if (index == i + 1) {
			SingleList::Node* nextnode = node->next;
			node->next = new SingleList::Node();
			node->next->next = nextnode;
			node->next->value = value;
			return;
		}
		node = node->next;
		i++;
	}
}

void SingleList_insert_InsertAfter(SingleList::Node* node, int value)
{
	SingleList::Node* nextNode = node->next;
	node->next = new SingleList::Node();
	node->next->next = nextNode;
	node->next->value = value;
}

int SingleList_find_FirstIndexOf(SingleList* list, int value)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (node->value == value)return i;
		node = node->next;
		i++;
	}
	return -1;
}

int SingleList_find_LastIndexOf(SingleList* list, int value)
{
	SingleList::Node* node = list->head;
	int i = 0;
	int result = -1;
	while (node != nullptr) {
		if (node->value == value)result = i;
		node = node->next;
		i++;
	}
	return result;
}

SingleList::Node* SingleList_find_FirstNodeOf(SingleList* list, int value)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (node->value == value)return node;
		node = node->next;
		i++;
	}
	return nullptr;
}

SingleList::Node* SingleList_find_GetNode(SingleList* list, int index)
{
	SingleList::Node* node = list->head;
	int i = 0;
	int result = -1;
	while (node != nullptr) {
		if (index == i)return node;
		node = node->next;
		i++;
	}
	return nullptr;
}

int SingleList_find_GetValue(SingleList* list, int index)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (index == i)return node->value;
		node = node->next;
		i++;
	}
	return 1 << 31;
}

void SingleList_remove_RemoveAtIndex(SingleList* list, int index)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (index == i + 1) {
			SingleList::Node* needDelete = node->next;
			node->next = node->next->next;
			delete needDelete;
			return;
		}
		node = node->next;
		i++;
	}
}

void SingleList_remove_RemoveValue(SingleList* list, int value)
{
	SingleList::Node* node = list->head;
	int i = 0;
	while (node != nullptr) {
		if (node->next->value==value) {
			SingleList::Node* needDelete = node->next;
			node->next = node->next->next;
			delete needDelete;
			return;
		}
		node = node->next;
		i++;
	}
}

void SingleList_remove_RemoveNode(SingleList* list, SingleList::Node* node)
{
	SingleList::Node* tnode = list->head;
	int i = 0;
	while (tnode != nullptr) {
		if (tnode->next == node) {
			tnode->next = tnode->next->next;
			delete node;
			return;
		}
		tnode = tnode->next;
		i++;
	}
}

void SingleList_print(SingleList* list)
{
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
