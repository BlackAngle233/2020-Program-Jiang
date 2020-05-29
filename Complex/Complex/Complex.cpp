#include<iostream>
#include"math.h"
#include"Complex.h"
using namespace std;

double Complex::abs() {
	return sqrt(real * real + image * image);
}

Complex operator+(const Complex& c1, const Complex& c2) {
	return{ c1.real + c2.real,c1.image + c2.image };
}

Complex operator-(const Complex& c1, const Complex& c2) {
	return{ c1.real - c2.real,c1.image - c2.image };
}

Complex operator*(const Complex& c1, const Complex& c2) {
	return{ c1.real*c2.real - c1.image*c2.image,c1.real*c2.image + c1.image*c2.real };
}

Complex operator/(const Complex& c1, const Complex& c2) {
	double x, y;
	double m;
	m = pow(c2.real, 2) + pow(c2.image, 2);
	x = (c1.real*c2.real + c1.image*c2.image)/m;
	y = (c1.image*c2.real - c1.real*c2.image) / m;
	return{ x,y };
}

bool operator==(const Complex& c1, const Complex& c2) {
	if (c1.real == c2.real&&c1.image == c2.image)return true;
	else return false;
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex& Complex::operator++(int flag) {
	Complex nb{real,image};
	real++;
	return nb;
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex& Complex::operator--(int flag) {
	Complex nb{ real,image };
	real--;
	return nb;
}

Complex& Complex::operator+=(const Complex& other) {
	real += other.real;
	image += other.image;
	return *this;
}

Complex& Complex::operator-=(const Complex& other) {
	real -= other.real;
	image -= other.image;
	return *this;
}

Complex& Complex::operator*=(const Complex& other) {
	double r, i;
	r = real;
	i = image;
	real = r*other.real - i * other.image;
	image = r*other.image + i*other.real;
	return *this;
}

Complex& Complex::operator/=(const Complex& other) {
	double m,r, i;
	r = real;
	i = image;
	m = pow(other.real, 2) + pow(other.image, 2);
	real = (r*other.real + i*other.image) / m;
	image = (i*other.real - r*other.image) / m;
	return *this;
}

void Complex::print() {
	if(real==0){ 
		if(image==0)cout << "虚数为：" << real<< endl;
		else cout << "虚数为：" << image << 'i' << endl; 
	}
	else {
		if (image > 0) {
			cout << "虚数为：" << real << '+' << image << 'i' << endl;
		}
		else if(image<0){
			cout << "虚数为：" << real << '-' << -image << 'i' << endl;
		}
			else {
				cout << "虚数为：" << real << endl;
		}
	}
}