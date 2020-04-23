#include <iostream>
#include "SingleList.h"

using namespace std;
SingleList::SingleList() {
	Node *t = new Node;
	head = t;
}
void SingleList::create() {
	/*Node temp;
	temp.value = value;
	this->head->next = &temp;*/
	Node *h = head;
	cout << "输入数字 第一个数字为长度\n";

	int num;
	cin >> num;
	for(int i =0;i <num;i++)
	{
		int temp;
		cin >> temp;
		Node *t = new Node;
		t->value = temp;
		h->next = t;
		h = t;
	}
}
void SingleList::erase() {
	head->next = nullptr;
}
void SingleList::insert(int index,int value) {
	Node* temp = new Node;
	temp->value = value;
	Node* n = head;
	
	for (int i = 0; i < index; i++) {
		if (n->next == nullptr) {
			break;
		}
		n = n->next;
	}
	temp->next = n->next;
	n->next = temp;
	
	
}
bool SingleList::find(int value) {
	Node* n = head->next;
	while (n != nullptr) {
		if (n->value == value) {
			return true;
		}
		n = n->next;
	}
	return false;
}
void SingleList::remove(int index) {
	Node* n = head;

	for (int i = 0; i < index; i++) {
		if (n->next == nullptr) {
			return;
		}
		n = n->next;
	}
	n->next = nullptr;
	
}
void SingleList::remove(Node* node) {
	Node* n = head->next;
	while (n != nullptr) {
		if (n->next == node) {
			n->next = node->next;
			return;
		}
		n = n->next;
	}
	return;
}
void SingleList::print() {
	Node *n = head->next;
	while (n != nullptr)
	{
		cout << n->value<<" ";
		n = n->next;
	}
}