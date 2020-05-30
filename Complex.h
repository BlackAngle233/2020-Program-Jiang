#pragma once
#include<iostream>
using namespace std;

class Complex
{
private:
	double _real;//ʵ��
	double _imag;//�鲿
public:
	Complex(double, double);//���캯��
	Complex(Complex& c);//�������캯��
	~Complex();//��������
	Complex& operator=(const Complex& c);//��ֵ����������
	Complex& operator++();//ǰ��++
	Complex operator++(int);//����++
	Complex& operator--();//ǰ��--
	Complex operator--(int);//����--
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
	friend ostream& operator<<(ostream& output, const Complex& complex);//�������������
};

Complex::Complex(double real = 0, double imag = 0)//���캯��
{
	_real = real;
	_imag = imag;
}
Complex::Complex(Complex& c)//�������캯��
{
	_real = c._real;
	_imag = c._imag;
}
Complex::~Complex()//��������
{
	_real = 0.0;
	_imag = 0.0;
}
Complex& Complex::operator=(const Complex& c)//��ֵ����������
{
	if (this != &c)
	{
		_real = c._real;
		_imag = c._imag;
	}
	return *this;
}
ostream& operator<<(ostream& output, const Complex& c)//�������������
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
