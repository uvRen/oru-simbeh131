#include "circular_list.h"
#include "josephus.h"

using namespace std;

int main() {
	Betyg4::circular_list lista;
	Betyg41::josephus spel;

	spel.addPersons();

	spel.printPersons();

	system("pause");
	return 0;
}