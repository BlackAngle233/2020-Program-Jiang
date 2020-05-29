#pragma once
#include<iostream>
using namespace std;

class MyComplex
{
private:
	double _real;//ʵ��
	double _imag;//�鲿
public:
	MyComplex(double, double);//���캯��
	MyComplex(MyComplex& c);//�������캯��
	~MyComplex();//��������
	MyComplex& operator=(const MyComplex& c);//��ֵ����������
	MyComplex& operator++();//ǰ��++
	MyComplex operator++(int);//����++
	MyComplex& operator--();//ǰ��--
	MyComplex operator--(int);//����--
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
		if(_imag != 0)
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
	friend ostream& operator<<(ostream& output, const MyComplex& complex);//�������������
};

MyComplex::MyComplex(double real = 0, double imag = 0)//���캯��
{
	_real = real;
	_imag = imag;
}
MyComplex::MyComplex(MyComplex& c)//�������캯��
{
	_real = c._real;
	_imag = c._imag;
}
MyComplex::~MyComplex()//��������
{
	_real = 0.0;
	_imag = 0.0;
}
MyComplex& MyComplex::operator=(const MyComplex& c)//��ֵ����������
{
	if (this != &c)
	{
		_real = c._real;
		_imag = c._imag;
	}
	return *this;
}
ostream& operator<<(ostream& output, const MyComplex& c)//�������������
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
MyComplex& MyComplex::operator++()
{
	++_real;
	return *this;
}
MyComplex MyComplex::operator++(int)
{
	MyComplex c;
	c._real = _real++;
	return c;
}
MyComplex& MyComplex::operator--()
{
	--_real;
	return *this;
}

MyComplex MyComplex::operator--(int)
{
	MyComplex c;
	c._real = _real--;
	return c;
}
MyComplex MyComplex::operator+(MyComplex& c)
{
	MyComplex sum;
	sum._real = this->_real + c._real;
	sum._imag = this->_imag + c._imag;
	return sum;
}
MyComplex& MyComplex::operator+=(MyComplex& c)
{
	_real += c._real;
	_imag += c._imag;
	return *this;
}
MyComplex MyComplex::operator-(MyComplex& c)
{
	MyComplex sub;
	sub._real = this->_real - c._real;
	sub._imag = this->_imag - c._imag;
	return sub;
}
MyComplex& MyComplex::operator-=(MyComplex& c)
{
	_real -= c._real;
	_imag -= c._imag;
	return *this;
}
MyComplex MyComplex::operator*(MyComplex& c)
{
	MyComplex mul;
	mul._real = _real * (c._real) - _imag * (c._imag);
	mul._imag = _imag * (c._real) + _real * (c._imag);
	return mul;
}
MyComplex& MyComplex::operator*=(MyComplex& c)
{
	double real = _real;
	_real = _real * c._real - _imag * c._imag;
	_imag = _imag * c._real + real * c._imag;
	return *this;
}
MyComplex MyComplex::operator/(MyComplex& complex)
{
	MyComplex dev;
	dev._real = (_real*complex._real + _imag*complex._imag)*1.0 /
	 (complex._real*complex._real + complex._imag*complex._imag);
	dev._imag = (_imag*complex._real - _real*complex._imag)*1.0 /
	 (complex._real*complex._real + complex._imag*complex._imag);
	return dev;
}
MyComplex& MyComplex::operator/=(MyComplex& complex)
{
	double real = _real;
	_real = (_real*complex._real + _imag * complex._imag) /
		(complex._real*complex._real + complex._imag*complex._imag);
	_imag = (_imag*complex._real - real * complex._imag) /
		(complex._real*complex._real + complex._imag*complex._imag);
	return *this;
}