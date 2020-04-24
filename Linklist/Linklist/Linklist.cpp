#include <iostream>
#include<string>
#include"LinkList.h"
using namespace std;

Linklist::Linklist() {
	head = new Node;
	head->data = 0;
	head->next = NULL;
	size = 0;
}

Linklist::~Linklist() {
	delete head;
}

int Linklist::createList(int s) {
	if (s < 0) {
		cout << "error size" << endl;
		return -1;
	}
	Node *pcur = NULL;
	Node *pnew = NULL;
	this->size = s;
	pcur = this->head;
	for (int i = 0; i < s; i++) {
		pnew = new Node;
		pnew->next = NULL;
		cout << "Please input No." << i + 1 << " Node:";
		cin >> pnew->data;
		pcur->next = pnew;
		pcur = pnew;
	}
	cout << "Create successfully!" << endl;
	return 0;
}

int Linklist::insertNode(Node *d,int n) {//插在第n个节点后面
	Node *pcur;
	if (this->head == NULL) {
		cout << "Linklist is null." << endl;
		return -1;
	}
	if (d = NULL) {
		cout << "The node inserted is NULL." << endl;
		return -1;
	}
	if (n < this->size) {
		pcur = this->head;
		for (int i = 0; i < n; i++) {
			pcur = pcur->next;
		}
		Node *pnew = new Node;
		pnew->data = d->data;
		pnew->next = pcur->next;
		pcur->next = pnew;
		this->size++;
		return 0;
	}
	else {
		pcur = this->head;
		while (pcur->next != NULL) {
			pcur = pcur->next;
		}
		Node *pnew = new Node;
		pnew->data = d->data;
		pnew = NULL;
		pcur->next = pnew;
		this->size++;
		return 0;
	}
}

int Linklist::deleteNode(int n) {//删除第n个节点
	Node *pfor;
	Node *pcur;
	if (n > this->size) {
		cout << "error num！cannot insert！" << endl;
		return -1;
	}

	if (n == this->size) {
		pfor = this->head;
		for (int i = 0; i < n - 1; i++) {
			pfor = pfor->next;
		}
		pcur = pfor->next;
		pfor->next = NULL;
		delete pcur;
		this->size--;
		return 0;
	}
	else{
		pfor = this->head;
		for (int i = 0; i < n-1; i++) {
			pfor = pfor->next;
		}
		pcur = pfor->next;
		pfor->next = pcur->next;
		delete pcur;
		this->size--;
		return 0;
	}
}

void Linklist::printList(){
	Node *pcur = new Node;
	pcur = this->head;
	cout << "The Linklist is:" << endl;
	for (int i = 1; i <= this->size; i++) {
		pcur = pcur->next;
		if (i==this->size) {
			cout << pcur->data << endl;
		}
		else { cout << pcur->data << "->"; }
	}
}

int main() {
	Linklist list;
	Linklist *plist = &list;
	int lsize;
	int num;
	cout << "Input the size of Linklist:";
	cin >> lsize;
	plist->createList(lsize);
	plist->printList();
	Node pnode;
	Node *inNode=&pnode;
	cout << "Input the data of Node inserting:";
	//cin >> pnode.data;
	//pnode.next = NULL;
	cin >> inNode->data;
	inNode->next = NULL;
	cout << "Input the number of Node inserting after:";
	cin >> num;
	//plist->insertNode(&pnode, num);
	plist->insertNode(inNode, num);
	plist->printList();
	cout << "Input the number of Node deleting:";
	cin >> num;
	plist->deleteNode(num);
	plist->printList();
	return 0;
}