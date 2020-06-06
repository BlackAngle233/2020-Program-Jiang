#include"Employee.h"


Employee::Employee(string name) {
	name_ = name;
}

void Employee::PrintReportLines() {
	std::cout << this->getName() << std::endl;
}

Manager::Manager(string name):Employee(name) {

}

void Manager::addManager(Manager* e) {
	this->getEmpls().push_back(e);
}

void Manager::showSubtree(string space) {
	if (!this->getEmpls().empty()) {
		for (int i = 0;i < this->getEmpls().size();i++) {
			std::cout << space << this->getEmpls()[i]->getName() << std::endl;
			this->showSubtree("\t"+space);
		}
	}
}

void Manager::PrintReportLines() {
	if (empls_.empty())
		return;
	else {
		std::cout << this->getName() << std::endl;
		this->showSubtree("\t");
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
				item = item->getEmpls[i];
				flag = true;
				break;
			}
		}
	}
	return item;
}