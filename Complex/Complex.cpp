#include"Complex.h"
#include<math.h>

double Complex::getLength() {
	return sqrt(pow(_r, 2) + pow(_i, 2));
}

Complex operator +(Complex& a, Complex& b) {
	return Complex(a.getR() + b.getR(), a.getI() + b.getI());
}
Complex operator -(Complex& a, Complex& b) {
	return Complex(a.getR() - b.getR(), a.getI() - b.getI());
}
Complex operator *(Complex& a, Complex& b) {
	return Complex(a.getR()*b.getR()- a.getI()*b.getI(), a.getI()*b.getR()+a.getR()*b.getI());
}
Complex operator /(Complex& a, Complex& b) {
	if (b.getI() == 0 && b.getR() == 0) {
		std::cout << "diviser is zero,the formula can't be calculated." << std::endl;
		return a;
	}
	double r, i;
	r = (a.getR() * b.getR() + a.getI() * b.getI()) / (pow(b.getR(), 2) + pow(b.getI(), 2));
	i = (a.getI() * b.getR() - a.getR() * b.getI()) / (pow(b.getR(), 2) + pow(b.getI(), 2));
	return Complex(r, i);
}
Complex& Complex::operator++() {
	_r++;
	return *this;
}
Complex& Complex::operator++(int) {
	Complex temp = *this;
	_r++;
	return temp;
}
Complex& Complex::operator--() {
	_r--;
	return *this;
}
Complex& Complex::operator--(int) {
	Complex temp = *this;
	_r--;
	return temp;
}
Complex& Complex::operator+=(Complex& other) {
	_r += other.getR();
	_i += other.getI();
	return *this;
}
Complex& Complex::operator-=(Complex& other) {
	_r -= other.getR();
	_i -= other.getI();
	return *this;
}
Complex& Complex::operator*=(Complex& other) {
	double r, i;
	r = _r * other.getR() - _i * other.getI();
	i = _i * other.getR() + _r * other.getI();
	_r = r;
	_i = i;
	return *this;
}
Complex& Complex::operator/=(Complex& other) {
	double r, i;
	r = (_r * other.getR() + _i * other.getI()) / (pow(other.getR(), 2) + pow(other.getI(), 2));
	i = (_i * other.getR() - _r * other.getI()) / (pow(other.getR(), 2) + pow(other.getI(), 2));
	_r = r;
	_i = i;
	return *this;
}

void Complex::printf(){
	if (_i > 0)
		std::cout << _r << '+' << _i << 'i' << std::endl;
	else if (_i == 0)
		std::cout << _r << std::endl;
	else
		std::cout << _r << '-' << -_i << 'i' << std::endl;
}