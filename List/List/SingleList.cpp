#include <iostream>
#include "SingleList.h"
using namespace std;

SingleList::SingleList() {
	head = new Node;
	head->value = 0;
	head->next = nullptr;
}

int SingleList::Len() {
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
		cout << "输入有误" << endl;
		exit(-1);
	}
	for (int i = 0; i < size; i++) {
		anew = new Node;
		cout << "输入第" << i + 1 << "个值" << endl;
		cin >> anew->value;
		anew->next = nullptr;
		anow->next = anew;
		anow = anew;
	}
}

void SingleList::EraseSingleList(){
	delete head;
}

void SingleList::Insert(int value, int n) {
	if (n<1 || n > Len()) {
		cout << "输入错误" << endl;
	}
	else {
		Node* anow = new Node;
		anow->value = value;
		Node* a = head;
		int i = 1;
		while(n > 1) {
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
		cout << "空链表啊兄弟" << endl;
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

void SingleList::Print(){
	if (head == nullptr && head->next == nullptr) {
		cout << "空链表啊兄弟" << endl;
	}
	Node* a = head;
	while (a->next != nullptr) {
		a = a->next;
		cout << a->value << endl;
	}
}