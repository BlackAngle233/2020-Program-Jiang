#pragma once
#include <string>
#include <iostream>

class Employee
{
public:
	Employee(std::string n):name_(n) {}

	virtual void PrintReportLines();
	std::string getName() { return name_; }
private:
	std::string name_;
};

