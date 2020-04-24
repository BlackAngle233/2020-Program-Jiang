#include <iostream>
#include "SingleList.h"

using namespace std;

void Test() {
	cout << "使用{1,2,3,4,5}初始化" << endl;
	int nums1[] = { 1,2,3,4,5 };
	LinkList* list = create(nums1, 5);
	print(list);
	cout << endl;
	cout << "加入6" << endl;
	insert(list, 6);
	print(list);
	cout << endl;
	cout << "清空" << endl;
	erase(list);
	print(list);
	cout << endl;
	cout << "加入7" << endl;
	insert(list, 7);
	print(list);
	cout << endl;
	cout << "加入8" << endl;
	insert(list, 8);
	print(list);
	cout << endl;
	cout << "找到8" << endl;
	if (find(list, 8) != nullptr) {
		cout << find(list, 8)->value << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	cout << endl;
	cout << "找到7" << endl;
	if (find(list, 7) != nullptr) {
		cout << find(list, 7)->value << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	cout << endl;
	cout << "找到9" << endl;
	if (find(list, 9) != nullptr) {
		cout << find(list, 9)->value << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	cout << endl;
	cout << "清空" << endl;
	erase(list);
	print(list);
	cout << endl;
	cout << "使用{1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}初始化" << endl;
	int nums2[] = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
	list = create(nums2, 15);
	print(list);
	cout << endl;
	cout << "找到第一个4并删除" << endl;
	remove(list, find(list, 4));
	print(list);
	cout << endl;
	cout << "删除全部1（测试头尾）" << endl;
	remove(list, 1);
	print(list);
	cout << endl;
	cout << "删除全部5（测试中间）" << endl;
	remove(list, 5);
	print(list);
	cout << endl;
}

int main() {

	Test();

	return 0;
}