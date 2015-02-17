#pragma once
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include "../forward_list/forward_list.h"

using namespace std;

class InterestTable {
private:
	forward_list<string> intresse;

public:
	//l�gger till ett nytt intresse i vektorn
	void AddInterest(string intresse) {
		this->intresse.push_front(intresse);
	}
	
	//returnerar en str�ng med alla intressena som finns i vektorn [a, b, c ,, d]
	string toString() {
		ostringstream ut;

		forward_list<string>::iterator check = intresse.begin();

		ut << '[';
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			ut << *it;
			check = it;
			check = check + 1;
			if (check != intresse.end()) {
				ut << ',';
			}
		}
		ut << ']';

		return ut.str();
	}

	//WRITETOFILE() SKA TAS BORT
	//skriver alla intressena fr�n vektorn till en fil
	void WriteToFile() {
		ofstream ut;
		string filnamn = "InterestTable.txt";

		ut.open(filnamn);

		forward_list<string>::iterator check = intresse.begin();

		ut << '[';
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			ut << *it;
			check = it;
			check = check + 1;
			if (check != intresse.end()) {
				ut << ',';
			}
		}
		ut << ']';

		ut.close();
	}

	//READFROMFILE() SKA TAS BORT
	//l�ser in intressen fr�n en fil och l�gger i vektorn
	void ReadFromFile() {
		ifstream in;
		string str, row, filnamn;

		filnamn = "InterestTable.txt";

		try {
			in.open(filnamn);
			intresse.clear();

			while (getline(in, row)) {
				istringstream iss(row);
				getline(iss, str, '[');
				getline(iss, row, ']');
				istringstream iss2(row);
				while (getline(iss2, str, ',')) {
					intresse.push_front(str);
				}
			}
			in.close();
		}
		catch (exception e) {
			cout << "Kunde inte �ppna filen!" << endl;
		}
	}

	//skriver ut alla intressen som finns i vektorn i konsolf�nstret.
	void printList() {
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	
};