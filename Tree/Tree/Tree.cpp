#include<iostream>
#include<vector>
#include"Tree.h"
#include<queue>
using namespace std;

Employee* Employee::find(const std::string& name) {
	if (name_ == name) return this;
	else return nullptr;
}

void Employee::PrintReportLines()
{
	cout << getName()<<endl;
}

void Manager::AddEmployee(Employee* pe) {
	empls_.push_back(pe);
}

void Manager::sonT(Manager* p, const string& str)
{
	if (!p->empls_.empty())
	{
		for (int i = 0; i < p->empls_.size(); ++i) {
			cout << str << p->empls_[i]->getName() << endl;
			sonT((Manager*)p->empls_[i], "   " + str);
		}
		cout << endl;
	}

}

void Manager::PrintReportLines() {
	if (empls_.empty())return;
	cout << getName() << endl;
	sonT(this, "   ");
}

Employee* Manager::find(const std::string& name) {
	queue<Manager*> q;

	if (getName() == name)
		return this;

	for (int i = 0; i < empls_.size(); ++i)
	{
		if (empls_[i]->getName() == name)
		{
			return empls_[i];
		}
		q.push((Manager*)empls_[i]);
	}
	Manager* temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		for (int i = 0; i < temp->empls_.size(); ++i)
		{
			if (temp->empls_[i]->getName() == name)
			{
				return temp->empls_[i];
			}
			q.push((Manager*)temp->empls_[i]);
		}
	}
	return nullptr;
}

Employee* Manager::FindLeastCommonManagers(Employee* root, const std::string& name1, const std::string& name2) {
	Manager* temp = (Manager*)root;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < temp->empls_.size(); ++i)
		{
			if (find(name1)!=nullptr && find(name2)!=nullptr)
			{
				temp = (Manager*)temp->empls_[i];
				flag = true;
				break;
			}
		}
	}
	return (Employee*)temp;
}