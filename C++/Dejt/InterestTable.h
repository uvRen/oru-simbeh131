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
	void AddInterest(string intresse) {
		this->intresse.push_front(intresse);
	}
	
	string toString() {
		ostringstream ut;

		forward_list<string>::iterator check = intresse.begin();

		ut << '[';
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			ut << *it;
			check = it;
			check++;
			if (check != intresse.end()) {
				ut << ',';
			}
		}
		ut << ']';

		return ut.str();
	}

	void WriteToFile() {
		ofstream ut;
		string filnamn = "InterestTable.txt";

		ut.open(filnamn);

		forward_list<string>::iterator check = intresse.begin();

		ut << '[';
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			ut << *it;
			check = it;
			check++;
			if (check != intresse.end()) {
				ut << ',';
			}
		}
		ut << ']';

		ut.close();
	}

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
			cout << "Kunde inte öppna filen!" << endl;
		}
	}

	void printList() {
		for (forward_list<string>::iterator it = intresse.begin(); it != intresse.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	
};