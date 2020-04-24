#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include "SingleList.h"


using namespace std;
//生成链表
void create() {
	int len;
	int val;
	cout << "请输入链表长度：";
	cin >> len;
	singlelist.length = len;
	singlelist.head = (SingleList::Node*)malloc(sizeof(singlelist.node));
	singlelist.end = singlelist.head;
	for (int i = 0; i < len; i++)
	{
		singlelist.pnew= (SingleList::Node*)malloc(sizeof(singlelist.node));
		cout <<endl<< "请输入结点的值：";
		cin >> val;
		singlelist.pnew->value = val;
		singlelist.end->next = singlelist.pnew;
		singlelist.end = singlelist.pnew;
		singlelist.end->next = nullptr;
		//cout << singlelist.end->value << endl;
	}
}

//打印链表
void print() {
	cout << "此时链表中数据依次为：";
	singlelist.end = singlelist.head->next;
	do
	{
		cout << singlelist.end->value << " ";
		singlelist.pnew = singlelist.end->next;
		singlelist.end = singlelist.pnew;
	} while (singlelist.end->next != nullptr);
	cout << singlelist.end->value << " ";
}

//查询某一位置的值
void search() {
	int i,j=1;
	cout <<endl<< "请输入需要查询第几个位置的值：";
	cin >> i;
	cout << endl;
	singlelist.end = singlelist.head->next;
	if (i > singlelist.length) {
		cout << "超过链表长度";
	}
	else 
	{
		while (i>j) 
		{
			singlelist.pnew = singlelist.end->next;
			singlelist.end = singlelist.pnew;
			j++;
		}
		cout <<"查得值为："<< singlelist.end->value;
	}
}
//插入某一位置
void insert() {
	int i, j = 1,num;
	cout << endl << "请输入需要插入链表第几位置之后：";
	cin >> i;
	cout << endl << "请输入需要插入的值：";
	cin >> num;
	singlelist.end = singlelist.head->next;
	if (i > singlelist.length&&i<=0) 
	{
		cout << "非法位置";
	}
	else if (i == singlelist.length) 
	{
		for (int k = 1; k < i; k++)
		{
			singlelist.pnew = singlelist.end->next;
			singlelist.end = singlelist.pnew;
		}
		singlelist.pnew->value = num;
		singlelist.pnew->next = nullptr;
		singlelist.end->next = singlelist.pnew;
		singlelist.length++;
	}
	else
	{
		while (i > j)
		{
			singlelist.pnew = singlelist.end->next;
			singlelist.end = singlelist.pnew;
			j++;
		}
		singlelist.pnew = (SingleList::Node*)malloc(sizeof(singlelist.node));
		singlelist.pnew->value = num;
		singlelist.pnew->next = singlelist.end->next;
		singlelist.end->next = singlelist.pnew;
	}
}
//删除某一位置的值
void erase() {
	int i, j = 1,k=1;
	cout << endl << "请输入需要删除链表第几位置的值：";
	cin >> i;
	singlelist.end = singlelist.head->next;
	if (i > singlelist.length&&i <1) {
		cout << "非法位置";
	}
	else if (i == singlelist.length)
	{
		int l = i - 1;
		while (k < l )
		{
			singlelist.pnew = singlelist.end->next;
			singlelist.end = singlelist.pnew;
			k++;
		}
		singlelist.pnew = singlelist.end->next;
		singlelist.end->next = nullptr;
		free(singlelist.pnew);
		singlelist.length--;
	}
	else if (i == 1)
	{
		singlelist.head->next = singlelist.end->next;
		free(singlelist.end);
		singlelist.length--;
	}
	else
	{
		while (i > j+1)
		{
			singlelist.pnew = singlelist.end->next;
			singlelist.end = singlelist.pnew;
			j++;
		}
		singlelist.pnew = singlelist.end->next;
		singlelist.end->next = singlelist.pnew->next;
		free(singlelist.pnew);
		singlelist.length--;
	}
}
