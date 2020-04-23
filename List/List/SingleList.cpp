/*#include <iostream>
#include "SingleList.h"
using namespace std;
SingleList creat(int a[], int len)
{
	SingleList* list = new SingleList();
	list->head = new Node();
	Node* head = list->head;
	for (int b = 0; b <len; b++) 
    {
		head->next = new Node();
		head->next->value = a[b];
		head = head->next;
	}
	return *list;
}
int find(int num, SingleList list)
{
	Node* head = list.head;
	for (int a = 1; a < num; a++) {

		head = head->next;
	}
	return head->next->value;
}

void insert(int pos, int num, SingleList list)
{
	Node* head = list.head;

	for (int a = 1; a < pos; a++) {

		head = head->next;
	}
	Node* now = new Node();
	now->value = num;
	now->next = head->next;
	head->next = now;


}
void removepos(int pos, SingleList list) {
	Node* head = list.head;
	for (int a = 1; a < pos; a++) {

		head = head->next;
	}
	head->next = head->next->next;
}

void removenum(int num, SingleList list)
{
	Node* head = list.head;

	while (head->next != nullptr) {

		if (head->next->value == num) {


			break;
		}
		head = head->next;
	}
	head->next = head->next->next;

}

void print(SingleList list)
{
	Node* head = list.head;

	while (head->next != nullptr) {
		head = head->next;
		cout << head->value << endl;
	}
}*/