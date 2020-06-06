#include <iostream>
#include "employee.h"

using namespace std;

int main()
{
    Employee Tom("Tom");
    Employee Jhon("Jhon");
    Employee Sam("Sam");
    Manager Jack("Jack");
    Manager Jekky("Jekky");
    Employee Alex("Alex");
    Employee Rander("Rander");
    Employee Joyy("Joyy");
    Jack.AddEmployee(&Tom);
    Jack.AddEmployee(&Jhon);
    Jack.AddEmployee(&Sam);
    Jack.AddEmployee(&Jekky);
    Jekky.AddEmployee(&Alex);
    Jekky.AddEmployee(&Rander);
    Jekky.AddEmployee(&Joyy);
    Jack.PrintReportLines();
    getchar();
}