#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_
#include <initializer_list>
#include <string>
#include <iostream>
#include <vector>
#include <stack>

class Employee
{
    public:
        Employee(std::string name):_name(name)  {}
        virtual ~Employee();
        virtual void PrintReportLines();
        std::string getName();
    private:
        std::string _name;
};

class Manager:public Employee
{
    public:
        Manager(std::string name) : Employee(name) {};
        Manager(std::string name,std::initializer_list<Employee *> employees);
        void PrintReportLines() override;
        void AddEmployee(std::string name); 
        ~Manager() override;
    private:
        std::vector<Employee *> empls_ {};
        void Release(Employee *& root);
};

std::vector<std::string> trace{};
#endif
