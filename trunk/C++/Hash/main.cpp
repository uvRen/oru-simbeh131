#include <iostream>
#include <functional>
#include <string>

using namespace std;

int main() {

	hash<string> str, str2;

	cout << str("simon")%100 << endl;
	cout << str2("simon")%100 << endl;

	system("pause");
	return 0;
}