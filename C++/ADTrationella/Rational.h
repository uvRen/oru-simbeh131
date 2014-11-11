#pragma once
#include <iostream>

using namespace std;

namespace Simon {
	namespace adt {

		template<class T>
		class Rational {
		private:
			T taljare;
			T namnare;

		public:
			//konstruktor
			Rational(void) {
				taljare = 0;
				namnare = 0;
			}

			Rational(T taljare, T namnare) {
				this->taljare = taljare;
				this->namnare = namnare;
			}

			//medlemsfunktioner
			void print_rational() {
				cout << taljare << '/' << namnare << endl;
			}
			
			friend Rational<T> operator+(const Rational<T> &left, const Rational<T> &right) {
				Rational<T> a;
				if (left.namnare != right.namnare) {
					a.namnare = left.namnare * right.namnare;
					a.taljare = left.taljare * right.namnare;
					a.taljare = a.taljare + (right.taljare * left.namnare);
				}

				return a;
			}

			friend ostream& operator<<(ostream &ut, const Rational<T> &r) {
				ut << r.taljare << '/' << r.namnare;
				return ut;
			}
		};
	}
}