#include"Employee.h"
#include<queue>


void Employee::PrintReportLines()
{
	std::cout <<getName();
}

Employee::Employee(string name):name_(name)
{
}

void Manager::PrintReportLines()
{
	
	if (empls_.empty())
		return;
	std::cout << getName() << endl;
	showBelow(this, "   ");

}

void Manager::showBelow(Manager* p,const string& str)
{
	if (!p->empls_.empty())
	{
		for (int i = 0; i < p->empls_.size(); ++i) {
			std::cout << str << p->empls_[i]->getName()<<endl;
			showBelow((Manager*)p->empls_[i],"   " + str);
		}
		std::cout << std::endl;
	}
	
}

void Manager::AddEmployees(Employee* pe)
{
	empls_.push_back(pe);
}


Employee* FindLeastCommonManagers(Employee* root, const string& name1, const string& name2)
{
	Manager* temp = (Manager*)root;
	bool flag = true;
	while (flag) 
	{
		flag = false;
		for (int i = 0; i < temp->empls_.size(); ++i) 
		{
			if (find((Manager*)temp->empls_[i], name1) && find((Manager*)temp->empls_[i], name2)) 
			{
				temp = (Manager*)temp->empls_[i];
				flag = true;
				break;
			}
		}
	}
	return (Employee*)temp;
}

bool find(Manager* root, const string& name) 
{

	queue<Manager*> q;

	if (root->getName() == name)
		return true;

	for (int i = 0; i < root->empls_.size(); ++i) 
	{
		if (root->empls_[i]->getName() == name) 
		{
			return true;
		}
		q.push((Manager*)root->empls_[i]);
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
				return true;
			}
			q.push((Manager*)temp->empls_[i]);
		}
	}
	return false;
}
