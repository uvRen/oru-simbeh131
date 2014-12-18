#include <iostream>
#include <cmath>

using namespace std;

namespace Betyg3_1 {
	class Rekursion {
	public:
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
			if (i == 0)
				return 1;

			double sum = pow(x, i) / rekFak(i);
			return sum + summaRek(x, i-1);
		}

		static double summa(int x, int n)
		{
			double sum = 0;
			for (int i = n; i >= 0; i--) {
				sum = sum + (pow(x, i) / fak(i));
			}
			return sum;
		}


	};

}