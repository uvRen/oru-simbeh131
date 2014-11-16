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
					if (left.namnare < right.namnare) { // 1/2 + 4/4 = 6/4
						if (right.namnare % left.namnare == 0) {
							a.taljare = right.taljare + (left.taljare * (right.namnare / left.namnare));
							a.namnare = right.namnare;
						}
						else { //hitta gemensama nämnare
							a.namnare = left.namnare * right.namnare;
							a.taljare = left.taljare * right.namnare;
							a.taljare = a.taljare + (right.taljare * left.namnare);
						}
					}
					else {  // 4/4 + 1/2 = 6/4
						if (left.namnare % right.namnare == 0) {
							a.taljare = left.taljare + (right.taljare * (left.namnare / right.namnare));
							a.namnare = left.namnare;
						}
						else { //hitta gemensama nämnare
							a.namnare = left.namnare * right.namnare;
							a.taljare = left.taljare * right.namnare;
							a.taljare = a.taljare + (right.taljare * left.namnare);
						}
					}
				}
				else {
					a.taljare = left.taljare + right.taljare;
					a.namnare = left.namnare + right.namnare;
				}
				return a;
			}

			friend Rational<T> operator-(const Rational<T> &left, const Rational<T> &right) {
				Rational<T> a;
				if (left.namnare != right.namnare) {
					if (left.namnare < right.namnare) { // 1/2 - 1/4 = 1/4
						if (right.namnare % left.namnare == 0) {
							a.taljare = (left.taljare * (right.namnare / left.namnare)) - right.taljare;
							a.namnare = right.namnare;
						}
						else { //hitta gemensama nämnare
							a.namnare = left.namnare * right.namnare;
							a.taljare = left.taljare * right.namnare;
							a.taljare = a.taljare - (right.taljare * left.namnare);
						}
					}
					else {  // 1/4 - 1/2 = -1/4
						if (left.namnare % right.namnare == 0) {
							a.taljare = left.taljare - (right.taljare * (left.namnare / right.namnare));
							a.namnare = left.namnare;
						}
						else { //hitta gemensama nämnare
							a.namnare = left.namnare * right.namnare;
							a.taljare = left.taljare * right.namnare;
							a.taljare = a.taljare - (right.taljare * left.namnare);
						}
					}
				}
				else {
					a.taljare = left.taljare - right.taljare;
					a.namnare = left.namnare - right.namnare;
				}
				return a;
			}

			friend Rational<T> operator*(const Rational<T> &left, const Rational<T> &right) {
				Rational<T> a;
				a.taljare = left.taljare * right.taljare;
				a.namnare = left.namnare * right.namnare;

				return a;
			}

			friend Rational<T> operator/(const Rational<T> &left, const Rational<T> &right) {
				Rational<T> a;
				Rational<T> b;

				b.taljare = right.namnare;
				b.namnare = right.taljare;

				a.taljare = left.taljare * b.taljare;
				a.namnare = left.namnare * b.namnare;

				return a;
			}

			friend ostream& operator<<(ostream &ut, const Rational<T> &r) {
				ut << r.taljare << '/' << r.namnare;
				return ut;
			}
		};
	}
}