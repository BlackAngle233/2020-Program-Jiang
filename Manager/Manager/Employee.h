#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
	Employee(std::string n) :name_(n) {}
	virtual void PrintReportLines()
	{
		cout << name_;
	}
	string getName()
	{
		return name_;
	}
private:
	string name_;
};