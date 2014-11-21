#include "GlosLista.h"

using namespace std;

int main() {
	GlosLista lista("Simon");
	Glosor<string> a("bil", "car"), b("hus", "house"), c("hund", "dog"), d;

	istringstream iss("(skola,school)");

	/*lista.addWord(a);
	lista.addWord(b);
	lista.addWord(c);
	iss >> d;
	lista.addWord(d);

	cout << lista.List() << endl;
	lista.writeToFile();

	lista.readFromFile();
	cout << lista.List() << endl;*/

	lista.readFromFile();
	cout << lista.List() << endl << endl;

	lista.addWord();
	lista.readFromFile();
	cout << lista.List() << endl;


	system("pause");
	return 0;
}