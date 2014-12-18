#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;
namespace Betyg3_2 {
	struct data_pq {
		string ipnummer;
		int antal;

		data_pq(string ipnummer, int antal) {
			this->ipnummer = ipnummer;
			this->antal = antal;
		}

		friend bool operator<(const data_pq &left, const data_pq &right) {
			return left.antal < right.antal;
		}
	};

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

		friend bool operator<(const Node &l, const Node &r) {
			string left = l.ipnummer;
			string right = r.ipnummer;
			for (string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit)
				if (tolower(*lit) < tolower(*rit))
					return true;
				else if (tolower(*lit) > tolower(*rit))
					return false;
			if (left.size() < right.size())
				return true;
			return false;
		}

		friend bool operator==(const Node &left, const Node &right) {
			if (left.ipnummer.compare(right.ipnummer)) {
				return true;
			}
			else {
				return false;
			}
		}

		void sortList() {
			sort(v.begin(), v.end());
		}

		void ipHasConnections(string ipnummer) {
			vector<Node>::iterator it = find(v.begin(), v.end(), ipnummer);
			cout << "Ipnummret har: " << it->antal << " anslutningar";
		}

		void printList() {
			for (vector<Node>::iterator it = v.begin(); it != v.end(); ++it) {
				cout << it->ipnummer << " " << it->antal << endl;
			}
		}

		void maxConnections() {
			priority_queue<data_pq> queue;
			for (auto &p : v) {
				data_pq d(p.ipnummer, p.antal);
				queue.push(d);
			}
			for (int i = 0; i < 10; i++) {
				cout << queue.top().ipnummer << ":" << queue.top().antal << endl;
				queue.pop();
			}
		}

	};
}