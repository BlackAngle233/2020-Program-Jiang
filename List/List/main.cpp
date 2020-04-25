#include <iostream>
#include "SingleList.h"


SingleList Instance;

void test()
{
    SingleList::Create(Instance.head,1);
    SingleList::Node *p = Instance.head;
    for(int i = 0; i < 9; i++)
    {
        SingleList::Create(p->next, i);
        p = p -> next;
    }
    SingleList::print(Instance.head);
    //created a list 1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    //delete node 7
    SingleList::Delete(Instance.head,7);

    SingleList::print(Instance.head);
    //successfully deleted node with the value 7

}

int main()
{
    test();
}
