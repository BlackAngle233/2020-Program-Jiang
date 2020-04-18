#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
struct LinkList {
	T data;
	LinkList<T> *next;
};
template<class T>
class LinkListClass {

public:
	LinkList<T> *head;
	LinkListClass<T>();
	~LinkListClass<T>();
	void CreatListR(T a[], int n);//β�巨��������
	void DispList();//չʾ����
	int ListLength();//����ǰ����
	bool GetElem(int i, T &e);//�õ���e����������
	int LocateElem(T e);//�õ�����Ϊe�Ľ��λ��
	bool ListInsert(T e, int i);//��iλ�ò���һ������Ϊe�Ľ��
	bool ListDelete(int i);//ɾ��i���
};
template<class T>
LinkListClass<T>::LinkListClass()
{
	head = new LinkList<T>();
	head->next = NULL;
}
template<class T>
LinkListClass<T>::~LinkListClass()
{
	LinkList<T> *p, *pre;
	int x = 1;
	pre = head;
	p = pre->next;
	while (p != NULL)
	{
		delete pre;
		x++;
		cout << x << endl;
		pre = p;
		p = p->next;
	}
	delete pre;
	x++;
	cout << x << endl;
}
template<class T>
void LinkListClass<T>::CreatListR(T a[], int n)
{
	LinkList<T> *s, *r;
	int i;
	r = head;
	for (i = 0; i < n; i++)
	{
		s = new LinkList<T>();
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
}
template<class T>
void LinkListClass<T>::DispList()
{
	LinkList<T> *p;
	p = head->next;
	while (p != NULL)
	{

		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
template<class T>
int LinkListClass<T>::ListLength()
{
	int i = 0;
	LinkList<T> *p;
	p = head;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);

}
template<class T>
bool LinkListClass<T>::GetElem(int i, T & e)
{
	int j = 0;
	LinkList<T> *p;
	p = head;
	while (j < i&&p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}

	return false;
}
template<class T>
int LinkListClass<T>::LocateElem(T e)
{
	LinkList<T> *p;
	p = head;
	int i = 0;
	while (p != NULL)
	{
		i++;
		if (p->data == e)
			return (i-1);
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "�������������" << endl;
	}
	return 0;
}
template<class T>
bool LinkListClass<T>::ListInsert(T e, int i)
{
	LinkList<T> *p, *s;
	int j = 1;
	p = head;
	while (j < i&&p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = new LinkList<T>();
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
template<class T>
bool LinkListClass<T>::ListDelete(int i)
{
	int j = 1;
	LinkList<T> *p, *q;
	p = head;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	q = p->next;
	p->next = q->next;
	delete q;
	return true;
}



