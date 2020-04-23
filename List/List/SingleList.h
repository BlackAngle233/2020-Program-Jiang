#pragma once
#include <iostream>
using namespace std;
struct Node
{
	Node* next = nullptr;
	int value;
};
struct SingleList
{	
	Node* head;
};
SingleList creat(int a[], int len)
{
	SingleList* list = new SingleList();
	list->head = new Node();
	Node* head = list->head;
	for (int b = 0; b < len; b++)
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

void insert(int position, int num, SingleList list)
{
	Node* head = list.head;

	for (int a = 1; a < position; a++) {

		head = head->next;
	}
	Node* now = new Node();
	now->value = num;
	now->next = head->next;
	head->next = now;


}
void positionmove(int position, SingleList list) {
	Node* head = list.head;
	for (int a = 1; a < position; a++) {

		head = head->next;
	}
	head->next = head->next->next;
}

void numbermove(int num, SingleList list)
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
		cout << head->value <<"->";
	}
	cout << endl;
}

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能