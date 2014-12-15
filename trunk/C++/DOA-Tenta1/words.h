#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class words {
private:
	map<string, int> ord;
	
public:
	words() {

	}

	string stringManipulation(string word) {
		string newWord = word;
		char c;
		int w;
		//gör alla tecken till små
		for (int i = 0; i < newWord.size(); i++) {
			newWord[i] = tolower(newWord[i]);
		}
		//tar bort alla icke alfabetiska tecken
		for (int i = 0; i < newWord.size(); i++) {
			c = newWord[i];
			w = (int)c;

			if (w < 97 || w > 122) {
				if (w != -10 && w != -27 && w != -28) {
					newWord.erase(i, 1);
					i--;
				}
			}
		}
		return newWord;
	}

	void ReadFromFile() {
		ifstream in;
		string row, word;
		int antal = 0;

		try {
			in.open("nils_holgersson.txt");
			if (!in.good()) {
				cout << "Gick ej att öppna filen!" << endl;
			}

			else {
				ord.clear();
				
				while (getline(in, row)) {
					istringstream iss(row);
					while (getline(iss, word, ' ')) {
						word = stringManipulation(word);
						if (ord[word] == 0) {
							ord[word] = 1;
						}
						else {
							ord[word]++;
						}
					}
				}
			}
		}

		catch (exception e) {

		}
	}

	pair<string, int> getMostFrekventWord() {
		int antal = 0;
		string word = "";
		typedef map<string, int>::iterator it_type;
		for (it_type it = ord.begin(); it != ord.end(); it++) {
			if (it->second > antal) {
				word = it->first;
			}
			antal = max(antal, it->second);
		}
		return pair<string, int>(word, antal);
	}

	void printMap() {
		typedef map<string, int>::iterator it_type;
		for (it_type it = ord.begin(); it != ord.end(); it++) {
			cout << '|' << it->first << "| -> " << it->second << endl;
		}
	}

	
};