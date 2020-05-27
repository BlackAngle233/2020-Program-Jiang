#include "pch.h"
#include "Complex1.h"

Complex operator+(const Complex & num1, const Complex &num2)
{
	return Complex(num1.a+num2.a,num1.b+num2.b);
}

Complex operator-(const Complex & num1, const Complex &num2)
{
	return Complex(num1.a - num2.a, num1.b - num2.b);
}

Complex operator*(const Complex & num1, const Complex &num2)
{
	return Complex(num1.a*num2.a-num1.b*num2.b,num1.a*num2.b+num1.b*num2.a);
}

ostream & operator<<(ostream & out, Complex & obj)
{
	
		out << obj.a <<'+'<< " " << obj.b<<'i'<<endl;
		return out;
}

Complex &Complex::operator+=(const Complex & num1)
{
	 this->a +=num1.a;
	 this->b += num1.b;
	/* Complex e = Complex(num1.a + this->a, num1.b + this->b); */
	 
		 return *this;
}

Complex& Complex::operator-=(const Complex & num1)
{
	this->a = this->a - num1.a;
	this->b = this->b - num1.b;
	return *this;
}

Complex& Complex::operator*=(const Complex & num1)
{
	this->a = this->a*num1.a - this->b*num1.b;
	this->b = this->a*num1.b + this->b*num1.a;
	return *this;
}

Complex & Complex::operator++()
{
	++this->a ;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex e = *this;
	this->a++;
	return e;
}

Complex & Complex::operator--()
{
	--this->a;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex e = *this;
	this->a--;
	return e;
}

