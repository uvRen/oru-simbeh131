#include <iostream>
#include <cmath>

using namespace std;

namespace Betyg3_1 {
	class Rekursion {
	public:
		/*static int fak(int n) {
			int sum = 1;
			for (int i = n; i > 0; i--) {
				sum = sum*i;
			}
			return sum;
		}

		static int fakRek(int n) {
			if (n <= 1) {
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
		}*/

		static int rekFak(int i)
		{
			if (i <= 1)
				return 1;
			else
				return i * rekFak(i - 1);
		}

		static int fak(int i)
		{
			int sum = 1;
			for (int n = 2; n <= i; n++) {
				sum *= n;
			}
			return sum;
		}

		static double summaRek(int x, int i)
		{
			return pow(x, i) / rekFak(i);
		}

		static double summa(int x, int i)
		{
			return pow(x, i) / fak(i);
		}


	};

}