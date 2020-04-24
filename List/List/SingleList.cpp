
#include "SingleList.h"
#include<iostream>

using namespace std;

template<class T>
int SingleList<T>::length()const
{
    return listsize;
}

template<class T>
void SingleList<T>::Insert(const T& item)
{
    currptr->next = new SLNode<T>(item, currptr->next);
    if (tail == currptr)
        tail = currptr->next;
    listsize++;
}

template<class T>
void SingleList<T>::InsertHead(const T& item)
{
    if (IsEmpty())
    {
        head->next = new SLNode<T>(item, head->next);
        tail = head->next;
    }
    else {
        head->next = new SLNode<T>(item, head->next);
    }
    listsize++;
}

template<class T>
void SingleList<T>::InsertTail(const T& item)
{
    tail->next = new SLNode<T>(item, nullptr);
    tail = tail->next;
    listsize++;
}

template<class T>
void SingleList<T>::Erase()
{
    if (currptr == tail || IsEmpty())
    {
        cout << "No next node or empty list!";
    }
    SLNode<T>* temp = currptr->next;
    currptr->next = temp->next;
    listsize--;
    if (temp == tail) tail = currptr;
    delete temp;
}

template<class T>
void SingleList<T>::EraseHead()
{
    if (IsEmpty())
    {
        cout << "Empty list!";
    }
    SLNode<T>* temp = head->next;
    head->next = temp->next;
    listsize--;
    if (temp == tail) tail = head;
    delete temp;
}

template<class T>
void SingleList<T>::EraseTail()
{
    if (IsEmpty())
    {
        cout << "Empty list!";
    }
    while (currptr->next != tail)
    {
        currptr = currptr->next;
    }
    currptr->next = nullptr;
    listsize--;
    delete tail;
    tail = currptr;
}

template<class T>
void SingleList<T>::Find(int k)const
{
    SLNode<T>* temp = head->next;
    int i = 1;
    if (k > listsize)
        cout << "The number k is wrong!" << endl;
    else
    {
        while (temp != nullptr && i < k)
        {
            temp = temp->next;
            i++;
        }
        cout << "The " << k << "th item is " << temp->data << endl;
    }

}

template<class T>
int SingleList<T>::FindNow()const
{
    return currptr->data;
}

template<class T>
void SingleList<T>::Search(int x)const
{
    SLNode<T>* temp = head;
    int position = 0;
    for (int i = 1; i <= listsize; ++i)
    {
        temp = temp->next;
        if (temp->data == x)
        {
            position = i;
            break;
        }
    }
    if (position == 0)
    {
        cout << "There isn't a " << x << " in the list!" << endl;
    }
    else cout << "The " << x << "\'s position is " << position << "!" << endl;
}

template<class T>
void SingleList<T>::Print()
{
    for (SLNode<T>* temp = head->next; temp; temp = temp->next)
    {
        cout << "[" << temp->data << "]";
        if (temp->next != nullptr)
            cout << "->";
    }
    cout << endl << "The listsize is " << listsize << endl;
}