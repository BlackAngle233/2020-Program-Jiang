#ifndef EMPLOYEE__H__
#define EMPLOYEE__H__

#include <iostream>
#include <vector>
using namespace std;

class Employee
{
private:
    string name_;

public:
    //Report Names
    virtual void PrintReportLines();
    string getName();
    Employee(string name):name_(name){}
};

class Manager : public Employee
{
private:
    vector<Employee *> empls_;
public:
    Manager(string name):Employee(name){}
    void AddEmployee(Employee *pe);
    void PrintReportLines() override;
};

Employee *FindLeastCommonMannagers(Employee *root, const string &name1, string &name2);

#endif