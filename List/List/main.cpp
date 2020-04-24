#include <iostream>
#include "SingleList.h"

using namespace std;

void Test() {
	cout << "ʹ��{1,2,3,4,5}��ʼ��" << endl;
	int nums1[] = { 1,2,3,4,5 };
	LinkList* list = create(nums1, 5);
	print(list);
	cout << endl;
	cout << "����6" << endl;
	insert(list, 6);
	print(list);
	cout << endl;
	cout << "���" << endl;
	erase(list);
	print(list);
	cout << endl;
	cout << "����7" << endl;
	insert(list, 7);
	print(list);
	cout << endl;
	cout << "����8" << endl;
	insert(list, 8);
	print(list);
	cout << endl;
	cout << "�ҵ�8" << endl;
	if (find(list, 8) != nullptr) {
		cout << find(list, 8)->value << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	cout << endl;
	cout << "�ҵ�7" << endl;
	if (find(list, 7) != nullptr) {
		cout << find(list, 7)->value << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	cout << endl;
	cout << "�ҵ�9" << endl;
	if (find(list, 9) != nullptr) {
		cout << find(list, 9)->value << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	cout << endl;
	cout << "���" << endl;
	erase(list);
	print(list);
	cout << endl;
	cout << "ʹ��{1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}��ʼ��" << endl;
	int nums2[] = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
	list = create(nums2, 15);
	print(list);
	cout << endl;
	cout << "�ҵ���һ��4��ɾ��" << endl;
	remove(list, find(list, 4));
	print(list);
	cout << endl;
	cout << "ɾ��ȫ��1������ͷβ��" << endl;
	remove(list, 1);
	print(list);
	cout << endl;
	cout << "ɾ��ȫ��5�������м䣩" << endl;
	remove(list, 5);
	print(list);
	cout << endl;
}

int main() {

	Test();

	return 0;
}