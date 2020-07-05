#include <iostream>
#include "SingleList.h"

SingleList::Node* SingleList::createNode(int v) {
	SingleList::Node* result = new SingleList::Node();
	result->next = NULL;
	result->value = v;
	return result;
}

SingleList::SingleList(int num[], int size) {
	this->head = createNode(0);
	SingleList::Node* tmp = this->head;
	for (int i = 0; i < size; ++i) {
		tmp->next = createNode(num[i]);
		tmp = tmp->next;
	}
}

void SingleList::erase() {
	SingleList::Node* tmp = this->head;
	SingleList::Node* next = tmp->next;
	while (next != NULL)
	{
		delete tmp;
		tmp = next;
		next = tmp->next;
	}
	delete tmp;
	delete this;
}

void  SingleList::insert(int v) {
	SingleList::Node* tmp = this->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = createNode(v);
}

SingleList::Node* SingleList::find( int v) {
	SingleList::Node* tmp = this->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->value == v)
			return tmp;
	}
	return nullptr;
}

void SingleList::remove(SingleList::Node* n) {
	SingleList::Node* tmp = this->head;
	SingleList::Node* pre = this->head;
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

void SingleList::remove(int v) {
	SingleList::Node* tmp = this->head;
	SingleList::Node* pre = this->head;
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

void SingleList::print() {
	SingleList::Node* tmp = this->head;
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