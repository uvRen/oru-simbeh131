#include "Student.h"
#include <vector>
#include <clocale>
#include <fstream>

using namespace std;

class Studentregister {

private:
	string school;
	vector<Student> s;

public:
	//konstruktor
	Studentregister(void) {
		school = "";
	}

	//medlemsfunktioner
	string getSchool() { return school; }
	void setSchool(string school) { this->school = school; }

	void Add(Student s) {
		this->s.push_back(s);
	}

	string List() {
		ostringstream oss;

		for (int i = 0; i < s.size(); i++) {
			oss << s[i] << endl;
		}
		return oss.str();
	}

	void WriteToFile() {
		ofstream out;
		out.open("studenter.txt");

		out << "Skola=" << this->school << endl;

		for (int i = 0; i < s.size(); i++) {
			out << "Student=" << s[i] << endl;
		}
		out.close();
	}

	void ReadFromFile(string filnamn) {
		ifstream in;
		string str, strRow;

		try {
			if (!in.good()) {
				cout << "Gick ej att öppna filen!" << endl;
				return;
			}

			s.clear();

			while (getline(in, strRow)) {
				istringstream iss(strRow);
				getline(iss, str, '=');

				if (str.compare("Skola") == 0) {
					getline(iss, this->school);
				}

				else if (str.compare("Student") == 0) {
					Student a;
					iss >> a;
					s.push_back(a);
				}
			}
			in.close();
		}

		catch (exception e) {
			cerr << "Exception: " << filnamn << endl;
			cerr << e.what() << endl;
		}
	}
};