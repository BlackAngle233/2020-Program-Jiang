#include<iostream>
#include"Complex.h"
using namespace std;
int main() {
	Complex t1{ 1,2 };
	cout<<"t1："<<endl;
	t1.print();

	Complex t2{ 3,4 };
	cout << "t2：" << endl;
	t2.print();
	double zhi = t2.abs();
	cout << "复数的值为：" << zhi << endl;

	Complex t3{};
	t3=t1+t2;
	cout << "t1+t2：" << endl;
	t3.print();

	t3=t1-t2;
	cout << "t1-t2：" << endl;
	t3.print();

	t3=t1*t2;
	cout << "t1*t2：" << endl;
	t3.print();

	t3=t1/t2;
	cout << "t1/t2：" << endl;
	t3.print();

	t1 += 1;
	cout << "t1+=1：" << endl;
	t1.print();

	t1 -= 1;
	cout << "t1-=1：" << endl;
	t1.print();

	t1 *= 2;
	cout << "t1*=2：" << endl;
	t1.print();

	t1 /= 2;
	cout << "t1/=2：" << endl;
	t1.print();

	t1 += t2;
	cout << "t1+=t2：" << endl;
	t1.print();

	t1 -= t2;
	cout << "t1-=t2：" << endl;
	t1.print();

	t1 *= t2;
	cout << "t1*=t2：" << endl;
	t1.print();

	t1 /= t2;
	cout << "t1/=t2：" << endl;
	t1.print();

	Complex t4{ };
	cout << "t4：" << endl;
	t4.print();

	t4=t1++;
	cout << "t4=t1++：" << endl;
	t4.print();

	t4=t1--;
	cout << "t4=t1--：" << endl;
	t4.print();

	t4=++t1;
	cout << "t4=++t1：" << endl;
	t4.print();

	t4=--t1;
	cout << "t4=--t1：" << endl;
	t4.print();
}