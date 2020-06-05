#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Employee.h"
using namespace std;
class Manager : public Employee
{
public:
	Manager(std::string n) :Employee(n) {}
	void AddEmployee(Employee* pe)
	{
		empls_.push_back(pe);
	}
	void PrintReportLines() override
	{
		cout << getName() << "��";
		for (int i = 0; i < empls_.size(); i++) 
		{
			cout << empls_[i]->getName();
			if (i != empls_.size() - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
		for (int j = 0; j < empls_.size(); j++)
		{
			empls_[j]->PrintReportLines();
		}
	}
//˼·����ÿ���ڵ㹹���Ӹ���㿪ʼ��ֱ��·���Ķ��У�Ȼ���ÿ�����е�ͷ����ʼ��ȡ�ڵ㣬�������һ����ȫ��ͬ�Ľڵ����Ŀ��
	Employee* FindLeastCommonManagers(Manager* root, const string& name1, const string& name2)
	{
		queue<Manager*> n1 = CreatPath(root, name1);
		queue<Manager*> n2 = CreatPath(root, name2);
		Manager* temp = root;
		int size = max(n1.size(), n2.size());
		for (int i = 0; i < size; i++)
		{
			if (n1.front() == n2.front())
			{
				temp = n1.front();
				n1.pop();
				n2.pop();
			}
			else
				return temp;
		}
		return root;
	}
	queue<Manager*> CreatPath(Manager* root, const string& name)
	{
		queue<Manager*> n;
		Manager* temp = root;//�ȶԸ������д���
		n.push(root);//�����������
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < temp->empls_.size(); i++)//�����ýڵ��µ�ĳ���ӽڵ��������Ŀ��
			{
				if (HaveTarget((Manager*)temp->empls_[i], name)|| temp->empls_[i]->getName() == name)//�������
				{
					n.push((Manager*)temp->empls_[i]);//���ӽڵ������
					temp = (Manager*)temp->empls_[i];//��һ���Ը��ӽڵ���д���
					flag = true;
					break;
				}
			}
		}
		return n;
	}
	bool HaveTarget(Manager* root, const string& name)//����ĳ���ڵ��µ������ӽڵ㿴����û��Ŀ��
	{
		bool flag = false;
		queue<Manager*> q;
		for (int i = 0; i < root->empls_.size(); i++)//�ȿ���һ��
		{
			if (root->empls_[i]->getName() == name) 
			{
				flag = true;
				return flag;
			}
			q.push((Manager*)root->empls_[i]);//�ڶ�������
		}
		Manager* tmp;
		while (!q.empty()) 
		{
			tmp = q.front();//�Ա��㴦��
			q.pop();//��һ�����
			for (int i = 0; i < tmp->empls_.size(); i++)
			{
				if (tmp->empls_[i]->getName() == name)
				{
					flag = true;
					return flag;
				}
				q.push((Manager*)tmp->empls_[i]);
			}
		}
		return flag;
	}
private:
	vector<Employee*> empls_;
};