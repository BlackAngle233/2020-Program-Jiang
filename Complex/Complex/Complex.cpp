#include "Complex.h"

Complex Complex::operator + (const Complex& rhs)
{
	Complex result;
	result.real = real + rhs.real;
	result.image = image + rhs.image;
	return result;
}

Complex Complex::operator-(const Complex& rhs)
{
	Complex result;
	result.real = real - rhs.real;
	result.image = image - rhs.image;
	return result;
}

Complex Complex::operator*(const Complex& rhs)
{
	Complex result;
	result.real = real * rhs.real - image * rhs.image;
	result.image = real * rhs.image + image * rhs.real;
	return result;
}

Complex& Complex::operator=(const Complex& rhs)
{
	real = rhs.real;
	image = rhs.image;
	return *this;
}

ostream& operator<<(ostream& os, const Complex& lhs)
{
	if (lhs.real == 0) 
		if(lhs.image == 0)
			os << lhs.real;
		else
			os << lhs.image << "j";
	else if (lhs.image < 0) 
		if (lhs.image == 0)
			os << lhs.real;
		else
			os << lhs.real << lhs.image << "j";
	else 
		if (lhs.image == 0)
			os << lhs.real;
		else
			os << lhs.real << "+" << lhs.image << "j";	
	return os;
}