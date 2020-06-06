#pragma once
#include<iostream>
#include<vector>
#include <string>

using namespace std;

class Employee {
public:
	Employee(string x);
	~Employee();
	virtual void PrintReportLines();
	string getName(){ return name_; }
private:
	string name_;
};

Employee::Employee(string x)
{
	name_ = x;
}

Employee::~Employee()
{
	;
}

void Employee::PrintReportLines()
{
	cout << name_ << endl;
}

class Manager : public Employee {
public:
	void PrintReportLines() override;
	std::vector<Employee*> GetEmpls()
	{
		return empls_;
	}
	Manager(string x);
	void showtree(string);
	void addManager(Manager* p);

private:
	std::vector<Employee*> empls_;
};

Manager::Manager(string name) :Employee(name)
{
	;
}

void Manager::addManager(Manager* p)
{
	this->GetEmpls().push_back(p);
}

void Manager::showtree(string xx)
{
	if (!this->GetEmpls().empty())//如果我的下属不为空
	{
		for (int i = 0; i < this->GetEmpls().size(); i++)
		{
			cout << xx << this->GetEmpls()[i] << endl;
			this->showtree("\t" + xx);
		}
	}
}

void Manager::PrintReportLines()
{
	if (empls_.empty())
		return;
	else
	{
		cout << this->getName() << endl;
		this->showtree("\t");
	}
}

Employee* FindLeastCommonManagers(Employee* root, const std::string& name1, const std::string& name2)
{

}
