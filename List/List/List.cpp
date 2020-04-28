// List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE * next;
};
class List
{
	NODE * head;
public:
	
	List() { head = new NODE; head->next = NULL; }  
	void CreatList1(int n);        
	void Insert(int i, int e);     
	void Delete(int i);             
	int ChangeData(int i);   
	void OutputList();
	NODE * Gethead() { return head->next; }    
};
void List::CreatList1(int n)
{
	NODE * p;
	NODE *temp;
	p = head;
	cout << "请依次输入" << n << "个链表的值:";
	for (int i = 1; i <= n; i++) {
		temp = (NODE*)new(NODE);	
		cin >> temp->data;
		temp->next = p->next;
		p->next = temp;
	}
}
void List::OutputList()
{
	NODE * current = head->next;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
void List::Insert(int i, int e) {
	NODE *temp;
	temp = head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "插入位置错误";
	}
	else {
		NODE *s;
		s = new NODE;
		s->data = e;
		s->next = temp->next;
		temp->next = s;
	}
}
void List::Delete(int i) {
	NODE *temp;
	temp = head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "删除位置错误";
		return;
	}
	else {
		NODE *s;
		s = temp->next;
		temp->next = s->next;
		delete s;
	}
}
int List::ChangeData(int i) {
	NODE *temp;
	temp = head;
	int j = 0;
	int x;
	cout << "输入要修改的值：";
	cin >> x;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "寻找位置错误" << endl;
		return -1;
	}
	else {
		temp->next->data = x;
		return temp->next->data;
	}
}
int main()
{
	int num1;
	List list1;

	cout << "请输入链表1长度：";
	cin >> num1;
	list1.CreatList1(num1);
	cout << "头插法创建链表1：";
	list1.OutputList();
	list1.Insert(3, 22);
	cout << "在3位置插入22后为：";
	list1.OutputList();
	list1.Delete(1);
	cout << "删除1位置处的元素后为：";
	list1.OutputList();
	list1.ChangeData(2);
	cout << "修改后的列表为：";
	cout << endl;
}
