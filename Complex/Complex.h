#pragma once
#include<iostream>
using namespace std;


class Complex
{
private:
	double re{};
	double im{};
public:
	Complex(double r =0, double i=0 );
	double getRe() { return re; }
	double getIm() { return im; }
	void setCplx(double r, double i);
	double abs();
	friend Complex operator+(const Complex& c1,const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator/(const Complex& c1, const Complex& c2);
	friend bool operator== (const Complex& c1, const Complex& c2);
	friend ostream& operator<<(ostream& out, const Complex& c);



	Complex& operator++();
	Complex operator++(int);
	Complex& operator--();
	Complex operator--(int);
	Complex& operator-();

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);


	class CplxException :public exception {
	public:
		CplxException() :exception("can not divide a number by zero.\n") {}
	};
};

