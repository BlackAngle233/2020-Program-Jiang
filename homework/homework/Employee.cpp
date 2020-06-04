#include "pch.h"
#include "Employee.h"
#include <iostream>
#include<string>
#include<vector>
#include<queue>
stack<Employee*>Employees;
Employee * Employee::find(const string & name)
{
	return this;
}

void Employee::printreportline()
{
	cout << this->name_ ;
}

void Manager::addemployee(Employee * ep)
{
	this->empls_.push_back(ep);
}

void Manager::printreportline()
{
	cout << this->name_ << endl;
	for (auto a = empls_.begin(); a != empls_.end(); a++) 
	{
		
		(*a)->printreportline();
		
	}
	
}

Employee * Manager::find(const string & name)
{
	if (this->name_ == name)
		return this;
	for (auto a = empls_.begin(); a != empls_.end(); a++) 
	{
		if ((*a)->find(name) != nullptr)
			return (*a)->find(name);
		if ((*a)->name_ == name)
			return *a;

	}
	return nullptr;
}

Employee * findlastManager(Employee * root, const string & name1, const string & name2)
{
	
	Manager* root1 = (Manager*)root;
	Employees.push(root);
	if (root1->find(name1) != nullptr&&root1->find(name2) != nullptr) 
	{
		for (auto a = root1->empls_.begin(); a != root1->empls_.end(); a++)
		{
			if ((*a)->find(name1) != nullptr && (*a)->find(name2) != nullptr) 
			{
				
				findlastManager((Manager*)(*a),name1,name2);
			}


		}
		
	}
	return Employees.top();
	
}


