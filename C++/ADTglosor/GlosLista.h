#include "Glosor.h"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class GlosLista {
private:
	string name;
	vector<Glosor<string>> l;

public:
	GlosLista() {
		name = "";
	}

	GlosLista(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	void addWord(Glosor<string> a) {
		l.push_back(a);
	}

	string List() {
		ostringstream oss;
		for (int i = 0; i < l.size(); i++)
			oss << l[i] << endl;

		return oss.str();
	}

	void writeToFile() {
		ofstream ut;
		string filnamn = this->name;
		filnamn = filnamn.append(".txt");

		ut.open(filnamn);

		ut << "Gloslista=" << this->name << endl;
		for (int i = 0; i < l.size(); i++) {
			ut << "word=" << l[i] << endl;
		}
		ut.close();
	}

	string toLowerCase(string text) {
		string ny;
		int i = 0;
		char c;
		for (int i = 0; i < text.size(); i++) {
			c = text[i];
			ny.push_back(tolower(c));
		}
		return ny;
	}

	void readFromFile() {
		ifstream in;
		string row, s, filnamn = this->name;
		filnamn = filnamn.append(".txt");

		try {
			in.open(filnamn);
			if (!in.good()) {
				cout << "Kunde inte �ppna filen!";
				return;
			}

			l.clear();

			while (getline(in, row)) {
				istringstream iss(row);
				getline(iss, s, '=');

				if (s.compare("Gloslista") == 0) {
					getline(iss, s);
				}

				else if (s.compare("word") == 0) {
					Glosor<string> a;
					iss >> a;
					l.push_back(a);
				}
			}
			in.close();
		}
		
		catch (exception e) {
			cerr << "Exception: gloslista.txt" << endl;
			cerr << e.what() << endl;
		}
	}

	void addWord() {
		string s;
		while (true) {
			Glosor<string> a;
			cout << "Ange nytt ord till gloslistan: (ord,motsvarandeOrd) avsluta med att skriva -1" << endl;
			getline(cin, s);
			if (s.compare("-1") == 0)
				break;
			istringstream iss(s);
			iss >> a;
			l.push_back(a);
		}
		writeToFile();
	}

};