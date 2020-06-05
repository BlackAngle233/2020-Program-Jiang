#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Employee {
public:
	virtual void PrintReportLines();//没人report 打印自己
	Employee(string name);
	string getName() { return name_; }
private:
	string name_;

};
class Manager :public Employee {
public:
	void PrintReportLines() override;
	void showBelow( Manager*,const string& str);
	void AddEmployees(Employee* pe);
	Manager(string name):Employee(name){}
	std::vector<Employee*> empls_;
};

Employee* FindLeastCommonManagers(Employee* root, const string& name1, const string& name2);
bool find(Manager* root, const string& name);

