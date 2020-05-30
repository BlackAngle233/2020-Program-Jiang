#pragma once
#include<iostream>
using namespace std;

class MyComplex
{
private:
	double _re;
	double _im;
public:
	MyComplex(double, double);
	MyComplex(MyComplex& c);
	~MyComplex();
	MyComplex& operator=(const MyComplex& c);
	MyComplex& operator++();
	MyComplex operator++(int);
	MyComplex& operator--();
	MyComplex operator--(int);
	void print()
	{
		cout << _re;
		if (_im > 0)
		{
			cout << "+";
		}
		if (_im != 1 && _im != -1 && _im != 0)
		{
			cout << _im;
		}
		if (_im == -1)
		{
			cout << "-";
		}
		if (_im != 0)
			cout << "i";
	}
	MyComplex operator+(MyComplex& c);
	MyComplex& operator+=(MyComplex& c);
	MyComplex operator-(MyComplex& c);
	MyComplex& operator-=(MyComplex& c);
	MyComplex operator*(MyComplex& c);
	MyComplex& operator*=(MyComplex& c);
	MyComplex operator/(MyComplex& complex);
	MyComplex& operator/=(MyComplex& complex);
	friend ostream& operator<<(ostream& output, const MyComplex& complex);
};

MyComplex::MyComplex(double real = 0, double imag = 0)
{
	_re = real;
	_im = imag;
}
MyComplex::MyComplex(MyComplex& c)
{
	_re = c._re;
	_im = c._im;
}
MyComplex::~MyComplex()
{
	_re = 0.0;
	_im = 0.0;
}
MyComplex& MyComplex::operator=(const MyComplex& c)
{
	if (this != &c)
	{
		_re = c._re;
		_im = c._im;
	}
	return *this;
}
ostream& operator<<(ostream& output, const MyComplex& c)
{
	output << c._re;
	if (c._im > 0)
	{
		output << "+";
	}
	if (c._im != 1 && c._im != -1 && c._im != 0)
	{
		output << c._im;
	}
	if (c._im == -1)
	{
		output << "-";
	}
	if (c._im != 0)
		output << "i";
	return output;
}
MyComplex& MyComplex::operator++()
{
	++_re;
	return *this;
}
MyComplex MyComplex::operator++(int)
{
	MyComplex c;
	c._re = _re++;
	return c;
}
MyComplex& MyComplex::operator--()
{
	--_re;
	return *this;
}

MyComplex MyComplex::operator--(int)
{
	MyComplex c;
	c._re = _re--;
	return c;
}
MyComplex MyComplex::operator+(MyComplex& c)
{
	MyComplex sum;
	sum._re = this->_re + c._re;
	sum._im = this->_im + c._im;
	return sum;
}
MyComplex& MyComplex::operator+=(MyComplex& c)
{
	_re += c._re;
	_im += c._im;
	return *this;
}
MyComplex MyComplex::operator-(MyComplex& c)
{
	MyComplex sub;
	sub._re = this->_re - c._re;
	sub._im = this->_im - c._im;
	return sub;
}
MyComplex& MyComplex::operator-=(MyComplex& c)
{
	_re -= c._re;
	_im -= c._im;
	return *this;
}
MyComplex MyComplex::operator*(MyComplex& c)
{
	MyComplex mul;
	mul._re = _re * (c._re) - _im * (c._im);
	mul._im = _im * (c._re) + _re * (c._im);
	return mul;
}
MyComplex& MyComplex::operator*=(MyComplex& c)
{
	double real = _re;
	_re = _re * c._re - _im * c._im;
	_im = _im * c._re + real * c._im;
	return *this;
}
MyComplex MyComplex::operator/(MyComplex& complex)
{
	MyComplex dev;
	dev._re = (_re * complex._re + _im * complex._im) * 1.0 / (complex._re * complex._re + complex._im * complex._im);
	dev._im = (_im * complex._re - _re * complex._im) * 1.0 / (complex._re * complex._re + complex._im * complex._im);
	return dev;
}
MyComplex& MyComplex::operator/=(MyComplex& complex)
{
	double real = _re;
	_re = (_re * complex._re + _im * complex._im) / (complex._re * complex._re + complex._im * complex._im);
	_im = (_im * complex._re - real * complex._im) / (complex._re * complex._re + complex._im * complex._im);
	return *this;
}
