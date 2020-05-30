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
	void printf() {
		if (_i > 0)
			std::cout << _r << '+' << _i << 'i' << std::endl;
		else if (_i == 0)
			std::cout << _r << std::endl;
		else
			std::cout << _r << '-' << -_i << 'i' << std::endl;
	}
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