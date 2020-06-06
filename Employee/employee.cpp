#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

string Employee::getName()
{
    return name_;
}

void Employee::PrintReportLines()
{
    cout << "Employee: " << getName() << " " << endl;
}

void Manager::AddEmployee(Employee *ep)
{
    empls_.push_back(ep);
}

void Manager::PrintReportLines()
{
    int i = 0;
    cout << "Manager: " << getName() << " " << endl;
    for (auto em = empls_.begin(); em != empls_.end(); em++, i++)
    {
        empls_[i]->PrintReportLines();
    }
}

Employee *FindLeastCommonMannagers(Employee *root, const string &name1, string &name2)
{
    return nullptr;
}