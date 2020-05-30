#include <iostream>
#include "Manager.h"

using namespace std;

int main()
{
	Manager* root = new Manager("a");
	Manager* e1 = new Manager("b");
	Manager* e2 = new Manager("c");
	Manager* e3 = new Manager("d");

	root->AddEmployee(e1);
	root->AddEmployee(e2);
	root->AddEmployee(e3);

	Manager* e4 = new Manager("e");
	Manager* e5 = new Manager("f");

	e2->AddEmployee(e4);
	e2->AddEmployee(e5);

	Manager* e6 = new Manager("g");
	Manager* e7 = new Manager("h");

	e4->AddEmployee(e6);
	e4->AddEmployee(e7);

	root->PrintReportLines();

	cout << FindLeastCommonManagers(root, "g", "f")->getName() << endl;
	cout << FindLeastCommonManagers(root, "b", "f")->getName() << endl;
}


