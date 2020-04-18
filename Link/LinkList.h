#pragma once
typedef struct LinkList
{
    struct Node
    {
        Node* next = nullptr;
        int value;
    };
    Node* head;
    int length;
};
LinkList* create(int m[],int len);
void erase(LinkList*& list);
void insert(LinkList* list,int v,int index);
LinkList::Node* find(LinkList* list , int v);
void remove(LinkList::Node* node);
void remove(LinkList* list,int v);
void print(LinkList* list);
