#include "../forward_list/forward_list.h"
#include <string>
#include "InterestTable.h"

int main() {
	InterestTable intresse;

	intresse.Add("training");
	intresse.Add("movies");
	intresse.Add("swimming");

	intresse.WriteToFile();

	system("pause");
	return 0;
}