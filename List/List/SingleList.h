
#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED
template<class T>

struct SLNode
{
    T data;
    SLNode<T>* next;
    SLNode(SLNode* nextNode = nullptr)
    {
        next = nextNode;
    }
    SLNode(const T& item, SLNode* nextNode = nullptr)
    {
        data = item;
        next = nextNode;
    }
};


template<class T>
class SingleList
{
private:
    SLNode<T>* head;
    SLNode<T>* tail;
    SLNode<T>* currptr;
    int listsize;

public:
    SingleList()
    {
        head = tail = currptr = new SLNode<T>();
        listsize = 0;
    }

    SingleList(T& item)
    {
        tail = currptr = new SLNode<T>(item);
        head = new SLNode<T>(currptr);
        listsize = 1;
    }

    ~SingleList()
    {
        while (!IsEmpty())
        {
            currptr = head->next;
            head->next = currptr->next;
            delete currptr;
        }
        delete head;
    }

    bool IsEmpty()const { return head->next == nullptr; }

    int length()const;

    void Find(int k)const;
    int FindNow()const;

    void Search(int x)const;

    void Erase();
    void EraseHead();
    void EraseTail();

    void Insert(const T& item);
    void InsertHead(const T& item);
    void InsertTail(const T& item);

    void Print();

};

#endif // SLLIST_H_INCLUDED

//定义一个单向链表
//实现单向链表的 create erase insert find remove(两种) print 六个功能