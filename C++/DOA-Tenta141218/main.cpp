#include <iostream>
#include "Rekursion.h"
#include "hr_time.h"
#include "Watch.h"
#include <vector>
#include <iomanip>

using namespace std;

struct measurement
{
	int n;
	double time;
};

int main() {
	const int MAX = 10000; //Indatats storlek n
	const int DELTA = MAX / 10; //
	const int nLoop = 10000; //Antal varv i testloopen för medelvärdesutjämning
	//PROVA: Lågt värde 100, stort värde 10000
	//       Vad kan påverka.


	vector<measurement> vTime;
	Course::Watch  w, wStartEnd;
	Course::microseconds t0, t1;

	wStartEnd.restart();
	cout.precision(2);
	cout.setf(ios::fixed);

	vTime.clear();
	for (int size = DELTA; size <= MAX; size = size + DELTA)
	{
		//Tid i tom loop
		w.restart();
		for (int i = 0; i < nLoop; i++)
		{
			;
		}
		t0 = w.elapsedUs();

		w.restart();
		for (int i = 0; i < nLoop; i++)
		{
			Betyg3::Rekursion::summa(100, 60);
		}
		t1 = w.elapsedUs();

		double time = ((t1 - t0).count() / (double)nLoop);
		std::cout << setw(20) << size << setw(20) << time << endl;
		std::cout.flush();

		measurement m = { size, time };
		vTime.push_back(m);

	}
	std::cout << "Totalt åtgången tid: " << (wStartEnd.elapsedUs().count() / 1000.0) << "ms" << endl;

	/*vTime.clear();
	for (int size = DELTA; size <= MAX; size = size + DELTA)
	{
		Tid i tom loop
		w.restart();
		for (int i = 0; i < nLoop; i++)
		{
			;
		}
		t0 = w.elapsedUs();

		w.restart();
		for (int i = 0; i < nLoop; i++)
		{
			Betyg3::Rekursion::summaRek(100, 60);
		}
		t1 = w.elapsedUs();

		double time = ((t1 - t0).count() / (double)nLoop);
		std::cout << setw(20) << size << setw(20) << time << endl;
		std::cout.flush();

		measurement m = { size, time };
		vTime.push_back(m);

	}
	std::cout << "Totalt åtgången tid: " << (wStartEnd.elapsedUs().count() / 1000.0) << "ms" << endl;*/

	cout << "SummaRek: " << Betyg3::Rekursion::summaRek(100, 10) << endl;

	system("pause");
	return 0;


}