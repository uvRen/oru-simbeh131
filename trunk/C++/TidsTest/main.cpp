#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <string>

#include <array>
#include <vector>

#include <chrono>
#include <random>

#include <thread>
using namespace std;

#include "Watch.h"
#include "Console.h"
#include "hr_time.h"
using namespace Course;

#include <Windows.h>


struct measurement
{
	int n;
	double time;
};


long rfac(long n)
{
	if (n == 0)
		return 1;
	else
		return n*rfac(n - 1);
}


//Kör programmet både i DEBUG- respektive RELEASE-mod
//  Vilken blir tidskillnanden?

int main()
{
	int main_chrono(); //Prototyp till kompilatorn
	//main_chrono();   //Anrop

	int main_hr_time();
	main_hr_time();
}

int main_chrono()
{

	if (SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS) == 0)
	{
		std::cout << "Error: SetPriorityClass: " << GetLastError() << endl;
	}
	if (SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL) == 0)
	{
		std::cout << "Error: SetThreadPriority" << endl;
	}
	const int MAX = 10000; //Indatats storlek n
	const int DELTA = MAX / 10; //
	const int nLoop = 10000; //Antal varv i testloopen för medelvärdesutjämning
	//PROVA: Lågt värde 100, stort värde 10000
	//       Vad kan påverka.

	vector<measurement> vTime, vDtime, vDDtime;
	Course::Watch  w, wStartEnd;
	Course::microseconds t0, t1, t2, t3;

	wStartEnd.restart();
	std::cout.precision(8);
	std::cout.setf(ios::fixed);
	{
		std::cout << "Tisdmätning för en algoritm\n";
		std::cout << setw(20) << "n";
		std::cout << setw(20) << "tid [us]\n";

		vTime.clear();
		for (int size = DELTA; size <= MAX; size = size + DELTA)
		{
			std::array<double, MAX> v;
			std::default_random_engine dre;
			std::uniform_int_distribution<int> uid(0, 30000);

			for (int i = 0; i<v.size(); i++)
				v[i] = uid(dre);

			//Tid i tom loop
			w.restart();
			for (int i = 0; i<nLoop; i++)
			{
				;
			}
			t0 = w.elapsedUs();

			w.restart();
			for (int i = 0; i<nLoop; i++)
			{
				//Algoritm 1
				//         Vettiga värden på indatastorleken size och nLoop?
				//         Vilken komplexitet har algoritmen uttryckt i antal operationer?
				//         Vad är en operation i detta fallet?
				//         big-Oh(n) vad är vårt n? 
				int sum = 0;
				for (int j = 0; j < size; j++)
				{
					sum += v[i];
				}

				//Algoritm 2
				//         Vettiga värden på indatastorleken size och nLoop?
				//         Vilken komplexitet har algoritmen uttryckt i antal operationer?
				//         Vad är en operation i detta fallet?
				/*for (int j = 0; j < size-1; j++)
				{
				for (int k = j+1; k < size; k++)
				{
				if ( v[j] < v[k] )
				std::swap(v[j], v[k] );
				}
				}*/

				//Algoritm 3 - Fakultet
				//volatile long r = rfac(10);
			}
			t1 = w.elapsedUs();

			double time = ((t1 - t0).count() / (double)nLoop);
			std::cout << setw(20) << size << setw(20) << time << endl;
			std::cout.flush();

			measurement m = { size, time };
			vTime.push_back(m);
		}
	}

	vDtime.clear();
	for (int i = 0; i < vTime.size() - 1; i++)
	{
		measurement d = { -1, vTime[i + 1].time - vTime[i].time };
		vDtime.push_back(d);
	}

	vDDtime.clear();
	for (int i = 0; i < vDtime.size() - 1; i++)
	{
		measurement d = { -1, vDtime[i + 1].time - vDtime[i].time };
		vDDtime.push_back(d);
	}

	//Vad säger oss denna utskrift?
	//I vilka fall kan vi ha nytta av denna?
	for (int i = 0; i < vTime.size(); i++)
	{
		std::cout << setw(10) << vTime[i].n << setw(20) << vTime[i].time << endl;
		if (i < vTime.size() - 1)
		{
			std::cout << setw(40) << vDtime[i].time << endl;
			if (i < vDtime.size() - 1)
			{
				std::cout << setw(55) << vDDtime[i].time << endl;
			}
		}
	}

	std::cout.precision(2);
	std::cout.setf(ios::fixed);
	std::cout << "Totalt åtgången tid: " << (wStartEnd.elapsedMs().count() / 1000.0) << " sekunder" << endl;
	system("pause");
	return 0;
}

