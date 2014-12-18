#include <iostream>
#include <cmath>

using namespace std;

namespace Betyg3 {
	class Rekursion {
	public:
		static int fak(int n) {
			int sum = 1;
			for (int i = n; i > 0; i--) {
				sum = sum*i;
			}
			return sum;
		}

		static int fakRek(int n) {
			if (n == 0) {
				return 1;
			}
			else {
				return n * fakRek(n - 1);
			}
		}

		static double summa(double x, int n) {
			double sum = 0;
			for (int i = n; i >= 0; i--) {
				sum = sum + pow(x, i) / fak(i);
			}
			return sum;
		}

		static double summaRek(double x, int n) {
			if (n == 0) {
				return 1;
			}
			else {
				double sum = 0;
				sum = pow(x, n) / fakRek(n);

				return sum + summaRek(x, fakRek(n - 1));
			}
		}
	};

}