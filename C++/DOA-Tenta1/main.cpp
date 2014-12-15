#include <iostream>
#include <deque>
#include <string>
#include <clocale>
#include "statistics.h"
#include "words.h"

using namespace std;

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
		/*if (s[storlek - 1] != s[s.size() - 1 - (storlek - 1)]) {
			return false;
		}
		if ((storlek - 1) == ((s.size() - 1) / 2)) {
			return true;
		}
		palindromRek(s, storlek - 1);*/

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
}


int main() {
	setlocale(LC_ALL, "swedish");
	/*Betyg3::main1_1();
	Betyg3::main1_2();
	Betyg3::main();*/

	words w;

	w.ReadFromFile();

	pair<string, int> a;
	a = w.getMostFrekventWord();

	w.printMap();

	cout << "Det vanligaste ordet är '" << get<0>(a) << "' och förekommer " << get<1>(a) << " gånger." << endl << endl << endl << endl;


	// 65 -> 90  A-Z 
	// 97 -> 122 a-z
	// 10 27 28

	
	system("pause");
	return 0;
}
