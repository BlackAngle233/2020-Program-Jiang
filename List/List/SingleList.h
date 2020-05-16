#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	friend class LinkList;
	Node(int v, Node* n)
	{
		value = v;
		next = n;
	}
	int value;
	Node* next = nullptr;
};

class LinkList
{
private:
	Node* head;
public:
	LinkList()
	{
		head = nullptr;
	}

	LinkList(int a[], int len)
	{
		Node* p;
		head = new Node(-1, nullptr);
		p = head;
		for (int i = 0; i < len; i++)
		{
			p->next = new Node(a[i], nullptr);
			p = p->next;
		}
	}
	void erase() {
		Node* p;
		while (p != nullptr) {
			p = this->head;
			this->head = this->head->next;
			delete p;
		}
	}
	void insert(Node* n, int x) {
		Node* p;
		Node* q;
		p = this->head;
		q = this->head->next;
		if (n != nullptr) {
			while (q != nullptr) {
				if (q == n) break;
				p = q;
				q = q->next;
			}
		}
		p->next = new Node(x, q);
	}
	Node* find(int x) {
		Node* p;
		p = this->head->next;
		while (p != nullptr) {
			if (p->value == x) {
				return p;
			}
			p = p->next;
		}
		return p;
	}
	void remove(int x) {
		Node* p;
		p = this->head;
		while (p->next != nullptr) {
			if (p->value == x)
				p->next = p->next->next;
			else p = p->next;
		}
	}
	void remove(Node* n) {
		Node* p;
		p = this->head;
		while (p->next != nullptr) {
			if (p == n)
				p->next = p->next->next;
			else p = p->next;
		}
	}
	void print() {
		Node* p;
		p = this->head->next;
		while (p != nullptr)
		{
			std::cout << p->value << "->" << "";
			p = p->next;
		}
		std::cout << "" << endl;
	}
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能