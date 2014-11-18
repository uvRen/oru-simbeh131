#pragma once
#include <sstream>
#include <iostream>

using namespace std;

template<class T>
class Complex {
private:
	T re, im;

public:
	Complex() {
		re = im = 0;
	}
	Complex(T re, T im) {
		this->re = re;
		this->im = im;
	}

	friend Complex<T> operator*(const Complex<T> &left, const Complex<T> &right) {
		Complex<T> a;

		a.re = left.re * right.im;
		a.im = left.re * right.im;

		return a;
	}

	friend ostream& operator<<(ostream &ut, const Complex<T> &c) {
		if (c.im >= 0)
			ut << '(' << c.re << '+' << c.im << 'i' << ')';
		else
			ut << '(' << c.re << c.im << 'i' << ')';

		return ut;
	}
};