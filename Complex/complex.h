#ifndef _Complex_H_
#define _Complex_H_

#include<iostream>
using namespace std;
class Complex
{
public:
 Complex(float real = 1, float imag = 1):_real(real), _imag(imag){}
 Complex(const Complex& complex);
 ~Complex(){};
 Complex& operator=(const Complex& complex);
 
 bool operator==(const Complex& complex);
 bool operator!=(const Complex& complex);
 Complex operator+(const Complex& complex);
 Complex& operator++();//前置++
 Complex operator++(int);//后置++
 Complex& operator+=(const Complex& complex);
 Complex operator-(const Complex& complex);
 Complex& operator-=(const Complex& complex);
 Complex& operator--();//前置--
 Complex operator--(int);//后置--
 Complex operator*(const Complex& complex);
 Complex& operator*=(const Complex& complex);
 Complex operator/(const Complex& complex);
 Complex& operator/=(const Complex& complex);
 friend ostream& operator<<(ostream& output, const Complex& complex);
private:
 float _real;
 float _imag;
};

#endif