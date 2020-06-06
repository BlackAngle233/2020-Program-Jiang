#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Employee {
	string name_;
public:
	Employee(string name);
	string getName() { return name_; }
	virtual void PrintReportLines();
};
class Manager :public Employee {
	std::vector<Manager*> empls_;
public:
	Manager(string name);
	std::vector<Manager*> getEmpls() { return empls_; }
	void addManager(Manager* pe);
	void showSubtree(string);
	void PrintReportLines() override;
};

Employee* FindLeastCommonManagers(Manager* root, const string& name1, const string& name2);
bool isHave(Manager* manager, const string& name);
