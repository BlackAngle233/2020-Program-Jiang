#include <iostream>
#include <vector>
using namespace std;
class Employee 
{
public:
virtual void PrintReportLines();
virtual bool findEmployee(const string& name);
virtual vector<Employee *> empls();
string getName() { return name_; }
Employee(string name) { name_ = name; }

private :
string name_ ;
};
class Manager : public Employee {
public :
    void AddEmployee( Employee* pe);
    void PrintReportLines() override;
    bool findEmployee(const string& name) override;
    vector<Employee *> empls() override{ return empls_; }
    Manager(string name) : Employee(name){}
private:
    vector<Employee*> empls_;
};
Employee* FindLeastCommonManagers ( Employee* root, const std::string& name1, const std::string& name2 )
{
    Employee *a;
    if(dynamic_cast<Manager*>(root)!=nullptr)    //如果节点是manager对象
    {
        if(root->findEmployee(name1) and root->findEmployee(name2))     //如果在其下找到了
        {
            for (auto tmp : root->empls())              //在子节点中继续寻找
            {
                a= FindLeastCommonManagers(tmp, name1, name2) == nullptr ? root : FindLeastCommonManagers(tmp, name1, name2);
            }
            return a;
        }
        else
        {
            return nullptr;
        }
    }
    return nullptr;
}
vector<Employee *> Employee::empls()
{
    vector<Employee *> a;
    return a;
}
bool Employee::findEmployee(const string& name)
{
    if(name_==name)
        return true;
    return false;
}
bool Manager::findEmployee(const string& name)      //是否找到名称为name的节点
{
    if(this->getName()==name)
        return true; 
    for(auto tmp : empls_)
    {
            return findEmployee(name);
    }
    return false;
}

void Employee::PrintReportLines()
{
    cout << name_ << endl;
}


void Manager::AddEmployee(Employee* pe)
{
    empls_.push_back(pe);
}

void Manager::PrintReportLines()
{
    cout << getName() << endl;
    if(empls_.empty())
        return;
    for (auto tmp : empls_)
    {
        cout <<' ';
        if(dynamic_cast<Manager*>(tmp)!=nullptr)        //如果tmp指向的对象是Manager类型
        {
            tmp->PrintReportLines();
        }
        else
        {
            cout << tmp->getName() << ' ';
        }
    }
    cout << endl;
}
