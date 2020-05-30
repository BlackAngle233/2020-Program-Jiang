#pragma once
#include<iostream>
using namespace std;

class Complex
{
private:
	double _real;//实部
	double _imag;//虚部
public:
	Complex(double, double);//构造函数
	Complex(Complex& c);//拷贝构造函数
	~Complex();//析构函数
	Complex& operator=(const Complex& c);//赋值操作符重载
	Complex& operator++();//前置++
	Complex operator++(int);//后置++
	Complex& operator--();//前置--
	Complex operator--(int);//后置--
	void print()
	{
		cout << _real;
		if (_imag > 0)
		{
			cout << "+";
		}
		if (_imag != 1 && _imag != -1 && _imag != 0)
		{
			cout << _imag;
		}
		if (_imag == -1)
		{
			cout << "-";
		}
		if (_imag != 0)
			cout << "i";
	}
	Complex operator+(Complex& c);
	Complex& operator+=(Complex& c);
	Complex operator-(Complex& c);
	Complex& operator-=(Complex& c);
	Complex operator*(Complex& c);
	Complex& operator*=(Complex& c);
	Complex operator/(Complex& complex);
	Complex& operator/=(Complex& complex);
	friend ostream& operator<<(ostream& output, const Complex& complex);//输出操作符重载
};

Complex::Complex(double real = 0, double imag = 0)//构造函数
{
	_real = real;
	_imag = imag;
}
Complex::Complex(Complex& c)//拷贝构造函数
{
	_real = c._real;
	_imag = c._imag;
}
Complex::~Complex()//析构函数
{
	_real = 0.0;
	_imag = 0.0;
}
Complex& Complex::operator=(const Complex& c)//赋值操作符重载
{
	if (this != &c)
	{
		_real = c._real;
		_imag = c._imag;
	}
	return *this;
}
ostream& operator<<(ostream& output, const Complex& c)//输出操作符重载
{
	output << c._real;
	if (c._imag > 0)
	{
		output << "+";
	}
	if (c._imag != 1 && c._imag != -1 && c._imag != 0)
	{
		output << c._imag;
	}
	if (c._imag == -1)
	{
		output << "-";
	}
	if (c._imag != 0)
		output << "i";
	return output;
}
Complex& Complex::operator++()
{
	++_real;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex c;
	c._real = _real++;
	return c;
}
Complex& Complex::operator--()
{
	--_real;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex c;
	c._real = _real--;
	return c;
}
Complex Complex::operator+(Complex& c)
{
	Complex sum;
	sum._real = this->_real + c._real;
	sum._imag = this->_imag + c._imag;
	return sum;
}
Complex& Complex::operator+=(Complex& c)
{
	_real += c._real;
	_imag += c._imag;
	return *this;
}
Complex Complex::operator-(Complex& c)
{
	Complex sub;
	sub._real = this->_real - c._real;
	sub._imag = this->_imag - c._imag;
	return sub;
}
Complex& Complex::operator-=(Complex& c)
{
	_real -= c._real;
	_imag -= c._imag;
	return *this;
}
Complex Complex::operator*(Complex& c)
{
	Complex mul;
	mul._real = _real * (c._real) - _imag * (c._imag);
	mul._imag = _imag * (c._real) + _real * (c._imag);
	return mul;
}
Complex& Complex::operator*=(Complex& c)
{
	double real = _real;
	_real = _real * c._real - _imag * c._imag;
	_imag = _imag * c._real + real * c._imag;
	return *this;
}
Complex Complex::operator/(Complex& complex)
{
	Complex dev;
	dev._real = (_real * complex._real + _imag * complex._imag) * 1.0 /
		(complex._real * complex._real + complex._imag * complex._imag);
	dev._imag = (_imag * complex._real - _real * complex._imag) * 1.0 /
		(complex._real * complex._real + complex._imag * complex._imag);
	return dev;
}
Complex& Complex::operator/=(Complex& complex)
{
	double real = _real;
	_real = (_real * complex._real + _imag * complex._imag) /
		(complex._real * complex._real + complex._imag * complex._imag);
	_imag = (_imag * complex._real - real * complex._imag) /
		(complex._real * complex._real + complex._imag * complex._imag);
	return *this;
}
