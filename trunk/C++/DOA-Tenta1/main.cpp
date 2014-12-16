#include <iostream>
#include <deque>
#include <string>
#include <clocale>
#include "statistics.h"
#include "words.h"
#include "Watch.h"
#include <chrono>
#include <vector>
#include <iomanip>
#include "unordered_list.h"
#include "hashtable.h"

using namespace std;

struct measurement
{
	int n;
	double time;
};

//funktioner
namespace Betyg3 {
	bool palindrom(string s) {
		deque<char> text;
		int i = 0;

		for (i = 0; i < s.size(); i++) {
			text.push_back(s[i]);
		}

		for (i = 0; i < (s.size() / 2); i++) {
			if (text.back() != text.front()) {
				return false;
			}
			text.pop_front();
			text.pop_back();
		}
		return true;
	}

	bool palindromRek(string s, int storlek) {
		if ((storlek - 1) == ((s.size() - 1) / 2)) {
			return true;
		}
		else {
			if (s[storlek - 1] == s[s.size() - 1 - (storlek - 1)]) {
				return palindromRek(s, storlek - 1);
			}
			else {
				return false;
			}
		}
	}

	void main1_1() {
		string hej = "kajak";
		int a;
		a = palindrom(hej);
		if (a == 1) {
			cout << hej << " = palindrom" << endl;
		}
		else {
			cout << hej << " != palindrom" << endl;
		}
	}

	void main1_2() {
		string hej = "kajak";
		if (palindromRek(hej, hej.size())) {
			cout << hej << " = palindrom" << endl;
		}
		else {
			cout << hej << " != palindrom" << endl;
		}
	}

	void main2() {
		statistics lista;

		lista.ReadFromFile();

		cout << "MEAN: " << lista.calculate_mean() << endl;
	}

	void main3_1() {
		words ord;
		ord.ReadFromFile();
		pair<string, int> a;
		a = ord.getMostFrekventWord();

		cout << "Det vanligaste ordet är '" << get<0>(a) << "' och förekommer " << get<1>(a) << " gånger." << endl << endl << endl << endl;
	}

	void main3_2() {
		const int MAX = 10000; //Indatats storlek n
		const int DELTA = MAX / 10; //
		const int nLoop = 2; //Antal varv i testloopen för medelvärdesutjämning
		//PROVA: Lågt värde 100, stort värde 10000
		//       Vad kan påverka.


		vector<measurement> vTime;
		Course::Watch  w, wStartEnd;
		Course::milliseconds t0, t1;

		wStartEnd.restart();
		cout.precision(2);
		cout.setf(ios::fixed);

		for (int size = 1; size <= 5; size++) {
			w.restart();
			for (int i = 0; i < nLoop; i++) {
				words ord;
				ord.ReadFromFile();
				pair<string, int> a;
				a = ord.getMostFrekventWord();
			}
			t0 = w.elapsedMs();

			double time = (t0.count() / (double)nLoop);
			std::cout << setw(20) << size << setw(20) << time << "ms" << endl;
			std::cout.flush();

			measurement m = { size, time };
			vTime.push_back(m);
		}

		t1 = wStartEnd.elapsedMs();

		cout << "Totalt åtgången tid: " << (wStartEnd.elapsedMs().count() / 1000.0) << " sekunder" << endl;
	}
}

using namespace Betyg4;

void main4() {
	unordered_list lista(1000);

	lista.ReadFromFile();

	pair<string, int> a;
	a = lista.findMostFrekventWord();

	cout << "Det ord som förekommer flest gånger är '" << a.first << "' och förekommer " << a.second << " gånger." << endl;
}


using namespace std;
int main() {
	setlocale(LC_ALL, "swedish");
	/*Betyg3::main1_1();
	Betyg3::main1_2();
	Betyg3::main2();

	Betyg3::main3_1();
	Betyg3::main3_2();*/

	//main4();

	Betyg5::HashTable<string, string> h(769);

	system("pause");
	return 0;
}
