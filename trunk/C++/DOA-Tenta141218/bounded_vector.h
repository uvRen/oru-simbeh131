#include <iostream>
#include <exception>

using namespace std;

namespace Betyg4 {
	class bounded_vector {
	private:
		int lowIndex;
		int highIndex;
		int *vptr;
		int size;

	public:
		//konstruktor
		bounded_vector() {
			vptr = nullptr;
			lowIndex = highIndex = size = -1;
		}

		bounded_vector(int lowIndex, int highIndex) {
			this->highIndex = highIndex;
			this->lowIndex = lowIndex;
			this->size = highIndex - lowIndex + 1;

			vptr = new int[size];
			for (int i = 0; i < size; i++) {
				vptr[i] = 0;
			}
		}

		//kopieringkonstruktor
		bounded_vector(const bounded_vector &obj) {
			this->highIndex = obj.highIndex;
			this->lowIndex = obj.lowIndex;
			this->size = obj.size;

			this->vptr = new int[size];
			for (int i = 0; i < size; i++) {
				this->vptr[i] = obj.vptr[i];
			}
		}

		//dekonstruktor
		~bounded_vector() {
			delete[] vptr;
		}

		//kopiering
		bounded_vector& operator=(const bounded_vector &right) {
			this->highIndex = right.highIndex;
			this->lowIndex = right.lowIndex;
			this->size = right.size;

			this->vptr = new int[size];
			for (int i = 0; i < size; i++) {
				this->vptr[i] = right.vptr[i];
			}
			return *this;
		}

		friend bounded_vector& operator+(const bounded_vector &left, const bounded_vector &right) {
			if (left.size != right.size || left.lowIndex != right.lowIndex || left.highIndex != right.highIndex) {
				throw exception("Vektorerna matchar inte varadndra");
			}
			bounded_vector a(left.lowIndex, left.highIndex);
			for (int i = 0; i < left.size; i++) {
				a.vptr[i] = left.vptr[i] + right.vptr[i];
			}

			return a;
		}

		int total_sum() {
			int summa = 0;

			for (int i = 0; i < this->size; i++) {
				summa += this->vptr[i];
			}
			return summa;
		}

		void print() {
			char c = lowIndex;

			for (int i = 0; i < size; i++) {
				cout << c << ": " << this->vptr[i] << endl;
				c++;
			}
		}
		
	};
	

}