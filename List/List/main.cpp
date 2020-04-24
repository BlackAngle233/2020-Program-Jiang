
#include "SingleList.h"
#include<iostream>
#include"SingleList.cpp"
using namespace std;

int main(int argc, char const* argv[])
{
    SingleList<int> list; 
    while (true)
    {
        int i;
        cout << "What do you want to do?" << endl;
        cout << "1.insert  2.delete  3.find  4.search" << endl;
        cin >> i;
        if (i == 1)
        {
            cout << "1.insertnow  2.insertHead  3.insertTail  4.back" << endl;
            cin >> i;
            if (i == 1)
            {
                cin >> i;
                list.Insert(i);
            }
            else if (i == 2)
            {
                cin >> i;
                list.InsertHead(i);
            }
            else if (i == 3)
            {
                cin >> i;
                list.InsertTail(i);
            }
            else
            {
                i = 0;
                continue;
            }
            list.Print();
        }
        else if (i == 2)
        {
            cout << "1.deletenow  2.deleteHead  3.deleteTail  4.back" << endl;
            cin >> i;
            if (i == 1)
            {
                list.Erase();

            }
            else if (i == 2)
            {
                list.EraseHead();
            }
            else if (i == 3)
            {
                list.EraseTail();
            }
            else
            {
                i = 0;
                continue;
            }
            list.Print();
        }
        else if (i == 3)
        {
            cout << "1.find k  2.findnow  3.back" << endl;
            cin >> i;
            if (i == 1)
            {
                cin >> i;
                list.Find(i);
            }
            else if (i == 2)
            {
                cout << list.FindNow() << endl;
            }
            else
            {
                i = 0;
                continue;
            }
        }
        else
        {
            cin >> i;
            list.Search(i);
        }
    }
    return 0;
}