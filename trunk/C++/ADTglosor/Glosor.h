#include <iostream>
#include <ostream>

using namespace std;

template<class T>
class Glosor {
private:
	T word;
	T matchingWord;

public:
	Glosor() {
		word = "";
		matchingWord = "";
	}

	Glosor(T word, T matchingWord) {
		this->word = word;
		this->matchingWord = matchingWord;
	}

	friend ostream& operator<<(ostream &ut, const Glosor<T> &a) {
		ut << '(' << a.word << ',' << a.matchingWord << ')';
		return ut;
	}

	friend istream& operator>>(istream &in, Glosor<T> &a) {
		string s;
		getline(in, s, '(');
		getline(in, a.word, ',');
		getline(in, a.matchingWord, ')');

		return in;
	}
};