#include "circular_list.h"
#include "josephus.h"

using namespace std;

int main() {
	Betyg4::circular_list lista;
	Betyg41::josephus spel;

	spel.addPersons();

	cout << spel.playGame() << " vann!" << endl;


	system("pause");
	return 0;
}