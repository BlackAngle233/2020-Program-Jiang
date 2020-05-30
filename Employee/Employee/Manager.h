#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "Employee.h"

class Manager : public Employee {
	friend Manager* FindLeastCommonManagers(Manager* root, const std::string& name1, const std::string& name2);
	friend bool isContain(Manager* root, const std::string& name);
public:
	Manager(std::string n) :Employee(n) {}

	void AddEmployee(Employee* pe);
	void PrintReportLines() override;
private:
	std::vector<Employee*> empls_;
};

Manager* FindLeastCommonManagers(Manager* root, const std::string& name1, const std::string& name2);

bool isContain(Manager* root, const std::string& name);