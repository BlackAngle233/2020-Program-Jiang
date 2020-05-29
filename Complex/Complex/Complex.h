#pragma once
#include<iostream>

using namespace std;

class Complex {
private:
	double real;
	double image;
public:
	Complex() :real(0), image(0) {};

	Complex(double real, double image) { 
		this->real = real; this->image = image; 
	}

	Complex(const Complex& rhs) { 
		(*this).real = rhs.real; image = rhs.image; 
	}

	~Complex() {}

	double getReal()const { return real; }
	double getImage()const { return image; }

	Complex operator + (const Complex& rhs);
	Complex operator - (const Complex& rhs);
	Complex operator * (const Complex& rhs);
	Complex& operator = (const Complex& rhs);

	friend ostream& operator<<(ostream& os, const Complex& lhs);
};

