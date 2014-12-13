#include <iostream>
#include <deque>
#include <string>

using namespace std;

//funktioner
bool palindrom(string);

int main() {
	string hej = "kanot";
	cout << palindrom(hej) << endl;

	system("pause");
	return 0;
}

bool palindrom(string s) {
	deque<char> text;
	int i = 0;

	for (i = 0; i < s.size(); i++) {
		text.push_back(s[i]);
	}

	for (i = 0; i < (s.size() / 2); i++) {
		if (text.back() != text.front()) {
			return false;
		}
		text.pop_front();
		text.pop_back();
	}
	return true;
}