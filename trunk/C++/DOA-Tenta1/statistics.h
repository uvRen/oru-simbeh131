#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>

using namespace std;

static const int arraySize = 1000003;

struct bucket {
	int key;
	int antal;

	bucket() {
		key = antal = 0;
	}

	bucket(int key, int antal) {
		this->key = key;
		this->antal = antal;
	}
};

class statistics {
private:
	array<bucket, arraySize> v;

public:
	statistics() {
		for (int i = 0; i < v.size(); i++) {
			v[i] = bucket();
		}
	}

	void clear() {
		for (int i = 0; i < v.size(); i++) {
			v[i] = bucket();
		}
	}

	void ReadFromFile() {
		ifstream in;
		string row, str;

		try {
			in.open("salary.txt");
			clear();

			while (getline(in, row)) {
				istringstream iss(row);
			}
		}

		catch (exception e) {

		}
	}
};