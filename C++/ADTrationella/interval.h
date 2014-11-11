#pragma once

#include <iostream>
using namespace std;


namespace Course
{
	namespace adt
	{
		template<class T>
		class interval
		{
		private:
			T upper;
			T lower;
		public:

			interval(void)
			{
				lower = upper = 0;
			}

			interval(T mean, double procent)
			{
				lower = (T)(mean - mean * procent / 100); //Lätt att glömma (T), krävs då  är int
				upper = (T)(mean + mean * procent / 100);
			}

			T mean()
			{
				return (lower + upper) / 2;
			}

			double relative_error()
			{
				return (upper - lower) / mean(); //Fungerar ej så bra för int
			}

			void print_relative()
			{
				cout << "mean=" << mean() << ", relative error = " << relative_error() << endl;
			}

			friend interval<T> operator+(const interval<T> &lop, const interval<T> &rop)
			{
				interval<T> m;

				m.upper = lop.upper + rop.upper;
				m.lower = lop.lower + rop.lower;
				return m;
			}

			friend ostream& operator<<(ostream &out, const interval<T> &rop)
			{
				out << "[" << rop.lower << "," << rop.upper << "]";
				return out;
			}

			~interval(void)
			{
			}
		};
	}
}

