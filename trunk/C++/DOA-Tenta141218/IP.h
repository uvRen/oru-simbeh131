#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
					it->antal = it->antal + 1;
					return true;
				}
			}
			return false;
		}

		//läser ip adresser från fil och placerar i vectorn
		void ReadFromFile() {
			ifstream in;
			string row, str, dump;

			try {
				in.open("ip_one.txt");
				if (!in.good()) {
					cout << "Det gick inte att öppna filen!" << endl;
				}
				else {
					v.clear();

					while (getline(in, row)) {
						istringstream iss(row);
						getline(iss, str, ' ');
						getline(iss, dump);
						
						Add(str);
					}
				}
			}

			catch (exception e) {

			}

		}

		bool stringCompare(const string &left, const string &right) {
			for (string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit)
				if (tolower(*lit) < tolower(*rit))
					return true;
				else if (tolower(*lit) > tolower(*rit))
					return false;
			if (left.size() < right.size())
				return true;
			return false;
		}

		void sortList() {
			sort(v.begin(), v.end(), stringCompare);
		}

		void printList() {
			for (vector<Node>::iterator it = v.begin(); it != v.end(); ++it) {
				cout << it->ipnummer << " " << it->antal << endl;
			}
		}
	};
}