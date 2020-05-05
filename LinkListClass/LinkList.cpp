#include"LinkList.h"
#include<iostream>

Node::Node(int v) {
	val = v;
	next = nullptr;
}
Node::~Node() {
	delete(next);
}
void LinkList::create() {
	head = new Node(0);
	listNum = 0;
}
LinkList::LinkList(int& nums,int size) {
	create();
	int i = 0;
	for (;i < size;i++) {
		insert(nums+i);
	}
}
LinkList::~LinkList() {
	Node* item = head;
	Node* next = head->next;
	while (next) {
		delete(item);
		item = next;
		next = item->next;
	}
}
Node LinkList::find(int v) {
	Node* item = head;
	Node* next = item->next;
	while (next) {
		if (next->val == v)
			return *next;
		item = next;
		next = item->next;
	}
	return NULL;
}
void LinkList::insert(int v) {
	Node* item = head;
	Node* next = item->next;
	while (next) {
		item = next;
		next = item->next;
	}
	next = new Node(v);
	next->next = nullptr;
	listNum++;
}
void LinkList::remove(int v) {
	Node* item = head;
	Node* next = item->next;
	while (next) {
		if (next->val == v) {
			item->next = next->next;
			delete(next);
		}
		item = next;
		next = item->next;
	}
}
void LinkList::show() {
	Node* item = head;
	Node* next = item->next;
	while (next) {
		std::cout << next->val;
		if (next->next != nullptr)
			std::cout << "->";
	}
	std::cout << std::endl;
}