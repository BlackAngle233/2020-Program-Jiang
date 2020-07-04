#include "Employee.h"
#include <stack>

std::string Employee::getName()
{
    return this -> _name;
}


Manager::Manager(std::string name, std::initializer_list<Employee *> employees) 
 : Employee(name)
{
    for(auto it = employees.begin(); it != employees.end(); ++it)
    {
        empls_.push_back(*it);
    }
}

void Manager::PrintReportLines() 
{
    trace.push_back(this -> getName());
    if(this->empls_.empty())
    {
        if(!trace.empty())
        {
            for(int i = trace.size() - 1; i >= 0; --i)
            {
                std::cout << trace[i];
                if(i != 0) std::cout << " -> ";
            }
            std::cout << std::endl;
        }
        trace.pop_back();
        return ;
    }

    for(int i = 0; i < empls_.size() ; ++i)
    {
        empls_[i] -> PrintReportLines();
    }
    trace.pop_back();
    return ;
}


void Manager::AddEmployee(std::string name)
{
    
}
