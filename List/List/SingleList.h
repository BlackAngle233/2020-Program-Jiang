#pragma once
#include<iostream>
#define LEN sizeof(struct SingleList)
int n = 0;

using namespace std;

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;

	Node *creat()
	{
		Node *p1,*p2;
		head = new Node;
		p1 = head;
		int input = 1;
		while (input)
		{
			cout << "输入数据，输入0以退出: ";
			cin >> input;

			if (input != 0)
			{
				p2 = new Node;
				p2->value = input;
				cout << "数据: " << input << "已输入" <<  endl;
				p1->next = p2;
				p1 = p2;
			}
			else
			{
				cout << "Input done! " << endl;
			}
		}
		head = head->next;
		p1->next = NULL;
		return head;
	}

	int length(Node *head)
	{
		int count = 0;
		Node *p1 = head;
		while (p1 != NULL)
		{
			p1 = p1->next;
			count++;
		}

		return count;
	}

	void erase(Node *head)
	{
		Node *p1 = head;
		Node *p2 = head;
		while (p1 != NULL)
		{
			p2 = p1;
			p1 = p1->next;
			delete p2;
		}
	}

	void *insert(Node *head, int num,int position)
	{
		int count = 0;
		Node *p0, *p1, *p2;
		p1 = head;
		p2 = p1;
		p0 = new Node;
		p0->value = num;

		if(position == 0)
		{
			head = p0;
			head->next = p1;
		}
		else if (position = length(head))
		{
			while (count != position)
			{
				p1 = p1->next;
				p2 = p1;
			}
			p1->next = p0;
			p0->next = NULL;
		}
		else
		{
			while (count != position)
			{
				p1 = p1->next;
				p2 = p1;
				count++;
			}
			p1 = p1->next;
			p2->next = p0;
			p0->next = p1;
		}
	}

	Node *find(int num)
	{
		Node *p1 = head;
		while (p1->value != num)
		{
			p1 = p1->next;
		}

		return p1;
	}

	void remove(Node *head, int num)
	{
		Node *p1, *p2;
		p1 = head;
		p2 = p1->next;
		if (p1->value == num)
		{
			delete p1;
			head = p2;
		}
		else
		{
			while (p2->value != num)
			{
				p1 = p2;
				p2 = p2->next;
			}
			p2 = p2->next;
			delete p1->next;
			p1->next = p2;
		}
		
	}

	void print(Node *head)
	{
		Node *p1 = head;
		while (p1 != NULL)
		{
			cout << p1->value << " " << endl;
			p1 = p1->next;
		}
	}


};


//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能