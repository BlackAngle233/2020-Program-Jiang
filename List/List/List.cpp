#include "List.h"
using namespace std;

List::List()
{
	head = new Node;
	head->next = NULL;
}

List::~List()
{
	Node *p;
	p = new Node;
	while (head!=NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

Node *List::create(int a[], int n)
{
	Node *r;
	r = new Node;
	head = new Node;
	r = head;
	for (int i = 0; i < n; i++) {
		Node *s;
		s = new Node;
		s->value = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void List::print()
{
	Node *p;
	p = new Node;
	p = head->next;
	while (p != NULL) {
		cout << p->value << " ";
		p = p->next;
	}

}

void List::get(int i)
{
	Node *p;
	p = new Node;
	p = head;
	int count = 0;
	while (count != i && p->next != NULL) {
		p = p->next;
		count++;
	}
	if (p != NULL) {
		cout << p->value;
	}
	else
	{
		cout << "cannot find this number" << endl;
	}
}

void List::locate(int i)
{
	Node *p;
	p = new Node;
	p = head;
	int count = 0;
	while (p->value != i && p != NULL) {
		p = p->next;
		count++;
	}
	if (p != NULL) {
		cout << count << ":" << i << endl;
	}
	else
	{
		cout << "cannot find this number" << endl;
	}
}
void List::insert(int i, int x)
{
	Node *p, *s;
	p = new Node;
	s = new Node;
	s->value = x;
	p = head;
	int count = 0;
	while (count != i - 1 && p != NULL)
	{
		p = p->next;
		count++;
	}
	if (p != NULL)
	{
		s->next = p->next;
		p->next = s;
	}
	else
	{
		cout << "error location" << endl;
	}
}

void List::remove_in_no(int i)
{
	Node *p,*s;
	p = new Node;
	s = new Node;
	p = head;
	int count = 0;
	while (count != i-1 && p != NULL)
	{
		p = p->next;
		count++;
	}
	if (p != NULL)
	{
		s = p->next;
		p->next = p->next->next;
		delete s;
	}
	else
	{
		cout << "error location" << endl;
	}
}

void List::remove_in_data(int i)
{
	Node *p,*s;
	p = new Node;
	s = new Node;
	p = head;
	int count = 0;
	while (p->value != i && p != NULL) {
		p = p->next;
		count++;
	}
	if (p != NULL)
	{
		s = p->next;
		p->next = p->next->next;
		delete s;
	}
	else
	{
		cout << "error number" << endl;
	}
}