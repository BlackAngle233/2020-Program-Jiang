#include "complex.h"

Complex::Complex(const Complex& complex)//拷贝构造函数
{
 _real = complex._real;
 _imag = complex._imag;
}
 
Complex& Complex::operator=(const Complex& complex)//赋值操作符重载
{
 cout << "赋值操作符重载" << endl;
 if (this != &complex)
 {
  _real = complex._real;
  _imag = complex._imag;
 }
 return *this;
}
 
ostream& operator<<(ostream& output, const Complex& complex)//输出操作符重载
{
  output << "(" << complex._real;
 if (complex._imag >= 0)
 {
  output << "+";
 }
 output << complex._imag << "i)";
  return output;
}

bool Complex::operator==(const Complex& complex)
{
 return (_real == complex._real) && (_imag == complex._imag);
}

bool Complex::operator!=(const Complex& complex)
{
 return !(*this==complex);
}
 
Complex Complex::operator+(const Complex& complex)
{
 Complex c(*this);
 c._real +=complex._real;
 c._imag +=complex._imag;
 return c;
}
 
Complex& Complex::operator++()
{
 ++_real;
 return *this;
}
 
Complex Complex::operator++(int)
{
 Complex c;
 c._real=_real++;
 return c; 
}
 
Complex& Complex::operator+=(const Complex& complex)
{
 _real += complex._real;
 _imag += complex._imag;
 return *this;
}
 
Complex Complex::operator-(const Complex& complex)
{
 return Complex(_real - complex._real, _imag - complex._imag);
}
 
Complex& Complex::operator-=(const Complex& complex)
{
 _real -= complex._real;
 _imag -= complex._imag;
 return *this;
}
 
Complex& Complex::operator--()
{
 --_real;
 return *this;
}
 
Complex Complex::operator--(int)
{
 Complex c;
 c._real=_real--;
 return c;
}
 
Complex Complex::operator*(const Complex& complex)
{
 Complex c;
 c._real = _real*complex._real - _imag*complex._imag;
 c._imag = _real*complex._imag + _imag*complex._real;
 return c;
}
 
Complex& Complex::operator*=(const Complex& complex)
{
 float real = _real;
 _real = _real*complex._real - _imag*complex._imag;
 _imag = _imag*complex._real + real*complex._imag;
 return *this;
}
 
Complex Complex::operator/(const Complex& complex)
{
 return Complex((_real*complex._real + _imag*complex._imag) / 
                   (complex._real*complex._real + complex._imag*complex._imag),
       (_imag*complex._real - _real*complex._imag)/
       (complex._real*complex._real + complex._imag*complex._imag));
}
 
Complex& Complex::operator/=(const Complex& complex)
{
 float real = _real;
 _real = (_real*complex._real + _imag*complex._imag)/
 (complex._real*complex._real + complex._imag*complex._imag);
 _imag = (_imag*complex._real - real*complex._imag) /
 (complex._real*complex._real + complex._imag*complex._imag);
 return *this;
}