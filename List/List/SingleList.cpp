#include <iostream>
#include "SingleList.h"
using namespace std;
SingleList SingleList::create(int * a)
{
	SingleList *list = new SingleList();
	list->head = new Node();
	Node*head = list->head;
	for (int b = 0; b<=sizeof(a)/sizeof(a[0]); b++) {
		
		
		
		head->next = new Node();
		head->next->value = a[b];
		head = head->next;
		
	}
	return *list;
}

int SingleList::find(int num,SingleList list)
{
	Node*head = list.head;
	for (int a = 1; a < num; a++) {

		head = head->next;
	}
	return head->next->value;
}

void SingleList::insert(int pos, int num,SingleList list)
{
	Node*head = list.head;
	
	for (int a = 1; a < pos; a++) {
	
		head = head->next;
	}
	Node*now = new Node();
	now->value = num;
	now->next = head->next;
	head->next = now;
	

}
void SingleList::removepos(int pos, SingleList list) {
	Node*head = list.head;
	for (int a = 1; a < pos; a++) {

		head = head->next;
	}
	head->next = head->next->next;
}

void SingleList::removenum(int num, SingleList list)
{
	Node*head = list.head;
	
	while (head->next != nullptr) {
		
		if (head->next->value == num) {
		

			break;
		}
		head = head->next;
	}
	head->next = head->next->next;
	
}

void SingleList::print(SingleList list)
{
	Node*head = list.head;

	while (head->next != nullptr) {
		head = head->next;
		cout << head->value << endl;
	}
}

SingleList::~SingleList()
{
	

	while (head->next != nullptr) {
		delete[] head;
		head = head->next;
		
	}
}


