#pragma once
#include <iostream>

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;

    static Node* Create(Node *&head,int value) //CreateOneNode
    {
        if(head == nullptr)
        {
            head = new Node();
            if(head == nullptr) return nullptr; 
            else
            {
                head -> value = value;
                return head; 
            }
        }
        else return head; 
    }

    static void Erase(Node *head) //delete all nodes of the linklist
    {
        Node *p, *q;
        p = head;
        q = head;

        while(p != nullptr)
        {
            p = p -> next;
            if(q != nullptr) delete(q);
            q = p;
        }
    }

    static int Delete(Node *head, int key) //delete node with given key except head node
    {
        Node *p = head;
        Node *q = nullptr;
        while(p != nullptr)
        {
            if(p -> value == key)
            {
                if(q != nullptr) q -> next = p -> next;
                else return -1;
                delete(p);
                return 1;
            }
            q = p;
            p = p -> next;
        }
        return -1;
    }

    static int Insert(Node *head, int key,int value)
    {
        Node *p = Find(head, key);
        Node *q = nullptr;
        if(p == nullptr) return -1;
        else
        {
            q = new Node();
            if(q == nullptr) return -1;
            else
            {
                q -> value = value;
                q -> next = p -> next;
                p -> next = q;
                return 1;
            }
        }
   }

    static Node* Find(Node *head, int key)
    {
        Node *p = head;
        while(p -> value != key && p != nullptr)
        {
            if(p == nullptr) return nullptr; //靠靠靠靠
            else 
            {
                return p;
            }
            p = p -> next;
        }
    }

    static void print(Node *head)
    {
        Node *p = head;
        while(p != nullptr)
        {
            std::cout << p -> value;
            p = p -> next;
            if(p != nullptr) std::cout << "->";
        }
        std::cout << std::endl;
    }
};

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能

