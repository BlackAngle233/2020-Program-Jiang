#include <iostream>
#include "SingleList.h"
using namespace std;

SingleList::SingleList() {
	head = new Node;
	head->value = 0;
	head->next = nullptr;
}

int SingleList::Length() {
	int size = 0;
	Node* p = head->next;
	while (p != nullptr) {
		size++;
		p = p->next;
	}
	return size;
}

int SingleList::CreateSingleList(int size) {
	Node* anow, * anew;
	anow = head;
	if (size < 0) {
		cout << "error" << endl;
		exit(-1);
	}
	for (int i = 0; i < size; i++) {
		anew = new Node;
		cout << "input value" << i + 1 << endl;
		cin >> anew->value;
		anew->next = nullptr;
		anow->next = anew;
		anow = anew;
	}
}

void SingleList::EraseSingleList() {
	delete head;
}

void SingleList::Insert(int value, int n) {
	if (n<1 || n > Length()) {
		cout << "error" << endl;
	}
	else {
		Node* anow = new Node;
		anow->value = value;
		Node* a = head;
		int i = 1;
		while (n > 1) {
			a = a->next;
			i++;
		}
		anow->next = a->next;
		a->next = anow;
	}
}

Node* SingleList::Find(int value) {
	Node* a = head;
	if (a == nullptr) {
		cout << " empty list" << endl;
		return nullptr;
	}
	else {
		while (a->next != nullptr) {
			if (a->value == value) {
				return a;
			}
			a = a->next;
		}
	}
	if (a->value == value) {
		return a;
	}
	else {
		return nullptr;
	}
}

void SingleList::Remove(int value) {
	Node* anow = Find(value);
	Node* a = head;
	while (a->next != anow) {
		a = a->next;
	}
	a->next = anow->next;
	delete anow;
	anow = nullptr;
}

void SingleList::Print() {
	if (head == nullptr && head->next == nullptr) {
		cout << "This is an empty list" << endl;
	}
	Node* a = head;
	while (a->next != nullptr) {
		a = a->next;
		cout << a->value << endl;
	}
}