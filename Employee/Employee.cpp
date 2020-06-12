#include"Employee.h"
#include<queue>
#include <stack>


void Employee::PrintReportLines()
{
	std::cout <<getName();
}

Employee::Employee(string name):name_(name)
{
}

void Manager::PrintReportLines()
{
	
	if (empls_.empty())
		return;
	std::cout << getName() << endl;
	showBelow(this, "   ");

}

void Manager::showBelow(Manager* p,const string& str)
{
	if (!p->empls_.empty())
	{
		for (int i = 0; i < p->empls_.size(); ++i) {
			std::cout << str << p->empls_[i]->getName()<<endl;
			showBelow((Manager*)p->empls_[i],"   " + str);
		}
		std::cout << std::endl;
	}
	
}

void Manager::AddEmployees(Employee* pe)
{
	empls_.push_back(pe);
}


Employee* FindLeastCommonManagers(Employee* root, const string& name1, const string& name2)
{
	
	if (not find((Manager*)root, name1) && not find((Manager*)root, name2))//找不到
		return nullptr;
	else if (not find((Manager*)root, name1))//只找不到name1
		return find((Manager*)root, name2);
	else if (not find((Manager*)root, name2))//只找不到name2
		return find((Manager*)root, name1);

	Manager* temp = (Manager*)root;

	stack<Manager*> s1;
	stack<Manager*> s2;
	//向s1,s2中压两个employee的路径
	s1.push((Manager*)root);
	for (int i = 0; i < temp->empls_.size(); )
	{
		if ( temp && find((Manager*)temp->empls_[i], name1))//子分支下面有name
		{
			s1.push((Manager*)temp->empls_[i]);//压栈
			temp = (Manager*)temp->empls_[i];//更改temp下移
			i = 0;
		}
		else
		++i;
	}
	//s2同样操作
	temp = (Manager*)root;
	s2.push((Manager*)root);
	for (int i = 0; i < temp->empls_.size(); )
	{
		if (temp && find((Manager*)temp->empls_[i], name2))//子分支下面有name
		{
			s2.push((Manager*)temp->empls_[i]);//压栈
			temp = (Manager*)temp->empls_[i];//更改temp下移
			i = 0;
		}
		else
			++i;
	}

	stack<Manager*> s = s1;
	stack<Manager*> l = s2;
	while (1)
	{
		temp = s.top();
		if (s.size() < l.size())
		{
			s = s1;
			l = s2;
		}
		else if (s.size() > l.size())
		{
			s = s2;
			l = s1;
		}
		else
		{
			if (s.top() == l.top())
				return temp;
			s.pop();
			l.pop();
			continue;
		}
		l.pop();
	}
}


//找root下是否存在name
Employee* find(Manager* root, const string& name) 
{

	queue<Manager*> q;
	if (nullptr == root) return nullptr;
	//判断根节点是否是Name
	if (root->getName() == name)
		return root;

	q.push(root);
	Manager* temp;
	while (!q.empty()) 
	{
		temp = q.front();
	if (temp->getName() == name)
			return temp;
		
		q.pop();
		for (int i = 0; i < temp->empls_.size(); ++i) 
		{	
			
			if (temp->empls_[i]->getName() == name) 
			{
				return temp->empls_[i];
			}
			q.push((Manager*)temp->empls_[i]);
		}
	}
	return nullptr;//未找到
}
