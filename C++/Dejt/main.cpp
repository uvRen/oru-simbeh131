#include "../forward_list/forward_list.h"
#include <string>
#include "InterestTable.h"

int main() {
	InterestTable intresse;

	intresse.Add("training");
	intresse.Add("movies");
	intresse.Add("swimming");

	intresse.printList();

	intresse.WriteToFile();

	intresse.ReadFromFile();

	intresse.WriteToFile();

	system("pause");
	return 0;
}