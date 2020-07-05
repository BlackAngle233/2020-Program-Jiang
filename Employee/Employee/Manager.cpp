#include "Manager.h"

void Manager::AddEmployee(Employee* pe)
{
	empls_.push_back(pe);
}

void Manager::PrintReportLines()
{
	if (empls_.empty())
		return;
	std::cout << getName() << "->";
	for (int i = 0; i < empls_.size(); ++i) {
		std::cout << "  " << empls_[i]->getName();
	}
	std::cout << std::endl;

	for (int i = 0; i < empls_.size(); ++i) {
		empls_[i]->PrintReportLines();
	}
}

Manager* FindLeastCommonManagers(Manager* root, const std::string& name1, const std::string& name2)
{
	Manager* tmp = root;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < tmp->empls_.size(); ++i) {
			if (isContain((Manager*)tmp->empls_[i], name1) && isContain((Manager*)tmp->empls_[i], name2)) {
				tmp = (Manager*)tmp->empls_[i];
				flag = true;
				break;
			}
		}
	}
	return tmp;
}

bool isContain(Manager* root, const std::string& name) {
	bool flag = false;
	std::queue<Manager*> q;
	for (int i = 0; i < root->empls_.size(); ++i) {
		if (root->empls_[i]->getName() == name) {
			flag = true;
			return flag;
		}
		q.push((Manager*)root->empls_[i]);
	}
	Manager* tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 0; i < tmp->empls_.size(); ++i) {
			if (tmp->empls_[i]->getName() == name) {
				flag = true;
				return flag;
			}
			q.push((Manager*)tmp->empls_[i]);
		}
	}
	return flag;
}
