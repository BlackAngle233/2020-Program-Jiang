#include"Employee.h"
#include<queue>

Employee::Employee(string name) {
	name_ = name;
}

void Employee::PrintReportLines() {
	std::cout << this->getName() << std::endl;
}

Manager::Manager(string name):Employee(name) {

}

void Manager::addManager(Manager* e) {
	empls_.push_back(e);
}

//void Manager::showSubtree(string space) {
//	if (!empls_.empty()) {
//		for (int i = 0;i < empls_.size();i++) {
//			std::cout << empls_[i]->getName() << space;
//		}
//		std::cout << std::endl;
//		for (int i = 0;i < empls_.size();i++) {
//
//		}
//	}
//}

void Manager::PrintReportLines() {
	std::cout << this->getName() << std::endl;
	queue<Manager* > q;
	if (empls_.empty())
		return;
	else {
		//this->showSubtree("\t");
		q.push(this);
		while (!q.empty()) {
			Manager* temp = q.pop();
			for (int i = 0;i < temp->empls_.size();i++) {
				std::cout << temp->empls_[i]->getName()<<"\t";
				q.push(temp->empls_[i]);
			}
		}
	}
}

bool isHave(Manager* manager, const string& name) {
	if (!manager->getEmpls().empty()) {
		for (int i = 0;i < manager->getEmpls().size();i++) {
			if (manager->getEmpls()[i]->getName() == name)
				return true;
		}
		for (int i = 0;i < manager->getEmpls().size();i++) {
			if (isHave(manager->getEmpls()[i], name))
				return true;
		}
		return false;
	}
	else
		return false;
}

Employee* FindLeastCommonManagers(Manager* root, const string& name1, const string& name2){
	Manager* item = root;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < item->getEmpls().size(); ++i)
		{
			if (isHave(item->getEmpls()[i], name1) && isHave(item->getEmpls()[i], name2))
			{
				item = item->getEmpls()[i];
				flag = true;
				break;
			}
		}
	}
	return item;
}