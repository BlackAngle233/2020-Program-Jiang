#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	cout << "Hello World!\n"; 
	SingleList l;
	int n;
	cout << "输个链表长度" << endl;
	cin >> n;
	l.CreateSingleList(n);  //创建链表

	cout << "链表为" << endl;
	l.Print();  //打印链表

	int value;
	int index;
	cout << "插入的数据" << endl;
	cin >> value;
	cout << "插入的位置" << endl;
	cin >> index;
	l.Insert(value,index);  //插入value
	cout << "链表为" << endl;
	l.Print();

	int removevalue;
	cout << "要删的数据" << endl;
	cin >> removevalue;
	l.Remove(removevalue);  //删value
	cout << "链表为" << endl;
	l.Print();

	int num;
	cout << "输入要查找的节点号" << endl;
	cin >> num;
	cout << l.Find(num)->value << endl;  //查找节点号数据

	int i;
	cout << "是否删除链表？" << endl;
	cout << "1.可  2.算了" << endl;
	cin >> i;
	switch (i) {
	case 1:
		l.EraseSingleList();
		break;

	case 2:
		cout << "链表为" << endl;
		l.Print();
		break;
	}
}