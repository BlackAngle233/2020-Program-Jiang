#include <iostream>
#include "SingleList.h"

int main()
{
	int numList[] = { 1,2,3,4,5,4 };
	SingleList* list = create(numList,6);
	print(list);

	//��������һ��ֵΪ3�Ľ��
	insert(list, 3);
	print(list);

	// �ҵ���һ��ֵΪ4�Ľ�㲢��ɾ����
	remove(list, find(list, 4)) ;
	print(list);

	// ɾ������ֵΪ3�Ľ��
	remove(list, 3);
	print(list);

	// ɾ��������
	erase(list);
}