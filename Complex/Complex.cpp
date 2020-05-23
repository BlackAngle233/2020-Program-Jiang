#include"Complex.h"
using namespace std;
#include<iostream>
Complex::Complex(double r , double i ):re(r),im(i)
{
}

void Complex::setCplx(double r = 0, double i = 0)
{
	re = r;
	im = i;
}

double Complex::abs()
{
	return re * re + im * im;
}

Complex& Complex::operator++()
{
	re++;
	im++;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex c{ re,im };
	re++;
	im++;
	return c;
}

Complex& Complex::operator--()
{
	re--;
	im--;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex c{ re,im };
	re--;
	im--;
	return c;
}

Complex& Complex::operator-()
{
	re = -re;
	im = -im;
	return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
	re += other.re;
	im += other.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	re -= other.re;
	im -= other.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	re = re * other.re - im * other.im;
	im = re * other.im + im * other.re;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	try {
		if (other == 0)
			throw Complex::CplxException();
		double t = 1 / (other.re * other.re + other.im * other.im);
		re = (re * other.re + im * other.im) / t;
		im = (im * other.re - re * other.im) / t;
		return *this;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}


Complex operator+(const Complex& c1, const Complex& c2) 
{
	return Complex{ c1.re + c2.re,c1.im + c2.im };
}

Complex operator-(const Complex& c1, const Complex& c2) 
{
	return Complex{ c1.re - c2.re,c1.im - c2.im };
}

Complex operator*(const Complex& c1, const Complex& c2) 
{
	return Complex{ c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re };
}

Complex operator/(const Complex& c1, const Complex& c2) 
{
	try{
		if (c2 == 0)
			throw Complex::CplxException();
		double t = 1 / (c2.re * c2.re + c2.im * c2.im);
		return Complex{ (c1.re * c2.re + c1.im * c2.im) / t,(c1.im * c2.re - c1.re * c2.im) / t };
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

bool operator==(const Complex& c1, const Complex& c2)
{
	return c1.re==c2.re&&c1.im==c2.im;
}

ostream& operator<<(ostream& out, const Complex& c)
{
	if (c.im == 0)
		out << c.re << endl;
	else if (c.re == 0)
		if (c.im == 1) out << "i" << endl;
		else if (c.im == -1) out << "-i" << endl;
		else out << c.im << "i" << endl;
	else
	{
		out << c.re;
		if (c.im > 0)
			out << "+";
		if (c.im == 1) out << "i" << endl;
		else if (c.im == -1) out << "-i" << endl;
		else 
			out << c.im << "i" << endl;
	}
	return out;
}









