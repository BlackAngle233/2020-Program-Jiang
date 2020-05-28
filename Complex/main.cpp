#include"Complex.h"

int main() {
	Complex a = Complex(1, 2);
	Complex b = Complex(3, 4);
	Complex c = a + b;
	std::cout << "a+b=" << std::endl;
	c.printf();
	c = a - b;
	std::cout << "a-b=" << std::endl;
	c.printf();
	c = a * b;
	std::cout << "a*b=" << std::endl;
	c.printf();
	c = a / b;
	std::cout << "a/b=" << std::endl;
	c.printf();
	c += a;
	std::cout << "c+a=" << std::endl;
	c.printf();
	c -= a;
	std::cout << "c-a=" << std::endl;
	c.printf();
	c *= a;
	std::cout << "c*a=" << std::endl;
	c.printf();
	c /= a;
	std::cout << "c/a=" << std::endl;
	c.printf();
	std::cout << "c++=" << std::endl;
	c.operator++();
	c.printf();
	std::cout << "c--=" << std::endl;
	c.operator--();
	c.printf();
}