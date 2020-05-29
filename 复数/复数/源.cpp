#include<iostream>

using namespace std;


class complex {	//....private:	double re;	double im;public:	constexpr double real() const { return re; }	constexpr double imag() const { return im; }	complex(double r = 0, double i = 0)		: re{ r }, im{ i }	{ }	complex& operator+= (double a)	{		re += a;		return *this;	}		bool operator==(complex b)	{		if (re == b.real() && im == b.imag())			return true;		else			return false;	}	// ....	complex operator+(double b)	{		return { re + b, im };	}	complex operator+(complex b)	{		return { re + b.real() , im + b.imag };	}	complex operator-(double b)	{		return { re - b, im };	}	complex operator-(complex b)	{		return { re - b.real() , im - b.imag };	}	complex operator*(complex& c);
	complex operator/(complex& c);
};

complex complex::operator*(complex& c)
{
	complex mul;
	mul.re = re * (c.real()) - im * (c.imag());
	mul.im = im * (c.real()) + re * (c.imag());
	return mul;
}

complex complex::operator/(complex& c)
{
	//(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
	complex div;
	div.re = (re*c.real() + im * c.imag()) / (c.real()*c.real() + c.imag()*c.imag());
	div.im = (im*c.real - re * c.imag) / (c.real*c.real + c.imag()*c.imag());
	return div;
}


int main()
{
	system("pause");
	return 0;
}