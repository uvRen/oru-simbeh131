#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include "../forward_list/forward_list.h"

using namespace std;

class InterestTable {
private:
	forward_list<string> lista;

public:
	void Add(string intresse) {
		lista.push_front(intresse);
	}

	/*void WriteToFile() {
		ofstream ut;
		string filnamn = "intresse.txt";

		ut.open(filnamn);

		for (auto &b : lista) {
			ut << '[';
			ut << b;
			ut << ']';
			ut << endl;
		}

		ut.close();
	}*/
};