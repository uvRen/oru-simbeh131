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
	int antal;

public:
	statistics() {
		antal = 0;
		for (int i = 0; i < v.size(); i++) {
			v[i] = bucket();
		}
	}

	void clear() {
		for (int i = 0; i < v.size(); i++) {
			v[i] = bucket();
		}
	}

	void printArray() {
		for (int i = 0; i < v.size(); i++) {
			cout << "Index: " << i << " -> " << v[i].key << "  " << v[i].antal << endl;;
		}
	}

	void ReadFromFile() {
		ifstream in;
		string row, str;
		int tal = 0;
		int index;

		hash<string> h;

		try {
			in.open("salary.txt");
			clear();

			while (getline(in, row)) {
				istringstream iss(row);
				tal = stoi(row);
				if (tal >= 20000 && tal <= 10000000) {
					index = h(row);
					index = index % arraySize;
					if (index < 0) {
						index = index * -1;
					}
					v[index].key = tal;
					v[index].antal = v[index].antal + 1;
					antal++;
				}
			}
		}

		catch (exception e) {

		}
	}
};