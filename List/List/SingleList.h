#pragma once

#include<iostream>
struct Node
{
	Node* next = nullptr;
	int value;
};
Node* head=new Node;

Node* creatList(int n) {
	Node* q = head;
	for (int j = 0; j < n; j++) {
		Node* p = q->next;
		std::cin >> p->value;
		q = p;
	}
	return head;
}
void eraseList(Node*L) {
	Node* q = L->next;
	while (q->next != nullptr){
		Node* p = q->next;
		delete(q);
		q = p;
	}
	delete(L);
}

void insertList(Node*L, int n, int v) {
	Node*q = L;
	for (int j = 0; j < n; j++) {
		L = L->next;
	}
	L->value = v;
}

Node* findList(Node*L, int n) {
	Node*q = L;
	for (int j = 0;j < n;j++) {
		q = q->next;
	}
	return q;
}
void removeList(Node*L, int n) {
	Node*q = L;
	Node*p = L->next;
	for (int j = 0; j < n-1; j++) {
		q = q->next;
		p = p->next;
	}
	q->next = p->next;
	delete(p);
}

void printList(Node*L) {
	Node*q = L;
	while (q->next != nullptr) {
		q=q->next;
		std::cout << q->value<<" ";
	}
}

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能