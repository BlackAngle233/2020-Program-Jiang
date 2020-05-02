#pragma once

class LinkList
{
    private :
    struct Node
    {
        Node* next = nullptr;
        int value;
    };
    Node* head;
    int length;

    public :
    LinkList();
    LinkList(int m[], int len);
    ~LinkList();
    void erase();
    void insert(int v,int index);
    LinkList::Node* find(int v);
    void remove(LinkList::Node *node);
    void remove(int v);
    void print();
};
