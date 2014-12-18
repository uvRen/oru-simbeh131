#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
namespace Betyg3_2 {
	class Node {
	public:
		string ipnummer;
		int antal;

		Node() {
			ipnummer = "";
			antal = 0;
		}

		Node(string ipnummer) {
			this->ipnummer = ipnummer;
			antal = 1;
		}
			

		Node(string ipnummer, int antal) {
			this->ipnummer = ipnummer;
			this->antal = antal;
		}
	};

	class Lista {
	private:
		vector<Node> v;

	public:
		Lista() {

		}

		//lägger till ip adressen i listan. Finns det redan en identisk ip adressen blir antal+1
		void Add(string ipnummer) {
			if (!isInList(ipnummer)) {
				v.push_back(Node(ipnummer));
			}
		}

		//om ip adressen redan finns i listan blir antal+1. Returnerar TRUE om det finns annars FALSE
		bool isInList(string ipnummer) {
			for (vector<Node>::iterator it = v.begin(); it != v.end(); ++it) {
				if (it->ipnummer.compare(ipnummer) == 0) {
					it->antal++;
					return true;
				}
			}
			return false;
		}

		//läser ip adresser från fil och placerar i vectorn
		void ReadFromFile() {
			ifstream in;
			string row, str;

			try {
				in.open("ip.txt");
				if (!in.good()) {
					cout << "Det gick inte att öppna filen!" << endl;
				}
				else {
					v.clear();

					while (getline(in, row)) {
						istringstream iss(row);
						getline(iss, str, ' ');
						
						Add(str);
					}
				}
			}

			catch (exception e) {

			}

		}

		void printList() {
			for (vector<Node>::iterator it = v.begin(); it != v.end(); ++it) {
				cout << it->ipnummer << " " << it->antal << endl;
			}
		}
	};
}