#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>

using namespace std;

class statistics {
private:
	array<int, 10000001> v;

public:

	statistics() {
		clear();
	}
	
	void clear() {
		for (int i = 0; i < v.size(); i++) {
			v[i] = 0;
		}
	}

	void ReadFromFile() {
		ifstream in;
		string row;
		int tal;

		try {
			in.open("salary.txt");
			if (!in.good()) {
				cout << "Kunde inte öppna filen!" << endl;
			}
			else {
				clear();
				while (getline(in, row)) {
					tal = stoi(row);
					if (tal >= 20000 && tal <= 10000000) {
						v[tal]++;
					}
				}
			}
			in.close();
		}

		catch (exception e) {

		}
	}

	int calculate_mean() {
		long long int sum = 0;
		int antal = 0;

		for (int i = 20000; i < v.size(); i++) {
			sum = sum + (i * v[i]);
			antal += v[i];
		}
		return sum/antal;
	}
};