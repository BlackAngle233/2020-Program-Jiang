#include <iostream>
#include "SingleList.h"
using namespace std;


#include "SingleList.h"

MyList::MyList(void)
{
	m_phead = NULL;
	m_ptemp = NULL;
}


MyList::MyList(void)
{
	//DestroyList(m_phead);
}

void MyList::CreatList()
{
	m_phead = new Node;
	m_phead->next = NULL;
}

void MyList::InsertList(int nodedata)
{
	Node *t = new Node;
	t->next = m_phead->next;
	m_phead->next = t;
	t->data = nodedata;
}




Node * MyList::SearchList(int finddata)
{
	m_ptemp = m_phead;
	m_ptemp = m_ptemp->next;
	while (m_ptemp)
	{
		if (m_ptemp->data == finddata)
		{
			return m_ptemp;
		}
		m_ptemp = m_ptemp->next;
	}
	return NULL;
}

void MyList::RemoveList(Node * pfind)
{
	m_ptemp = m_phead;
	if (pfind->next == NULL)
	{
		while (m_ptemp->next != pfind)
			m_ptemp = m_ptemp->next;
		m_ptemp->next = pfind->next;
		delete pfind;
	}
	else
	{
		Node *t = pfind->next;
		pfind->data = t->data;
		pfind->next = t->next;
		delete t;
	}
}

void MyList::PrintList(Node *head)
{
	Node *p = NULL;
	while (head)
	{
		p = head;
		head = head->next;
		cout << p->data;
	}
}