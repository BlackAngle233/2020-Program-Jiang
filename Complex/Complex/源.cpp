class Complex {
public:
	Complex(int a = 0, int b = 0) { n = a, d = b; }
	Complex operator =(Complex&);
	Complex operator ++();
	Complex operator ++(int);
	Complex operator --();
	Complex operator --(int);
	friend Complex operator +(const Complex&, const Complex&);
	friend Complex operator -(const Complex&, const Complex&);
	friend Complex operator *(const Complex&, const Complex&);
	friend Complex operator /(const Complex&, const Complex&);
	int getN() {
		return n;
	}
	int getD() {
		return d;
	}
private:
	int n;
	int d;
};
Complex Complex::operator =(Complex& a) {
	n = a.n; d = a.d;
	return *this;
}
Complex operator +(const Complex& a, const Complex& b) {
	int n, d;
	n = a.n + b.n;
	d = a.d + b.d;
	return Complex(n, d);
}
Complex operator -(const Complex& a, const Complex& b) {
	return Complex(a.n - b.n, a.d - b.d);
}
Complex operator *(const Complex& a, const Complex& b) {
	return Complex((a.n * b.n) - (a.d * b.d), (a.n * b.d) + (a.d * b.n));
}
Complex operator /(const Complex& a, const Complex& b) {
	return Complex(((a.n * b.n) + (a.d * b.d)) / (b.n * b.n + b.d * b.d), (a.d * b.n - a.n * b.d) / (b.n * b.n + b.d * b.d));
}

Complex Complex::operator ++() {
	n++; d++;
	return *this;
}
Complex Complex::operator ++(int) {
	Complex temp;
	temp.n = n++;
	temp.d = d++;
	return temp;
}
Complex Complex::operator --() {
	n--; d--;
	return *this;
}
Complex Complex::operator --(int) {
	Complex temp;
	temp.n = n--;
	temp.d = d--;
	return temp;
}