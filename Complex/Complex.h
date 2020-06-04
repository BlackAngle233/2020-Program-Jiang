#pragma once
#include<iostream>

class Complex {
	double _r;
	double _i;
public:
	Complex(double r, double i) { _r = r;_i = i; }
	double getR() { return _r; }
	double getI() { return _i; }
	double getLength();
	void printf();
	friend Complex operator + (Complex& a, Complex& b);
	friend Complex operator - (Complex& a, Complex& b);
	friend Complex operator * (Complex& a, Complex& b);
	friend Complex operator / (Complex& a, Complex& b);

	Complex& operator ++();
	Complex& operator ++(int);
	Complex& operator --();
	Complex& operator --(int);


	Complex& operator +=(Complex& other);
	Complex& operator -=(Complex& other);
	Complex& operator *=(Complex& other);
	Complex& operator /=(Complex& other);
};