#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

class Interest {
private:
	vector<string> lista;

public:
	Interest() {

	}
	
	void Add(string intresse) {
		lista.push_back(intresse);
	}

	void WriteToFile() {
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
	}
};