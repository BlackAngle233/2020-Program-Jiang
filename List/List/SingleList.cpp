#include <iostream>
#include "SingleList.h"

SingleList::Node* createNode(int v) {
	SingleList::Node* result = new SingleList::Node();
	result->next = NULL;
	result->value = v;
	return result;
}

SingleList* create(int num[], int size) {
	SingleList* result = new SingleList();
	result->head = createNode(0);
	SingleList::Node* tmp = result->head;
	for (int i = 0; i < size; ++i) {
		tmp->next = createNode(num[i]);
		tmp = tmp->next;
	}
	return result;
}

void erase(SingleList* s) {
	SingleList::Node* tmp = s->head;
	SingleList::Node* next = tmp->next;
	while (next != NULL)
	{
		delete(tmp);
		tmp = next;
		next = tmp->next;
	}
	delete(tmp);
	delete(s);
}

void insert(SingleList* s, int v) {
	SingleList::Node* tmp = s->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = createNode(v);
}

SingleList::Node* find(SingleList* s, int v) {
	SingleList::Node* tmp = s->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->value == v)
			return tmp;
	}
	return nullptr;
}

void remove(SingleList* s, SingleList::Node* n) {
	SingleList::Node* tmp = s->head;
	SingleList::Node* pre = s->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp == n) {
			pre->next = tmp->next;
			delete(n);
			return;
		}
		pre = tmp;
	}
}

void remove(SingleList* s, int v) {
	SingleList::Node* tmp = s->head;
	SingleList::Node* pre = s->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->value == v) {
			pre->next = tmp->next;
			delete(tmp);
			tmp = pre;
		}
		pre = tmp;
	}
}

void print(SingleList* s) {
	SingleList::Node* tmp = s->head;
	while (1) {
		tmp = tmp->next;
		std::cout << tmp->value;
		if (tmp->next == NULL) {
			break;
		}
		std::cout << "->";
	}
	std::cout << std::endl;
}