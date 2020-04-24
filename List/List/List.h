#pragma once
#include"SingleList.h"

class List
{
public:
	List();
	~List();

	Node *create(int a[], int n);
	void print();
	void get(int i);
	void locate(int i);
	void insert(int i,int x);
	void remove_in_no(int i);
	void remove_in_data(int i);

private:
	Node *head;
};


