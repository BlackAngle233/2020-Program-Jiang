#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList *create(int m[], int len)
{
    LinkList *linkList = new LinkList;
    linkList->length = len;
    linkList->head = new LinkList::Node;
    LinkList::Node *cur;
    cur = linkList->head;
    for (int i = 0; i < len; i++)
    {
        cur->next = new LinkList::Node;
        cur->next->value = m[i];
        cur = cur->next;
    }
    return linkList;
}
void erase(LinkList *&list)
{
    LinkList::Node *cur = list->head;
    LinkList::Node *temp;
    while (cur != nullptr)
    {
        temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete list;
    list = nullptr;
}
void insert(LinkList *list, int v, int index)
{
    if (((*list).length + 1) < index || index < 0)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        LinkList::Node *cur = new LinkList::Node;
        cur = list->head;
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
        list->length += 1;
    }
}
LinkList::Node *find(LinkList *list, int v)
{
    LinkList::Node *cur = list->head->next;
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
void remove(LinkList *list, LinkList::Node *node)
{
    LinkList::Node *cur = list->head->next;
    LinkList::Node *pre = list->head;
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
        }
    }
}
void remove(LinkList *list, int v)
{
    LinkList::Node *cur = list->head->next;
    LinkList::Node *pre = list->head;
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
void print(LinkList *list)
{
    if (list != nullptr)
    {
        LinkList::Node *cur = list->head->next;
        while (cur != nullptr)
        {
            cout << cur->value;
            cur = cur->next;
            if (cur != nullptr)
                cout << "->";
        }
        cout << endl;
    }
}