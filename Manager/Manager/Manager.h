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
		cout << getName() << "→";
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
//思路：给每个节点构建从根结点开始的直线路径的队列，然后从每个队列的头部开始读取节点，读到最后一个完全相同的节点就是目标
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
		Manager* temp = root;//先对根结点进行处理
		n.push(root);//根结点必入队列
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < temp->empls_.size(); i++)//看看该节点下的某个子节点包不包含目标
			{
				if (HaveTarget((Manager*)temp->empls_[i], name)|| temp->empls_[i]->getName() == name)//如果包含
				{
					n.push((Manager*)temp->empls_[i]);//该子节点进队列
					temp = (Manager*)temp->empls_[i];//下一个对该子节点进行处理
					flag = true;
					break;
				}
			}
		}
		return n;
	}
	bool HaveTarget(Manager* root, const string& name)//遍历某个节点下的所有子节点看看有没有目标
	{
		bool flag = false;
		queue<Manager*> q;
		for (int i = 0; i < root->empls_.size(); i++)//先看第一层
		{
			if (root->empls_[i]->getName() == name) 
			{
				flag = true;
				return flag;
			}
			q.push((Manager*)root->empls_[i]);//第二层入列
		}
		Manager* tmp;
		while (!q.empty()) 
		{
			tmp = q.front();//对本层处理
			q.pop();//上一层出列
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