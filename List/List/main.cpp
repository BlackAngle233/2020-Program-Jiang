
#include <iostream>
using namespace std;

struct LinkList
{
	struct Node
	{
		Node *next = nullptr;
	};
	Node* head;
	Node* next;
	int value;
};

LinkList* creat(int a[], int len)
{
	LinkList *head = NULL;
	LinkList *tail = NULL;
	LinkList *add = NULL;
	for (int i = 0; i < len; ++i)
	{
		LinkList *add = new LinkList(a[i]);
		if (tail != NULL)
		{
			tail->next = add;
			tail = add;
		}
		else
		{
			head = tail = add;
		}
	}
	return head;
}

void erase(LinkList *&L, int len, int e)
{
	int j = 0;
	LinkList *p = L, *q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		false;
	else
	{
		q = p->next;
		if (q == NULL) false;
		e = q->value;
		p->next = q->next;
		free(q);
	}
}

void insert(LinkList* list, int num)
{
	int j = 0;
	LinkList *p = list, *s;
	while (j < num - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		false;
	else
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->value = num;
		s->next = p->next;
		p->next = s;
	}
}

LinkList::Node* find(LinkList *L, int len, int e)
{
	int j = 0;
	LinkList *p = L;
	while (j < len && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
	{
		e = p->value;
	}
}

void remove(LinkList *&L, int len, int e)
{
	int j = 0;
	LinkList *p = L, *q;
	while (j < len - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		false;
	else
	{
		q = p->next;
		if (q == NULL) false;
		e = q->value;
		p->next = q->next;
		free(q);
	}
}

void remove(LinkList* list)
{

}

void print(LinkList* list, int len)
{
	for (int i; i < len; i++)
	{
		cout << list->value << "  ";
	}
}

int main()
{
	int a[] = { 1,2,3,4,5,7 };
	LinkList *L;
	L = creat(a, 6);
	erase(L, 3, 4);
	insert(L, 3);
	find(L, 6, 2);
	remove(L, 6, 5);
	print(L, 6);

}
