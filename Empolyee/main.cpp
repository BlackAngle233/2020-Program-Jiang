#include"Employee.h"

int main() {
	Manager* a = new Manager("A");
	Manager* b = new Manager("B");
	Manager* c = new Manager("C");
	Manager* d = new Manager("D");
	(*a).addManager(b);
	(*a).addManager(c);
	(*b).addManager(d);

	(*a).PrintReportLines();
}