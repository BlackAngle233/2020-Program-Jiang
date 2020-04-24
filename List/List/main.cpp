
#include "List.h"
using namespace std;

void test()
{
	int num1, num2, num3, num4, num5, num6;
	int m = 0;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	List list;
	Node *head;
	head = list.create(a, 10);
	for (;;) {
		cout << "1.find in location" << endl;
		cout << "2.find in value" << endl;
		cout << "3.insert the num" << endl;
		cout << "4.remove in location" << endl;
		cout << "5.remove in value" << endl;
		cout << "press the num of action:";
		cin >> m;
		switch (m)
		{
		case 1:cout << "input the number:";
			cin >> num1;
			list.get(num1);
			break;
		case 2:cout << "input the value:";
			cin >> num2;
			list.locate(num2);
			break;
		case 3:cout << "input the number:";
			cin >> num3;
			cout << "input the value:";
			cin >> num4;
			list.insert(num3, num4);
			break;
		case 4:cout << "input the number:";
			cin >> num5;
			list.remove_in_no(num5);
			break;
		case 5:cout << "input the value:";
			cin >> num6;
			list.remove_in_data(num6);
			break;
		}
	}
}
int main()
{
	int i;
	test();
	cout << "press any number to exit";
	cin >> i;
}