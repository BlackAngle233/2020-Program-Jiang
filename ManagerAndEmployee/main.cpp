#include "Manager.h"
int main()
{
    Manager *a = new Manager("A");
    Manager *b = new Manager("B");
    Employee *c = new Employee("C");
    Employee *d = new Employee("D");
    Employee *e = new Employee("E");

    a->AddEmployee(b);
    a->AddEmployee(c);
    b->AddEmployee(d);
    b->AddEmployee(e);

    a->PrintReportLines();

    cout << FindLeastCommonManagers(a, "D", "E")->getName() << endl;
    return 0;
}