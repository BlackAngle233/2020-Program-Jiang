#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{

}
LinkList::LinkList(int m[], int len)
{
    length = len;
    head = new LinkList::Node;
    LinkList::Node *cur;
    cur = head;
    for (int i = 0; i < len; i++)
    {
        cur->next = new LinkList::Node;
        cur->next->value = m[i];
        cur = cur->next;
    }
}
LinkList::~LinkList()
{

}

void LinkList::erase()
{
    LinkList::Node *cur = head->next;
    LinkList::Node *temp;
    while (cur != nullptr)
    {
        temp = cur;
        cur = cur->next;
        delete temp;
    }
    head->next = nullptr;
}

void LinkList::insert(int v, int index)
{
    if ((length + 1) < index || index < 0)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        LinkList::Node *cur = new LinkList::Node;
        cur = head;
        LinkList::Node *next = new LinkList::Node;
        LinkList::Node *newNode = new LinkList::Node;
        (*newNode).value = v;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        next = cur->next;
        cur->next = newNode;
        newNode->next = next;
        length += 1;
    }
}
LinkList::Node* LinkList::find(int v)
{
    LinkList::Node *cur = head->next;
    while (cur != nullptr)
    {
        if (cur != nullptr)
        {
            if (cur->value == v)
            {
                cout << cur->value << endl;
                return cur;
            }
        }
        cur = cur->next;
    }
    return cur;
}
void LinkList::remove(LinkList::Node *node)
{
    LinkList::Node *cur = head->next;
    LinkList::Node *pre = head;
    while (cur != nullptr)
    {
        if (cur != node)
        {
            cur = cur->next;
            pre = pre->next;
            continue;
        }
        else
        {
            if (cur->next != nullptr)
                pre->next = cur->next;
            else
            {
                pre->next = nullptr;
            }
            delete cur;
            break;
        }
    }
}
void LinkList::remove(int v)
{
    LinkList::Node *cur = head->next;
    LinkList::Node *pre = head;
    while (cur != nullptr)
    {
        if (cur->value != v)
        {
            cur = cur->next;
            pre = pre->next;
            continue;
        }
        else
        {
            if (cur->next != nullptr)
                pre->next = cur->next;
            else
            {
                pre->next = nullptr;
            }
            delete cur;
            cur = pre->next;
        }
    }
}
void LinkList::print()
{
    if (head->next != nullptr)
    {
        LinkList::Node *cur = new LinkList::Node;
        cur = head->next;
        while (cur != nullptr)
        {
            cout << cur->value;
            cur = cur->next;
            if (cur != nullptr)
                cout << "->";
        }
        cout << endl;
    }
    else
    {
        cout<<"Null";
    }
    
}