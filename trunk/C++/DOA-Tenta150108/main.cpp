#include "circular_list.h"
#include "josephus.h"

using namespace std;

int main() {
	Betyg4::circular_list lista;
	Betyg41::josephus spel;

	spel.addPersons();

	cout << spel.playGame() << " vann!" << endl;

	/*lista.add("1");
	lista.add("2");
	lista.add("3");
	lista.add("4");
	lista.add("5");
	lista.add("6");

	int antal = 0;
	for (Betyg4::circular_list::iterator it = lista.begin(); antal < 20; ++it) {
		if (it != lista.begin()) {
			cout << *it << endl;
		}
		antal++;
	}*/

	system("pause");
	return 0;
}