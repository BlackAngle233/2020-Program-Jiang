//
//  main.cpp
//  homework03
//
//  Created by 章大卫 on 2020/4/21.
//  Copyright © 2020 章大卫. All rights reserved.
//

#include <iostream>

using namespace std;

struct LinkList{
    struct Node{
        Node* next =nullptr;
        int value;
    };
    Node* head;
};
int length (LinkList m){
    int n = 0;
    LinkList::Node *p = m.head->next;
    while(p != nullptr ){
        p= p->next;
        n++;
    }
    return n;
}
void insert(LinkList* list ,int v){
    LinkList::Node s;
    s.value=v;
    s.next=list->head->next;
    list->head->next=&s;
}
//{1,2,3,4,5,4}
LinkList* create(int m[], int len){
    LinkList *p = nullptr;
    
    for(int i=0;i<len;i++){
        insert(p, m[i]);
    };
    return p;
}

void erase(LinkList* p){
    p->head->next=NULL;
}



LinkList::Node* find(int v,LinkList* list){
    LinkList::Node* a ;
    a=list->head->next;
    while (a != NULL){
        if (a->value == v) {
         return a;
        }
        a=a->next;
    }
    return NULL;
}

void remove(LinkList::Node* node,LinkList list){
    LinkList::Node* a ;
    a=list.head->next;
    while (a->next != NULL&&a->next->next != NULL){
        if (a->next == node) {
            a->next=a->next->next;
        }
    }
}
void remove(LinkList* list,int v){
    LinkList::Node* a ;
    a=list->head->next;
    while (a->next != NULL&&a->next->next != NULL){
        if (a->next->value == v) {
            a->next=a->next->next;
        }
    }
}


void printL(LinkList *head){
    LinkList::Node* a ;
    a=head->head->next;
    while (a != NULL){
        cout << a->value <<endl;
        a=a->next;
    }
}
void print(LinkList* list);
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
