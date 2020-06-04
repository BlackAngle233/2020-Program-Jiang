#pragma once
#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Employee {
public:
	virtual Employee*find(const string&name);
	virtual void printreportline();
	string name_;
	Employee(string a) {
		name_ = a;
	}
};
class Manager:public Employee {
public:
	void addemployee(Employee*ep);
	 void printreportline() override;
	 Employee*find(const string&name) override;
	vector<Employee*>empls_;
	Manager(string a):Employee(a) {  };

};
Employee*findlastManager(Employee*root, const string&name1, const string&name2);
