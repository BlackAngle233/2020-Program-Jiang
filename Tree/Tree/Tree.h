#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Employee {
public:
	virtual Employee* find(const std::string& name);
	virtual void PrintReportLines();
	string getName() { return name_; }
private:
	std::string name_;
};

class Manager :public Employee {
public:
	Employee* find(const std::string& name) override;
	void AddEmployee(Employee* pe);
	void sonT(Manager* p, const string& str);
	void PrintReportLines()override;
	Employee* FindLeastCommonManagers(Employee* root, const std::string& name1, const std::string& name2);
private:
	std::vector <Employee*>empls_;
};