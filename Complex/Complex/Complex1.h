#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
class Complex {
public:
	int a;
	int b;
	Complex(int a, int b) {
		this->a = a;
		this->b = b;
	};
	//Complex &operator+=(const Complex &num1);
	Complex& operator+=(const Complex &num1);
	Complex &operator-=(const Complex &num1);
	Complex &operator*=(const Complex &num1);
	Complex& operator++();
	Complex  operator++(int);
	Complex& operator--();
	Complex  operator--(int);
	~Complex() {
		cout << this->a<<" "<<this->b<<" "<<this<< endl;
	}
};
Complex operator+(const Complex &num1, const Complex &num2);
Complex operator-(const Complex &num1, const Complex &num2);
Complex operator*(const Complex &num1, const Complex &num2);
ostream & operator<<(ostream &out, Complex &obj);

