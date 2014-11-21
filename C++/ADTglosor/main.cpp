#include "GlosLista.h"

using namespace std;

int main() {
	GlosLista lista("Simon");
	Glosor<string> a("bil", "car"), b("hus", "house"), c("hund", "dog"), d;

	istringstream iss("(bil,car)");

	lista.addWord(a);
	lista.addWord(b);
	lista.addWord(c);

	cout << lista.List() << endl;
	lista.writeToFile();

	lista.readFromFile();
	cout << lista.List() << endl;


	system("pause");
	return 0;
}