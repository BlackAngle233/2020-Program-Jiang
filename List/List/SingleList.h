#pragma once

struct SingleList
{	
	struct Node
	{
		Node* next = nullptr;
		int value;
	};
	Node* head;
};

//����һ����������
//ʵ�ֵ�������� create erase insert find remove(����) print ��������