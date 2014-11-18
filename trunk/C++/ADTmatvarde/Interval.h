#pragma once
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class Interval {
private:
	T upper;
	T lower;

public:
	Interval() {
		upper = 0;
		lower = 0;
	}

	Interval(T value, double percent) {
		upper = (T)value + ((T)value * (percent / 100));
		lower = (T)value - ((T)value * (percent / 100));
	}

	friend ostream& operator<<(ostream &ut, const Interval<T> &a) {
		ut << '[' << a.upper << ',' << a.lower << ']';
		return ut;
	}

	friend Interval<T> operator+(const Interval<T> &left, const Interval<T> &right) {
		Interval<T> a;

		a.upper = left.upper + right.upper;
		a.lower = left.lower + right.lower;

		return a;
	}

	friend Interval<T> operator-(const Interval<T> &left, const Interval<T> &right) {
		Interval<T> a;

		a.upper = left.upper - right.upper;
		a.lower = left.lower - right.lower;

		return a;
	}

	friend Interval<T> operator*(const Interval<T> &left, const Interval<T> &right) {
		Interval<T> a;

		auto result = minmax({ left.upper*right.upper, left.upper*right.lower, left.lower*right.upper, left.lower*right.lower });
		a.lower = result.first;
		a.upper = result.second;

		return a;
	}

	friend Interval<T> operator/(const Interval<T> &left, const Interval<T> &right) {
		Interval<T> a;

		auto result = minmax({ left.upper/right.upper, left.upper/right.lower, left.lower/right.upper, left.lower/right.lower });
		a.lower = result.first;
		a.upper = result.second;

		return a;
	}
};