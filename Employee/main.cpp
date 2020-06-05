#include"Employee.h"
#include <iostream>
void test()
{

		Manager* CEO = new Manager("CEO");

		Manager* headSales = new Manager("Head Sales");

		Manager* headMarketing = new Manager("Head Marketing");

		Manager* clerk1 = new Manager("clerk1");
		Manager* clerk2 = new Manager("clerk2");

		Manager* salesExecutive1 = new Manager("salesExecutive1");
		Manager* salesExecutive2 = new Manager("salesExecutive2");

		CEO->AddEmployees(headSales);
		CEO->AddEmployees(headMarketing);

		headSales->AddEmployees(salesExecutive1);
		headSales->AddEmployees(salesExecutive2);

		headMarketing->AddEmployees(clerk1);
		headMarketing->AddEmployees(clerk2);

		CEO->PrintReportLines();
			
		Employee* a = FindLeastCommonManagers(CEO, "salesExecutive1", "Head Sales");
		cout<<" FindLeastCommonManagers:(salesExecutive1, Head Sales): "<<a->getName()<<endl;
}
int main()
{
	test();
}

