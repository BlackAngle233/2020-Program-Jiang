#pragma once

class Complex {
private:
	double real;
	double image;

public:
	//Complex() :real(0), image(0) {};
	Complex(double re=0, double im=0) :real(re), image(im) {};

	//constexpr double real() const { return real; }
	//constexpr double imag() const { return image; }
	//void real(double r) { real = r; }
	//void imag(double i) { image = i; }

	double getReal(){return real ; }
	double getImage(){return image ; }
	double abs();
	friend Complex operator+(const Complex& c1,const Complex& c2);
	friend Complex operator-(const Complex& c1,const Complex& c2);
	friend Complex operator*(const Complex& c1,const Complex& c2);
	friend Complex operator/(const Complex& c1,const Complex& c2);
	friend bool operator==(const Complex& c1,const Complex& c2);

	Complex& operator++();
	Complex& operator++(int flag);
	Complex& operator--();
	Complex& operator--(int flag);

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	void print();
};