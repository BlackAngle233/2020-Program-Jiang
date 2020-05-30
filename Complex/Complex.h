#pragma once
#include <iostream>
using namespace std;
class Complex {
	double x,i;
	Complex();
public: Complex(double x, double i);
	Complex& operator+(const Complex &cpx);
	Complex& operator-(const Complex &cpx);
	Complex& operator*(const Complex &cpx);
	//Complex& operator=(const Complex &cpx);
	friend void show(Complex cpx);
	friend double Mod(Complex cpx);
};
Complex::Complex(double x, double i) {
	this->x = x;
	this->i = i;
}
Complex::Complex() {
	this->x = 0; 
	this->i = 0;
}
inline Complex & Complex::operator+(const Complex & cpx)
{
	double     x1, i1;
	x1 = x + cpx.x;
	i1 = i + cpx.i;
	Complex cpx1(x1,i1);
	return cpx1;
	// TODO: 在此处插入 return 语句
}
inline Complex & Complex::operator-(const Complex & cpx)
{
	double     x1, i1;
	x1 = x - cpx.x;
	i1 = i - cpx.i;
	Complex cpx1(x1, i1);
	return cpx1;
	// TODO: 在此处插入 return 语句
}
inline Complex & Complex::operator*(const Complex & cpx)
{
	double     x1, i1;
	x1 = x * cpx.x - i * cpx.i;
	i1 = x * cpx.i + i * cpx.x;
	Complex cpx1(x1, i1);
	return cpx1;
	//（a + bi)(c + di) = (ac - bd) + (ad + bc)i
	// TODO: 在此处插入 return 语句
}
//inline Complex & Complex::operator=(const Complex & cpx)
//{
//	if (this == &cpx)    
//		return *this;
//	x = cpx.x;
//	i = cpx.i;
//	return *this;
//	// TODO: 在此处插入 return 语句
//}
double Mod(Complex cpx)
{
	return (cpx.x*cpx.x+cpx.i*cpx.i);
}
inline void show(Complex cpx)
{
	cout << "(" << cpx.x << "," << cpx.i << "i" << ")" << endl;
}