double find_max_in_array(double a[], int length)
{
	double max = a[0];
	for (int i = 1; i < length; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int main_hr_time()
{

	if (SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS) == 0)
	{
		std::cout << "Error: SetPriorityClass: " << GetLastError() << endl;
	}
	if (SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL) == 0)
	{
		std::cout << "Error: SetThreadPriority" << endl;
	}
	const int MAX = 10000; //Indatats storlek n
	const int DELTA = MAX / 10; //
	const int nLoop = 2; //Antal varv i testloopen för medelvärdesutjämning
	//PROVA: Lågt värde 100, stort värde 10000
	//       Vad kan påverka.

	vector<measurement> vTime, vDtime, vDDtime;
	CStopWatch  w;
	double		t0, t1, t2, t3;

	double tal[100000];

	for (int i = 0; i < 100000; i++)
		tal[i] = i;

	w.startTimer();
	std::cout.precision(8);
	std::cout.setf(ios::fixed);
	{
		std::cout << "Tisdmätning för en algoritm\n";
		std::cout << setw(20) << "n";
		std::cout << setw(20) << "tid [us]\n";

		vTime.clear();
		for (int size = DELTA; size <= MAX; size = size + DELTA)
		{
			std::array<double, MAX> v;
			std::default_random_engine dre;
			std::uniform_int_distribution<int> uid(0, 30000);

			for (int i = 0; i<v.size(); i++)
				v[i] = uid(dre);

			//Tid i tom loop
			w.startTimer();
			for (int i = 0; i<nLoop; i++)
			{
				;
			}
			w.stopTimer();
			t0 = 1e6*w.getElapsedTime();

			w.startTimer();
			for (int i = 0; i<nLoop; i++)
			{
				find_max_in_array(tal, 100000);
				//Algoritm 1
				//         Vettiga värden på indatastorleken size och nLoop?
				//         Vilken komplexitet har algoritmen uttryckt i antal operationer?
				//         Vad är en operation i detta fallet?
				//         big-Oh(n) vad är vårt n? 
				/*volatile int sum = 0;
				for (int j = 0; j < size; j++)
				{
				sum += v[i];
				}*/

				//Algoritm 2
				//         Vettiga värden på indatastorleken size och nLoop?
				//         Vilken komplexitet har algoritmen uttryckt i antal operationer?
				//         Vad är en operation i detta fallet?
				//for (int j = 0; j < size-1; j++)
				//{
				//	for (int k = j+1; k < size; k++)
				//	{
				//		if ( v[j] < v[k] )
				//			std::swap(v[j], v[k] );
				//	}
				//}

				//Algoritm 3 - Fakultet
				//volatile long r = rfac(10);
			}
			w.stopTimer();
			t1 = 1e6*w.getElapsedTime();

			double time = (t1 - t0) / (double)nLoop;
			std::cout << setw(20) << size << setw(20) << time << endl;
			std::cout.flush();

			measurement m = { size, time };
			vTime.push_back(m);
		}
	}

	vDtime.clear();
	for (int i = 0; i < vTime.size() - 1; i++)
	{
		measurement d = { -1, vTime[i + 1].time - vTime[i].time };
		vDtime.push_back(d);
	}

	vDDtime.clear();
	for (int i = 0; i < vDtime.size() - 1; i++)
	{
		measurement d = { -1, vDtime[i + 1].time - vDtime[i].time };
		vDDtime.push_back(d);
	}

	//Vad säger oss denna utskrift?
	//I vilka fall kan vi ha nytta av denna?
	for (int i = 0; i < vTime.size(); i++)
	{
		std::cout << "vTime " << setw(10) << vTime[i].n << setw(20) << vTime[i].time << endl;
		if (i < vTime.size() - 1)
		{
			std::cout << "vDTime " << setw(40) << vDtime[i].time << endl;
			if (i < vDtime.size() - 1)
			{
				std::cout << "vDDTime " << setw(55) << vDDtime[i].time << endl;
			}
		}
	}

	system("pause");
	return 0;
}