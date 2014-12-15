#include <iostream>
#include <deque>
#include <string>
#include "statistics.h"

using namespace std;

//funktioner
//namespace Betyg3 {
//	bool palindrom(string s) {
//		deque<char> text;
//		int i = 0;
//
//		for (i = 0; i < s.size(); i++) {
//			text.push_back(s[i]);
//		}
//
//		for (i = 0; i < (s.size() / 2); i++) {
//			if (text.back() != text.front()) {
//				return false;
//			}
//			text.pop_front();
//			text.pop_back();
//		}
//		return true;
//	}
//
//	bool palindromRek(string s, int storlek) {
//		if (s[storlek - 1] != s[s.size() - 1 - (storlek - 1)]) {
//			return false;
//		}
//		if ((storlek - 1) == ((s.size() - 1) / 2)) {
//			return true;
//		}
//		cout << palindromRek(s, storlek - 1);
//	}
//
//	void main1_1() {
//		string hej = "kajak";
//		int a;
//		a = palindrom(hej);
//		if (a == 1) {
//			cout << hej << " = palindrom" << endl;
//		}
//		else {
//			cout << hej << " != palindrom" << endl;
//		}
//	}
//
//	void main1_2() {
//		string hej = "kajsak";
//		int a;
//		a = palindromRek(hej, hej.size());
//		if (a == 1) {
//			cout << hej << " = palindrom" << endl;
//		}
//		else {
//			cout << hej << " != palindrom" << endl;
//		}
//	}
//}


int main() {
	/*Betyg3::main1_1();
	Betyg3::main1_2();*/

	statistics lista;

	lista.ReadFromFile();
	lista.printArray();

	system("pause");
	return 0;
}
